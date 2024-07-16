/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: api/workloadapi/workload.proto */

#ifndef PROTOBUF_C_api_2fworkloadapi_2fworkload_2eproto__INCLUDED
#define PROTOBUF_C_api_2fworkloadapi_2fworkload_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Istio__Workload__Address Istio__Workload__Address;
typedef struct Istio__Workload__Service Istio__Workload__Service;
typedef struct Istio__Workload__LoadBalancing Istio__Workload__LoadBalancing;
typedef struct Istio__Workload__Workload Istio__Workload__Workload;
typedef struct Istio__Workload__Workload__ServicesEntry Istio__Workload__Workload__ServicesEntry;
typedef struct Istio__Workload__Locality Istio__Workload__Locality;
typedef struct Istio__Workload__PortList Istio__Workload__PortList;
typedef struct Istio__Workload__Port Istio__Workload__Port;
typedef struct Istio__Workload__ApplicationTunnel Istio__Workload__ApplicationTunnel;
typedef struct Istio__Workload__GatewayAddress Istio__Workload__GatewayAddress;
typedef struct Istio__Workload__NetworkAddress Istio__Workload__NetworkAddress;
typedef struct Istio__Workload__NamespacedHostname Istio__Workload__NamespacedHostname;


/* --- enums --- */

typedef enum _Istio__Workload__LoadBalancing__Scope {
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__UNSPECIFIED_SCOPE = 0,
  /*
   * Prefer traffic in the same region.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__REGION = 1,
  /*
   * Prefer traffic in the same zone.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__ZONE = 2,
  /*
   * Prefer traffic in the same subzone.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__SUBZONE = 3,
  /*
   * Prefer traffic on the same node.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__NODE = 4,
  /*
   * Prefer traffic in the same cluster.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__CLUSTER = 5,
  /*
   * Prefer traffic in the same network.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE__NETWORK = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__LOAD_BALANCING__SCOPE)
} Istio__Workload__LoadBalancing__Scope;
typedef enum _Istio__Workload__LoadBalancing__Mode {
  ISTIO__WORKLOAD__LOAD_BALANCING__MODE__UNSPECIFIED_MODE = 0,
  /*
   * In STRICT mode, only endpoints that meets all of the routing preferences will be considered.
   * This can be used, for instance, to keep traffic ONLY within the same cluster/node/region.
   * This should be used with caution, as it can result in all traffic being dropped if there is no matching endpoints,
   * even if there are endpoints outside of the preferences.
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__MODE__STRICT = 1,
  /*
   * In FAILOVER mode, endpoint selection will prefer endpoints that match all preferences, but failover to groups of endpoints
   * that match less (or, eventually, none) preferences.
   * For instance, with `[NETWORK, REGION, ZONE]`, we will send to:
   * 1. Endpoints matching `[NETWORK, REGION, ZONE]`
   * 2. Endpoints matching `[NETWORK, REGION]`
   * 3. Endpoints matching `[NETWORK]`
   * 4. Any endpoints
   */
  ISTIO__WORKLOAD__LOAD_BALANCING__MODE__FAILOVER = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__LOAD_BALANCING__MODE)
} Istio__Workload__LoadBalancing__Mode;
typedef enum _Istio__Workload__ApplicationTunnel__Protocol {
  /*
   * Bytes are copied from the inner stream without modification.
   */
  ISTIO__WORKLOAD__APPLICATION_TUNNEL__PROTOCOL__NONE = 0,
  /*
   * Prepend PROXY protocol headers before copying bytes
   * Standard PROXY source and destination information
   * is included, along with potential extra TLV headers:
   * 0xD0 - The SPIFFE identity of the source workload
   * 0xD1 - The FQDN or Hostname of the targeted Service
   */
  ISTIO__WORKLOAD__APPLICATION_TUNNEL__PROTOCOL__PROXY = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__APPLICATION_TUNNEL__PROTOCOL)
} Istio__Workload__ApplicationTunnel__Protocol;
typedef enum _Istio__Workload__WorkloadStatus {
  /*
   * Workload is healthy and ready to serve traffic.
   */
  ISTIO__WORKLOAD__WORKLOAD_STATUS__HEALTHY = 0,
  /*
   * Workload is unhealthy and NOT ready to serve traffic.
   */
  ISTIO__WORKLOAD__WORKLOAD_STATUS__UNHEALTHY = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__WORKLOAD_STATUS)
} Istio__Workload__WorkloadStatus;
typedef enum _Istio__Workload__WorkloadType {
  ISTIO__WORKLOAD__WORKLOAD_TYPE__DEPLOYMENT = 0,
  ISTIO__WORKLOAD__WORKLOAD_TYPE__CRONJOB = 1,
  ISTIO__WORKLOAD__WORKLOAD_TYPE__POD = 2,
  ISTIO__WORKLOAD__WORKLOAD_TYPE__JOB = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__WORKLOAD_TYPE)
} Istio__Workload__WorkloadType;
/*
 * TunnelProtocol indicates the tunneling protocol for requests.
 */
