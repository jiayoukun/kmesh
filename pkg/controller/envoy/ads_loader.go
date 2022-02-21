/*
 * Copyright (c) 2019 Huawei Technologies Co., Ltd.
 * MeshAccelerating is licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Author: LemmyHuang
 * Create: 2022-01-24
 */

package envoy

import (
	configClusterV3 "github.com/envoyproxy/go-control-plane/envoy/config/cluster/v3"
	configCoreV3 "github.com/envoyproxy/go-control-plane/envoy/config/core/v3"
	configEndpointV3 "github.com/envoyproxy/go-control-plane/envoy/config/endpoint/v3"
	configListenerV3 "github.com/envoyproxy/go-control-plane/envoy/config/listener/v3"
	configRouteV3 "github.com/envoyproxy/go-control-plane/envoy/config/route/v3"
	filtersNetworkHttp "github.com/envoyproxy/go-control-plane/envoy/extensions/filters/network/http_connection_manager/v3"
	filtersNetworkTcp "github.com/envoyproxy/go-control-plane/envoy/extensions/filters/network/tcp_proxy/v3"
	pkgWellknown "github.com/envoyproxy/go-control-plane/pkg/wellknown"
	"google.golang.org/protobuf/proto"
	"google.golang.org/protobuf/types/known/anypb"
	cluster_v2 "openeuler.io/mesh/api/v2/cluster"
	core_v2 "openeuler.io/mesh/api/v2/core"
	endpoint_v2 "openeuler.io/mesh/api/v2/endpoint"
	filter_v2 "openeuler.io/mesh/api/v2/filter"
	listener_v2 "openeuler.io/mesh/api/v2/listener"
	route_v2 "openeuler.io/mesh/api/v2/route"
	cache_v2 "openeuler.io/mesh/pkg/cache/v2"
	"openeuler.io/mesh/pkg/nets"
)

type adsLoader struct {
	listenerCache cache_v2.ApiListenerCache
	clusterCache  cache_v2.ApiClusterCache
	routeCache    cache_v2.ApiRouteConfigurationCache
}

func newAdsLoader() *adsLoader {
	return &adsLoader{
		listenerCache: cache_v2.NewApiListenerCache(),
		clusterCache:  cache_v2.NewApiClusterCache(),
		routeCache:    cache_v2.NewApiRouteConfigurationCache(),
	}
}

func (load *adsLoader) createApiClusterByCDS(status core_v2.ApiStatus, cluster *configClusterV3.Cluster) {
	apiCluster := &cluster_v2.Cluster{
		ApiStatus: status,
		Name: cluster.GetName(),
		ConnectTimeout: uint32(cluster.GetConnectTimeout().GetSeconds()),
		LbPolicy: cluster_v2.Cluster_LbPolicy(cluster.GetLbPolicy()),
		CircuitBreakers: newApiCircuitBreakers(cluster.GetCircuitBreakers()),
	}

	if cluster.GetType() != configClusterV3.Cluster_EDS {
		apiCluster.LoadAssignment = newApiClusterLoadAssignment(cluster.GetLoadAssignment())
	}

	load.clusterCache[apiCluster.GetName()] = apiCluster
}

func (load *adsLoader) createApiClusterByEDS(status core_v2.ApiStatus, loadAssignment *configEndpointV3.ClusterLoadAssignment) {
	apiCluster := load.clusterCache[loadAssignment.GetClusterName()]
	if apiCluster == nil {
		return
	}

	apiCluster.LoadAssignment = newApiClusterLoadAssignment(loadAssignment)
}

func newApiClusterLoadAssignment(loadAssignment *configEndpointV3.ClusterLoadAssignment) *endpoint_v2.ClusterLoadAssignment {
	apiLoadAssignment := &endpoint_v2.ClusterLoadAssignment{
		ClusterName: loadAssignment.GetClusterName(),
	}

	for _, localityLb := range loadAssignment.GetEndpoints() {
		apiLocalityLb := &endpoint_v2.LocalityLbEndpoints{
			LoadBalancingWeight: localityLb.GetLoadBalancingWeight().GetValue(),
			Priority: localityLb.GetPriority(),
			LbEndpoints: nil,
		}

		for _, endpoint := range localityLb.GetLbEndpoints() {
			apiEndpoint := &endpoint_v2.Endpoint{
				Address: newApiSocketAddress(endpoint.GetEndpoint().GetAddress()),
			}
			if apiEndpoint.GetAddress() == nil {
				continue
			}
			apiLocalityLb.LbEndpoints = append(apiLocalityLb.LbEndpoints, apiEndpoint)
		}

		apiLoadAssignment.Endpoints = append(apiLoadAssignment.Endpoints, apiLocalityLb)
	}

	return apiLoadAssignment
}

func newApiSocketAddress(address *configCoreV3.Address) *core_v2.SocketAddress {
	var addr *configCoreV3.SocketAddress

	switch address.GetAddress().(type) {
	case *configCoreV3.Address_SocketAddress:
		addr = address.GetSocketAddress()
	default:
		return nil
	}

	if !nets.GetConfig().IsEnabledProtocol(addr.GetProtocol().String()) {
		return nil
	}

	return &core_v2.SocketAddress{
		//Protocol: core_v2.SocketAddress_Protocol(addr.GetProtocol()),
		Port: nets.ConvertPortToLittleEndian(addr.GetPortValue()),
		Ipv4: nets.ConvertIpToUint32(addr.GetAddress()),
	}
}

