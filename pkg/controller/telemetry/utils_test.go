/*
 * Copyright The Kmesh Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package telemetry

import (
	"context"
	"testing"

	"github.com/prometheus/client_golang/prometheus"
)

func TestRegisterMetrics(t *testing.T) {
	registry := prometheus.NewRegistry()
	ctx, cancel := context.WithCancel(context.Background())
	go func() {
		for {
			select {
			case <-ctx.Done():
				return
			default:
				runPrometheusClient(registry)
			}
		}
	}()

	exportMetrics := []*prometheus.GaugeVec{
		tcpConnectionClosedInWorkload,
		tcpConnectionOpenedInWorkload,
		tcpReceivedBytesInWorkload,
		tcpSentBytesInWorkload,
		tcpConnectionClosedInService,
		tcpConnectionOpenedInService,
		tcpReceivedBytesInService,
		tcpSentBytesInService,
	}

	workloadLabels := map[string]string{
		"reporter":                       "destination",
		"source_workload":                "sleep",
		"source_canonical_service":       "sleep",
		"source_canonical_revision":      "latest",
		"source_workload_namespace":      "ambient-demo",
		"source_principal":               "spiffe://cluster.local/ns/ambient-demo/sa/sleep",
		"source_app":                     "sleep",
		"source_version":                 "latest",
		"source_cluster":                 "Kubernetes",
		"destination_pod_address":        "192.068.10.25",
		"destination_pod_namespace":      "ambient-demo",
		"destination_pod_name":           "tcp-echo",
		"destination_workload":           "tcp-echo",
		"destination_canonical_service":  "tcp-echo",
		"destination_canonical_revision": "v1",
		"destination_workload_namespace": "ambient-demo",
		"destination_principal":          "spiffe://cluster.local/ns/ambient-demo/sa/default",
		"destination_app":                "tcp-echo",
		"destination_version":            "v1",
		"destination_cluster":            "Kubernetes",
		"request_protocol":               "tcp",
		"response_flags":                 "-",
		"connection_security_policy":     "mutual_tls",
	}

	serviceLabels := map[string]string{
		"reporter":                       "destination",
		"source_workload":                "sleep",
		"source_canonical_service":       "sleep",
		"source_canonical_revision":      "latest",
		"source_workload_namespace":      "ambient-demo",
		"source_principal":               "spiffe://cluster.local/ns/ambient-demo/sa/sleep",
		"source_app":                     "sleep",
		"source_version":                 "latest",
		"source_cluster":                 "Kubernetes",
		"destination_service":            "sleep.ambient.svc.cluster.local",
		"destination_service_namespace":  "ambient-demo",
		"destination_service_name":       "tcp-echo",
		"destination_workload":           "tcp-echo",
		"destination_canonical_service":  "tcp-echo",
		"destination_canonical_revision": "v1",
		"destination_workload_namespace": "ambient-demo",
		"destination_principal":          "spiffe://cluster.local/ns/ambient-demo/sa/default",
		"destination_app":                "tcp-echo",
		"destination_version":            "v1",
		"destination_cluster":            "Kubernetes",
		"request_protocol":               "tcp",
		"response_flags":                 "-",
		"connection_security_policy":     "mutual_tls",
	}

	tcpConnectionClosedInWorkload.With(workloadLabels).Set(2)
	tcpConnectionOpenedInWorkload.With(workloadLabels).Set(4)
	tcpReceivedBytesInWorkload.With(workloadLabels).Set(12.64)
	tcpSentBytesInWorkload.With(workloadLabels).Set(11.45)

	tcpConnectionClosedInService.With(serviceLabels).Set(4)
	tcpReceivedBytesInService.With(serviceLabels).Set(8)
	tcpSentBytesInService.With(serviceLabels).Set(9)
	tcpConnectionOpenedInService.With(serviceLabels).Set(16.25)

	for _, metric := range exportMetrics {
		if err := prometheus.Register(metric); err != nil {
			t.Errorf("metric not register")
		}
	}
	cancel()
}