typedef enum _Istio__Workload__TunnelProtocol {
  /*
   * NONE means requests should be forwarded as-is, without tunneling.
   */
  ISTIO__WORKLOAD__TUNNEL_PROTOCOL__NONE = 0,
  /*
   * HBONE means requests should be tunneled over HTTP.
   * This does not dictate HTTP/1.1 vs HTTP/2; ALPN should be used for that purpose.
   */
  /*
   * Future options may include things like QUIC/HTTP3, etc.
   */
  ISTIO__WORKLOAD__TUNNEL_PROTOCOL__HBONE = 1
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__TUNNEL_PROTOCOL)
} Istio__Workload__TunnelProtocol;

/* --- messages --- */

typedef enum {
  ISTIO__WORKLOAD__ADDRESS__TYPE__NOT_SET = 0,
  ISTIO__WORKLOAD__ADDRESS__TYPE_WORKLOAD = 1,
  ISTIO__WORKLOAD__ADDRESS__TYPE_SERVICE = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__ADDRESS__TYPE__CASE)
} Istio__Workload__Address__TypeCase;

/*
 * Address represents a unique address.
 * Address joins two sub-resources, Workload and Service, to support querying by IP address.
 * Address is intended to be able to be looked up on-demand, allowing a client
 * to answer a question like "what is this IP address", similar to a reverse DNS lookup.
 * Each resource will have a mesh-wide unique opaque name, defined in the individual messages.
 * In addition, to support lookup by IP address, they will have *alias* names for each IP the resource represents.
 * There may be multiple aliases for the same resource (examples: service in multiple networks, or a dual-stack workload).
 * Aliases are keyed by network/IP address. Example: "default/1.2.3.4".
 * In some cases, we do not know the IP address of a Workload. For instance, we may simply know
 * that there is a workload behind a gateway, and rely on the gateway to handle the rest.
 * In this case, the key format will be "resource-uid". The resource can be a Pod, WorkloadEntry, etc.
 * These resources cannot be looked up on-demand.
 * In some cases, we do not know the IP address of a Service. These services cannot be used for matching
 * outbound traffic, as we only have L4 attributes to route based on. However,
 * they can be used for Gateways.
 * In this case, the key format will be "network/hostname".
 * These resources cannot be looked up on-demand.
 */
struct  Istio__Workload__Address
{
  ProtobufCMessage base;
  Istio__Workload__Address__TypeCase type_case;
  union {
    /*
     * Workload represents an individual workload.
     * This could be a single Pod, a VM instance, etc.
     */
    Istio__Workload__Workload *workload;
    /*
     * Service represents a service - a group of workloads that can be accessed together.
     */
    Istio__Workload__Service *service;
  };
};
#define ISTIO__WORKLOAD__ADDRESS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__address__descriptor) \
    , ISTIO__WORKLOAD__ADDRESS__TYPE__NOT_SET, {0} }


/*
 * Service represents a service - a group of workloads that can be accessed together.
 * The xds primary key is "namespace/hostname".
 * Secondary (alias) keys are the unique `network/IP` pairs that the service can be reached at.
 */