func newApiCircuitBreakers(cb *configClusterV3.CircuitBreakers) *cluster_v2.CircuitBreakers {
	if cb == nil {
		return nil
	}

	thresholds := cb.GetThresholds()
	if len(thresholds) == 0 {
		return nil
	}

	return &cluster_v2.CircuitBreakers{
		Priority: core_v2.RoutingPriority(thresholds[0].GetPriority()),
		MaxConnections: thresholds[0].GetMaxConnections().GetValue(),
		MaxConnectionPools: thresholds[0].GetMaxConnectionPools().GetValue(),
		MaxRequests: thresholds[0].GetMaxRequests().GetValue(),
		MaxPendingRequests: thresholds[0].GetMaxPendingRequests().GetValue(),
		MaxRetries: thresholds[0].GetMaxRetries().GetValue(),
	}
}

func (load *adsLoader) createApiListenerByLDS(status core_v2.ApiStatus, listener *configListenerV3.Listener) {
	apiListener := &listener_v2.Listener{
		ApiStatus: status,
		Name: listener.GetName(),
		Address: newApiSocketAddress(listener.GetAddress()),
	}

	for _, filterChain := range listener.GetFilterChains() {
		apiFilterChain := &listener_v2.FilterChain{
			Name: filterChain.GetName(),
			FilterChainMatch: newApiFilterChainMatch(filterChain.GetFilterChainMatch()),
			Filters: nil,
		}

		for _, filter := range filterChain.GetFilters() {
			apiFilter := newApiFilter(filter)
			if apiFilter == nil {
				continue
			}
			apiFilterChain.Filters = append(apiFilterChain.Filters, apiFilter)
		}

		apiListener.FilterChains = append(apiListener.FilterChains, apiFilterChain)
	}

	load.listenerCache[apiListener.GetName()] = apiListener
}

func newApiFilterChainMatch(match *configListenerV3.FilterChainMatch) *listener_v2.FilterChainMatch {
	apiMatch := &listener_v2.FilterChainMatch{
		DestinationPort: match.GetDestinationPort().GetValue(),
		ApplicationProtocols: match.GetApplicationProtocols(),
	}

	// TODO
	apiMatch.PrefixRanges = nil
	return apiMatch
}

func newApiFilter(filter *configListenerV3.Filter) *listener_v2.Filter {
	var err error
	apiFilter := &listener_v2.Filter{
		Name: filter.GetName(),
	}

	switch filter.GetConfigType().(type) {
	case *configListenerV3.Filter_TypedConfig:
		switch filter.GetName() {
		case pkgWellknown.TCPProxy:
			cfgTcp := &filtersNetworkTcp.TcpProxy{}
			if err = anypb.UnmarshalTo(filter.GetTypedConfig(), cfgTcp, proto.UnmarshalOptions{}); err != nil {
				return nil
			}

			apiFilter.ConfigType = &listener_v2.Filter_TcpProxy{
				TcpProxy: &filter_v2.TcpProxy{
					Cluster: cfgTcp.GetCluster(),
				},
			}
		case pkgWellknown.HTTPConnectionManager:
			cfgHttp := &filtersNetworkHttp.HttpConnectionManager{}
			if err = anypb.UnmarshalTo(filter.GetTypedConfig(), cfgHttp, proto.UnmarshalOptions{}); err != nil {
				return nil
			}
			if cfgHttp.GetRds() == nil {
				return nil
			}

			apiFilter.ConfigType = &listener_v2.Filter_HttpConnectionManager{
				HttpConnectionManager: &filter_v2.HttpConnectionManager{
					RouteConfigName: cfgHttp.GetRds().GetRouteConfigName(),
				},
			}
		default:
		}
	case *configListenerV3.Filter_ConfigDiscovery:
	default:
	}

	if apiFilter.ConfigType == nil {
		return nil
	}
	return apiFilter
}

func (load *adsLoader) createApiRouteByRDS(status core_v2.ApiStatus, routeConfiguration *configRouteV3.RouteConfiguration) {
	apiRouteConfiguration := &route_v2.RouteConfiguration{
		ApiStatus: status,
		Name: routeConfiguration.Name,
	}

	for _, host := range routeConfiguration.GetVirtualHosts() {
		apiHost := &route_v2.VirtualHost{
			Name: host.GetName(),
			Domains: host.GetDomains(),
			Routes: nil,
		}

		for _, route := range host.GetRoutes() {
			apiRoute := newApiRoute(route)
			if apiRoute == nil {
				continue
			}
			apiHost.Routes = append(apiHost.Routes, apiRoute)
		}
		apiRouteConfiguration.VirtualHosts = append(apiRouteConfiguration.VirtualHosts, apiHost)
	}

	load.routeCache[apiRouteConfiguration.Name] = apiRouteConfiguration
}

func newApiRoute(route *configRouteV3.Route) *route_v2.Route {
	apiRoute := &route_v2.Route{
		Name: route.GetName(),
		Match: &route_v2.RouteMatch{
			Prefix: route.GetMatch().GetPrefix(),
		},
	}

	switch route.GetAction().(type) {
	case *configRouteV3.Route_Route:
		action := route.GetRoute()
		apiRoute.Route = &route_v2.RouteAction{
			Cluster: action.GetCluster(),
			Timeout: uint32(action.GetTimeout().GetSeconds()),
			RetryPolicy: &route_v2.RetryPolicy{
				NumRetries: action.GetRetryPolicy().GetNumRetries().GetValue(),
			},
		}
	case *configRouteV3.Route_FilterAction:
	case *configRouteV3.Route_Redirect:
	default:
	}

	if apiRoute.Route == nil {
		return nil
	}
	return apiRoute
}