struct  Istio__Workload__Service
{
  ProtobufCMessage base;
  /*
   * Name represents the name for the service.
   * For Kubernetes, this is the Service name.
   */
  char *name;
  /*
   * Namespace represents the namespace for the service.
   */
  char *namespace_;
  /*
   * Hostname represents the FQDN of the service.
   * For Kubernetes, this would be <name>.<namespace>.svc.<cluster domain>.
   * TODO: support this field
   */
  char *hostname;
  /*
   * Address represents the addresses the service can be reached at.
   * There may be multiple addresses for a single service if it resides in multiple networks,
   * multiple clusters, and/or if it's dual stack (TODO: support dual stack).
   * For a headless kubernetes service, this list will be empty.
   */
  size_t n_addresses;
  Istio__Workload__NetworkAddress **addresses;
  /*
   * Ports for the service.
   * The target_port may be overridden on a per-workload basis.
   */
  size_t n_ports;
  Istio__Workload__Port **ports;
  /*
   * Optional; if set, the SAN to verify for TLS connections.
   * Typically, this is not set and per-workload identity is used to verify
   * TODO: support this field
   */
  size_t n_subject_alt_names;
  char **subject_alt_names;
  /*
   * Waypoint is the waypoint proxy for this service. When set, all incoming requests must go
   * through the waypoint.
   */
  Istio__Workload__GatewayAddress *waypoint;
  /*
   * Load balancing policy for selecting endpoints.
   * Note: this applies only to connecting directly to the workload; when waypoints are used, the waypoint's load_balancing
   * configuration is used.
   */
  Istio__Workload__LoadBalancing *load_balancing;
};
#define ISTIO__WORKLOAD__SERVICE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__service__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL, 0,NULL, 0,NULL, NULL, NULL }


struct  Istio__Workload__LoadBalancing
{
  ProtobufCMessage base;
  /*
   * routing_preference defines what scopes we want to keep traffic within.
   * The `mode` determines how these routing preferences are handled
   */
  size_t n_routing_preference;
  Istio__Workload__LoadBalancing__Scope *routing_preference;
  /*
   * mode defines how we should handle the routing preferences.
   */
  Istio__Workload__LoadBalancing__Mode mode;
};
#define ISTIO__WORKLOAD__LOAD_BALANCING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__load_balancing__descriptor) \
    , 0,NULL, ISTIO__WORKLOAD__LOAD_BALANCING__MODE__UNSPECIFIED_MODE }


struct  Istio__Workload__Workload__ServicesEntry
{
  ProtobufCMessage base;
  char *key;
  Istio__Workload__PortList *value;
};
#define ISTIO__WORKLOAD__WORKLOAD__SERVICES_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__workload__services_entry__descriptor) \
    , (char *)protobuf_c_empty_string, NULL }


/*
 * Workload represents a workload - an endpoint (or collection behind a hostname).
 * The xds primary key is "uid" as defined on the workload below.
 * Secondary (alias) keys are the unique `network/IP` pairs that the workload can be reached at.
 */
struct  Istio__Workload__Workload
{
  ProtobufCMessage base;
  /*
   * UID represents a globally unique opaque identifier for this workload.
   * For k8s resources, it is recommended to use the more readable format:
   * cluster/group/kind/namespace/name/section-name
   * As an example, a ServiceEntry with two WorkloadEntries inlined could become
   * two Workloads with the following UIDs:
   * - cluster1/networking.istio.io/v1alpha3/ServiceEntry/default/external-svc/endpoint1
   * - cluster1/networking.istio.io/v1alpha3/ServiceEntry/default/external-svc/endpoint2
   * For VMs and other workloads other formats are also supported; for example,
   * a single UID string: "0ae5c03d-5fb3-4eb9-9de8-2bd4b51606ba"
   */
  char *uid;
  /*
   * Name represents the name for the workload.
   * For Kubernetes, this is the pod name.
   * This is just for debugging and may be elided as an optimization.
   */
  char *name;
  /*
   * Namespace represents the namespace for the workload.
   * This is just for debugging and may be elided as an optimization.
   */
  char *namespace_;
  /*
   * Address represents the IPv4/IPv6 address for the workload.
   * This should be globally unique.
   * This should not have a port number.
   * Each workload must have at least either an address or hostname; not both.
   */
  size_t n_addresses;
  ProtobufCBinaryData *addresses;
  /*
   * The hostname for the workload to be resolved by the ztunnel.
   * DNS queries are sent on-demand by default.
   * If the resolved DNS query has several endpoints, the request will be forwarded
   * to the first response.
   * At a minimum, each workload must have either an address or hostname. For example,
   * a workload that backs a Kubernetes service will typically have only endpoints. A
   * workload that backs a headless Kubernetes service, however, will have both
   * addresses as well as a hostname used for direct access to the headless endpoint.
   * TODO: support this field
   */
  char *hostname;
  /*
   * Network represents the network this workload is on. This may be elided for the default network.
   * A (network,address) pair makeup a unique key for a workload *at a point in time*.
   */
  char *network;
  /*
   * Protocol that should be used to connect to this workload.
   */
  Istio__Workload__TunnelProtocol tunnel_protocol;
  /*
   * The SPIFFE identity of the workload. The identity is joined to form spiffe://<trust_domain>/ns/<namespace>/sa/<service_account>.
   * TrustDomain of the workload. May be elided if this is the mesh wide default (typically cluster.local)
   */
  char *trust_domain;
  /*
   * ServiceAccount of the workload. May be elided if this is "default"
   */
  char *service_account;
  /*
   * If present, the waypoint proxy for this workload.
   * All incoming requests must go through the waypoint.
   */
  Istio__Workload__GatewayAddress *waypoint;
  /*
   * If present, East West network gateway this workload can be reached through.
   * Requests from remote networks should traverse this gateway.
   */
  Istio__Workload__GatewayAddress *network_gateway;
  /*
   * Name of the node the workload runs on
   */
  char *node;
  /*
   * CanonicalName for the workload. Used for telemetry.
   */
  char *canonical_name;
  /*
   * CanonicalRevision for the workload. Used for telemetry.
   */
  char *canonical_revision;
  /*
   * WorkloadType represents the type of the workload. Used for telemetry.
   */
  Istio__Workload__WorkloadType workload_type;
  /*
   * WorkloadName represents the name for the workload (of type WorkloadType). Used for telemetry.
   */
  char *workload_name;
  /*
   * If set, this indicates a workload expects to directly receive tunnel traffic.
   * In ztunnel, this means:
   * * Requests *from* this workload do not need to be tunneled if they already are tunneled by the tunnel_protocol.
   * * Requests *to* this workload, via the tunnel_protocol, do not need to be de-tunneled.
   */
  protobuf_c_boolean native_tunnel;
  /*
   * If an application, such as a sandwiched waypoint proxy, supports directly
   * receiving information from zTunnel they can set application_protocol.
   */
  Istio__Workload__ApplicationTunnel *application_tunnel;
  /*
   * The services for which this workload is an endpoint.
   * The key is the NamespacedHostname string of the format namespace/hostname.
   */
  size_t n_services;
  Istio__Workload__Workload__ServicesEntry **services;
  /*
   * A list of authorization policies applicable to this workload.
   * NOTE: this *only* includes Selector based policies. Namespace and global polices
   * are returned out of band.
   * Authorization policies are only valid for workloads with `addresses` rather than `hostname`.
   */
  size_t n_authorization_policies;
  char **authorization_policies;
  Istio__Workload__WorkloadStatus status;
  /*
   * The cluster ID that the workload instance belongs to
   */
  char *cluster_id;
  /*
   * The Locality defines information about where a workload is geographically deployed
   */
  Istio__Workload__Locality *locality;
};
#define ISTIO__WORKLOAD__WORKLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__workload__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, ISTIO__WORKLOAD__TUNNEL_PROTOCOL__NONE, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, NULL, NULL, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, ISTIO__WORKLOAD__WORKLOAD_TYPE__DEPLOYMENT, (char *)protobuf_c_empty_string, 0, NULL, 0,NULL, 0,NULL, ISTIO__WORKLOAD__WORKLOAD_STATUS__HEALTHY, (char *)protobuf_c_empty_string, NULL }


struct  Istio__Workload__Locality
{
  ProtobufCMessage base;
  char *region;
  char *zone;
  char *subzone;
};
#define ISTIO__WORKLOAD__LOCALITY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__locality__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/*
 * PorList represents the ports for a service
 */
struct  Istio__Workload__PortList
{
  ProtobufCMessage base;
  size_t n_ports;
  Istio__Workload__Port **ports;
};
#define ISTIO__WORKLOAD__PORT_LIST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__port_list__descriptor) \
    , 0,NULL }


struct  Istio__Workload__Port
{
  ProtobufCMessage base;
  /*
   * Port the service is reached at (frontend).
   */
  uint32_t service_port;
  /*
   * Port the service forwards to (backend).
   */
  uint32_t target_port;
};
#define ISTIO__WORKLOAD__PORT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__port__descriptor) \
    , 0, 0 }


/*
 * ApplicationProtocol specifies a workload  (application or gateway) can
 * consume tunnel information.
 */
struct  Istio__Workload__ApplicationTunnel
{
  ProtobufCMessage base;
  /*
   * A target natively handles this type of traffic.
   */
  Istio__Workload__ApplicationTunnel__Protocol protocol;
  /*
   * optional: if set, traffic should be sent to this port after the last zTunnel hop
   */
  uint32_t port;
};
#define ISTIO__WORKLOAD__APPLICATION_TUNNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__application_tunnel__descriptor) \
    , ISTIO__WORKLOAD__APPLICATION_TUNNEL__PROTOCOL__NONE, 0 }


typedef enum {
  ISTIO__WORKLOAD__GATEWAY_ADDRESS__DESTINATION__NOT_SET = 0,
  ISTIO__WORKLOAD__GATEWAY_ADDRESS__DESTINATION_HOSTNAME = 1,
  ISTIO__WORKLOAD__GATEWAY_ADDRESS__DESTINATION_ADDRESS = 2
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ISTIO__WORKLOAD__GATEWAY_ADDRESS__DESTINATION__CASE)
} Istio__Workload__GatewayAddress__DestinationCase;

/*
 * GatewayAddress represents the address of a gateway
 */
struct  Istio__Workload__GatewayAddress
{
  ProtobufCMessage base;
  /*
   * port to reach the gateway at for mTLS HBONE connections
   */
  uint32_t hbone_mtls_port;
  /*
   * port to reach the gateway at for single tls HBONE connections
   * used for sending unauthenticated traffic originating outside the mesh to a waypoint-enabled destination
   * A value of 0 = unset
   */
  uint32_t hbone_single_tls_port;
  Istio__Workload__GatewayAddress__DestinationCase destination_case;
  union {
    /*
     * TODO: add support for hostname lookup
     */
    Istio__Workload__NamespacedHostname *hostname;
    Istio__Workload__NetworkAddress *address;
  };
};
#define ISTIO__WORKLOAD__GATEWAY_ADDRESS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__gateway_address__descriptor) \
    , 0, 0, ISTIO__WORKLOAD__GATEWAY_ADDRESS__DESTINATION__NOT_SET, {0} }


/*
 * NetworkAddress represents an address bound to a specific network.
 */
struct  Istio__Workload__NetworkAddress
{
  ProtobufCMessage base;
  /*
   * Network represents the network this address is on.
   */
  char *network;
  /*
   * Address presents the IP (v4 or v6).
   */
  ProtobufCBinaryData address;
};
#define ISTIO__WORKLOAD__NETWORK_ADDRESS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__network_address__descriptor) \
    , (char *)protobuf_c_empty_string, {0,NULL} }


/*
 * NamespacedHostname represents a service bound to a specific namespace.
 */
struct  Istio__Workload__NamespacedHostname
{
  ProtobufCMessage base;
  /*
   * The namespace the service is in.
   */
  char *namespace_;
  /*
   * hostname (ex: gateway.example.com)
   */
  char *hostname;
};
#define ISTIO__WORKLOAD__NAMESPACED_HOSTNAME__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&istio__workload__namespaced_hostname__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/* Istio__Workload__Address methods */
void   istio__workload__address__init
                     (Istio__Workload__Address         *message);
size_t istio__workload__address__get_packed_size
                     (const Istio__Workload__Address   *message);
size_t istio__workload__address__pack
                     (const Istio__Workload__Address   *message,
                      uint8_t             *out);
size_t istio__workload__address__pack_to_buffer
                     (const Istio__Workload__Address   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__Address *
       istio__workload__address__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__address__free_unpacked
                     (Istio__Workload__Address *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__Service methods */
void   istio__workload__service__init
                     (Istio__Workload__Service         *message);
size_t istio__workload__service__get_packed_size
                     (const Istio__Workload__Service   *message);
size_t istio__workload__service__pack
                     (const Istio__Workload__Service   *message,
                      uint8_t             *out);
size_t istio__workload__service__pack_to_buffer
                     (const Istio__Workload__Service   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__Service *
       istio__workload__service__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__service__free_unpacked
                     (Istio__Workload__Service *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__LoadBalancing methods */
void   istio__workload__load_balancing__init
                     (Istio__Workload__LoadBalancing         *message);
size_t istio__workload__load_balancing__get_packed_size
                     (const Istio__Workload__LoadBalancing   *message);
size_t istio__workload__load_balancing__pack
                     (const Istio__Workload__LoadBalancing   *message,
                      uint8_t             *out);
size_t istio__workload__load_balancing__pack_to_buffer
                     (const Istio__Workload__LoadBalancing   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__LoadBalancing *
       istio__workload__load_balancing__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__load_balancing__free_unpacked
                     (Istio__Workload__LoadBalancing *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__Workload__ServicesEntry methods */
void   istio__workload__workload__services_entry__init
                     (Istio__Workload__Workload__ServicesEntry         *message);
/* Istio__Workload__Workload methods */
void   istio__workload__workload__init
                     (Istio__Workload__Workload         *message);
size_t istio__workload__workload__get_packed_size
                     (const Istio__Workload__Workload   *message);
size_t istio__workload__workload__pack
                     (const Istio__Workload__Workload   *message,
                      uint8_t             *out);
size_t istio__workload__workload__pack_to_buffer
                     (const Istio__Workload__Workload   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__Workload *
       istio__workload__workload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__workload__free_unpacked
                     (Istio__Workload__Workload *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__Locality methods */
void   istio__workload__locality__init
                     (Istio__Workload__Locality         *message);
size_t istio__workload__locality__get_packed_size
                     (const Istio__Workload__Locality   *message);
size_t istio__workload__locality__pack
                     (const Istio__Workload__Locality   *message,
                      uint8_t             *out);
size_t istio__workload__locality__pack_to_buffer
                     (const Istio__Workload__Locality   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__Locality *
       istio__workload__locality__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__locality__free_unpacked
                     (Istio__Workload__Locality *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__PortList methods */
void   istio__workload__port_list__init
                     (Istio__Workload__PortList         *message);
size_t istio__workload__port_list__get_packed_size
                     (const Istio__Workload__PortList   *message);
size_t istio__workload__port_list__pack
                     (const Istio__Workload__PortList   *message,
                      uint8_t             *out);
size_t istio__workload__port_list__pack_to_buffer
                     (const Istio__Workload__PortList   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__PortList *
       istio__workload__port_list__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__port_list__free_unpacked
                     (Istio__Workload__PortList *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__Port methods */
void   istio__workload__port__init
                     (Istio__Workload__Port         *message);
size_t istio__workload__port__get_packed_size
                     (const Istio__Workload__Port   *message);
size_t istio__workload__port__pack
                     (const Istio__Workload__Port   *message,
                      uint8_t             *out);
size_t istio__workload__port__pack_to_buffer
                     (const Istio__Workload__Port   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__Port *
       istio__workload__port__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__port__free_unpacked
                     (Istio__Workload__Port *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__ApplicationTunnel methods */
void   istio__workload__application_tunnel__init
                     (Istio__Workload__ApplicationTunnel         *message);
size_t istio__workload__application_tunnel__get_packed_size
                     (const Istio__Workload__ApplicationTunnel   *message);
size_t istio__workload__application_tunnel__pack
                     (const Istio__Workload__ApplicationTunnel   *message,
                      uint8_t             *out);
size_t istio__workload__application_tunnel__pack_to_buffer
                     (const Istio__Workload__ApplicationTunnel   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__ApplicationTunnel *
       istio__workload__application_tunnel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__application_tunnel__free_unpacked
                     (Istio__Workload__ApplicationTunnel *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__GatewayAddress methods */
void   istio__workload__gateway_address__init
                     (Istio__Workload__GatewayAddress         *message);
size_t istio__workload__gateway_address__get_packed_size
                     (const Istio__Workload__GatewayAddress   *message);
size_t istio__workload__gateway_address__pack
                     (const Istio__Workload__GatewayAddress   *message,
                      uint8_t             *out);
size_t istio__workload__gateway_address__pack_to_buffer
                     (const Istio__Workload__GatewayAddress   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__GatewayAddress *
       istio__workload__gateway_address__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__gateway_address__free_unpacked
                     (Istio__Workload__GatewayAddress *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__NetworkAddress methods */
void   istio__workload__network_address__init
                     (Istio__Workload__NetworkAddress         *message);
size_t istio__workload__network_address__get_packed_size
                     (const Istio__Workload__NetworkAddress   *message);
size_t istio__workload__network_address__pack
                     (const Istio__Workload__NetworkAddress   *message,
                      uint8_t             *out);
size_t istio__workload__network_address__pack_to_buffer
                     (const Istio__Workload__NetworkAddress   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__NetworkAddress *
       istio__workload__network_address__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__network_address__free_unpacked
                     (Istio__Workload__NetworkAddress *message,
                      ProtobufCAllocator *allocator);
/* Istio__Workload__NamespacedHostname methods */
void   istio__workload__namespaced_hostname__init
                     (Istio__Workload__NamespacedHostname         *message);
size_t istio__workload__namespaced_hostname__get_packed_size
                     (const Istio__Workload__NamespacedHostname   *message);
size_t istio__workload__namespaced_hostname__pack
                     (const Istio__Workload__NamespacedHostname   *message,
                      uint8_t             *out);
size_t istio__workload__namespaced_hostname__pack_to_buffer
                     (const Istio__Workload__NamespacedHostname   *message,
                      ProtobufCBuffer     *buffer);
Istio__Workload__NamespacedHostname *
       istio__workload__namespaced_hostname__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   istio__workload__namespaced_hostname__free_unpacked
                     (Istio__Workload__NamespacedHostname *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Istio__Workload__Address_Closure)
                 (const Istio__Workload__Address *message,
                  void *closure_data);
typedef void (*Istio__Workload__Service_Closure)
                 (const Istio__Workload__Service *message,
                  void *closure_data);
typedef void (*Istio__Workload__LoadBalancing_Closure)
                 (const Istio__Workload__LoadBalancing *message,
                  void *closure_data);
typedef void (*Istio__Workload__Workload__ServicesEntry_Closure)
                 (const Istio__Workload__Workload__ServicesEntry *message,
                  void *closure_data);
typedef void (*Istio__Workload__Workload_Closure)
                 (const Istio__Workload__Workload *message,
                  void *closure_data);
typedef void (*Istio__Workload__Locality_Closure)
                 (const Istio__Workload__Locality *message,
                  void *closure_data);
typedef void (*Istio__Workload__PortList_Closure)
                 (const Istio__Workload__PortList *message,
                  void *closure_data);
typedef void (*Istio__Workload__Port_Closure)
                 (const Istio__Workload__Port *message,
                  void *closure_data);
typedef void (*Istio__Workload__ApplicationTunnel_Closure)
                 (const Istio__Workload__ApplicationTunnel *message,
                  void *closure_data);
typedef void (*Istio__Workload__GatewayAddress_Closure)
                 (const Istio__Workload__GatewayAddress *message,
                  void *closure_data);
typedef void (*Istio__Workload__NetworkAddress_Closure)
                 (const Istio__Workload__NetworkAddress *message,
                  void *closure_data);
typedef void (*Istio__Workload__NamespacedHostname_Closure)
                 (const Istio__Workload__NamespacedHostname *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    istio__workload__workload_status__descriptor;
extern const ProtobufCEnumDescriptor    istio__workload__workload_type__descriptor;
extern const ProtobufCEnumDescriptor    istio__workload__tunnel_protocol__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__address__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__service__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__load_balancing__descriptor;
extern const ProtobufCEnumDescriptor    istio__workload__load_balancing__scope__descriptor;
extern const ProtobufCEnumDescriptor    istio__workload__load_balancing__mode__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__workload__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__workload__services_entry__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__locality__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__port_list__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__port__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__application_tunnel__descriptor;
extern const ProtobufCEnumDescriptor    istio__workload__application_tunnel__protocol__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__gateway_address__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__network_address__descriptor;
extern const ProtobufCMessageDescriptor istio__workload__namespaced_hostname__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_api_2fworkloadapi_2fworkload_2eproto__INCLUDED */
