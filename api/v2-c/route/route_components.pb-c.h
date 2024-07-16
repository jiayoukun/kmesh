/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: api/route/route_components.proto */

#ifndef PROTOBUF_C_api_2froute_2froute_5fcomponents_2eproto__INCLUDED
#define PROTOBUF_C_api_2froute_2froute_5fcomponents_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Route__VirtualHost Route__VirtualHost;
typedef struct Route__Route Route__Route;
typedef struct Route__RouteMatch Route__RouteMatch;
typedef struct Route__RouteAction Route__RouteAction;
typedef struct Route__RetryPolicy Route__RetryPolicy;
typedef struct Route__WeightedCluster Route__WeightedCluster;
typedef struct Route__ClusterWeight Route__ClusterWeight;
typedef struct Route__HeaderMatcher Route__HeaderMatcher;


/* --- enums --- */


/* --- messages --- */

struct  Route__VirtualHost
{
  ProtobufCMessage base;
  char *name;
  size_t n_domains;
  char **domains;
  size_t n_routes;
  Route__Route **routes;
};
#define ROUTE__VIRTUAL_HOST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__virtual_host__descriptor) \
    , (char *)protobuf_c_empty_string, 0,NULL, 0,NULL }


struct  Route__Route
{
  ProtobufCMessage base;
  char *name;
  Route__RouteMatch *match;
  Route__RouteAction *route;
};
#define ROUTE__ROUTE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__route__descriptor) \
    , (char *)protobuf_c_empty_string, NULL, NULL }


struct  Route__RouteMatch
{
  ProtobufCMessage base;
  char *prefix;
  protobuf_c_boolean case_sensitive;
  size_t n_headers;
  Route__HeaderMatcher **headers;
};
#define ROUTE__ROUTE_MATCH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__route_match__descriptor) \
    , (char *)protobuf_c_empty_string, 0, 0,NULL }


typedef enum {
  ROUTE__ROUTE_ACTION__CLUSTER_SPECIFIER__NOT_SET = 0,
  ROUTE__ROUTE_ACTION__CLUSTER_SPECIFIER_CLUSTER = 1,
  ROUTE__ROUTE_ACTION__CLUSTER_SPECIFIER_WEIGHTED_CLUSTERS = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ROUTE__ROUTE_ACTION__CLUSTER_SPECIFIER__CASE)
} Route__RouteAction__ClusterSpecifierCase;

struct  Route__RouteAction
{
  ProtobufCMessage base;
  /*
   * the matched prefix (or path) should be swapped with this value.
   */
  char *prefix_rewrite;
  uint32_t timeout;
  Route__RetryPolicy *retry_policy;
  Route__RouteAction__ClusterSpecifierCase cluster_specifier_case;
  union {
    /*
     * Indicates the upstream cluster to which the request should be routed to.
     */
    char *cluster;
    /*
     * Multiple upstream clusters can be specified for a given route. The
     * request is routed to one of the upstream clusters based on weights
     * assigned to each cluster.
     */
    Route__WeightedCluster *weighted_clusters;
  };
};
#define ROUTE__ROUTE_ACTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__route_action__descriptor) \
    , (char *)protobuf_c_empty_string, 0, NULL, ROUTE__ROUTE_ACTION__CLUSTER_SPECIFIER__NOT_SET, {0} }


struct  Route__RetryPolicy
{
  ProtobufCMessage base;
  /*
   *RetryPriority retry_priority = 4;
   */
  uint32_t num_retries;
};
#define ROUTE__RETRY_POLICY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__retry_policy__descriptor) \
    , 0 }


struct  Route__WeightedCluster
{
  ProtobufCMessage base;
  size_t n_clusters;
  Route__ClusterWeight **clusters;
};
#define ROUTE__WEIGHTED_CLUSTER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__weighted_cluster__descriptor) \
    , 0,NULL }


struct  Route__ClusterWeight
{
  ProtobufCMessage base;
  char *name;
  uint32_t weight;
};
#define ROUTE__CLUSTER_WEIGHT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__cluster_weight__descriptor) \
    , (char *)protobuf_c_empty_string, 0 }


typedef enum {
  ROUTE__HEADER_MATCHER__HEADER_MATCH_SPECIFIER__NOT_SET = 0,
  ROUTE__HEADER_MATCHER__HEADER_MATCH_SPECIFIER_EXACT_MATCH = 4,
  ROUTE__HEADER_MATCHER__HEADER_MATCH_SPECIFIER_PREFIX_MATCH = 9
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(ROUTE__HEADER_MATCHER__HEADER_MATCH_SPECIFIER__CASE)
} Route__HeaderMatcher__HeaderMatchSpecifierCase;

struct  Route__HeaderMatcher
{
  ProtobufCMessage base;
  /*
   * Specifies the name of the header in the request.
   */
  char *name;
  Route__HeaderMatcher__HeaderMatchSpecifierCase header_match_specifier_case;
  union {
    /*
     * If specified, header match will be performed based on the value of the header.
     */
    char *exact_match;
    /*
     * If specified, header match will be performed based on the prefix of the header value.
     */
    char *prefix_match;
  };
};
#define ROUTE__HEADER_MATCHER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&route__header_matcher__descriptor) \
    , (char *)protobuf_c_empty_string, ROUTE__HEADER_MATCHER__HEADER_MATCH_SPECIFIER__NOT_SET, {0} }


/* Route__VirtualHost methods */
void   route__virtual_host__init
                     (Route__VirtualHost         *message);
size_t route__virtual_host__get_packed_size
                     (const Route__VirtualHost   *message);
size_t route__virtual_host__pack
                     (const Route__VirtualHost   *message,
                      uint8_t             *out);
size_t route__virtual_host__pack_to_buffer
                     (const Route__VirtualHost   *message,
                      ProtobufCBuffer     *buffer);
Route__VirtualHost *
       route__virtual_host__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__virtual_host__free_unpacked
                     (Route__VirtualHost *message,
                      ProtobufCAllocator *allocator);
/* Route__Route methods */
void   route__route__init
                     (Route__Route         *message);
size_t route__route__get_packed_size
                     (const Route__Route   *message);
size_t route__route__pack
                     (const Route__Route   *message,
                      uint8_t             *out);
size_t route__route__pack_to_buffer
                     (const Route__Route   *message,
                      ProtobufCBuffer     *buffer);
Route__Route *
       route__route__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__route__free_unpacked
                     (Route__Route *message,
                      ProtobufCAllocator *allocator);
/* Route__RouteMatch methods */
void   route__route_match__init
                     (Route__RouteMatch         *message);
size_t route__route_match__get_packed_size
                     (const Route__RouteMatch   *message);
size_t route__route_match__pack
                     (const Route__RouteMatch   *message,
                      uint8_t             *out);
size_t route__route_match__pack_to_buffer
                     (const Route__RouteMatch   *message,
                      ProtobufCBuffer     *buffer);
Route__RouteMatch *
       route__route_match__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__route_match__free_unpacked
                     (Route__RouteMatch *message,
                      ProtobufCAllocator *allocator);
/* Route__RouteAction methods */
void   route__route_action__init
                     (Route__RouteAction         *message);
size_t route__route_action__get_packed_size
                     (const Route__RouteAction   *message);
size_t route__route_action__pack
                     (const Route__RouteAction   *message,
                      uint8_t             *out);
size_t route__route_action__pack_to_buffer
                     (const Route__RouteAction   *message,
                      ProtobufCBuffer     *buffer);
Route__RouteAction *
       route__route_action__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__route_action__free_unpacked
                     (Route__RouteAction *message,
                      ProtobufCAllocator *allocator);
/* Route__RetryPolicy methods */
void   route__retry_policy__init
                     (Route__RetryPolicy         *message);
size_t route__retry_policy__get_packed_size
                     (const Route__RetryPolicy   *message);
size_t route__retry_policy__pack
                     (const Route__RetryPolicy   *message,
                      uint8_t             *out);
size_t route__retry_policy__pack_to_buffer
                     (const Route__RetryPolicy   *message,
                      ProtobufCBuffer     *buffer);
Route__RetryPolicy *
       route__retry_policy__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__retry_policy__free_unpacked
                     (Route__RetryPolicy *message,
                      ProtobufCAllocator *allocator);
/* Route__WeightedCluster methods */
void   route__weighted_cluster__init
                     (Route__WeightedCluster         *message);
size_t route__weighted_cluster__get_packed_size
                     (const Route__WeightedCluster   *message);
size_t route__weighted_cluster__pack
                     (const Route__WeightedCluster   *message,
                      uint8_t             *out);
size_t route__weighted_cluster__pack_to_buffer
                     (const Route__WeightedCluster   *message,
                      ProtobufCBuffer     *buffer);
Route__WeightedCluster *
       route__weighted_cluster__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__weighted_cluster__free_unpacked
                     (Route__WeightedCluster *message,
                      ProtobufCAllocator *allocator);
/* Route__ClusterWeight methods */
void   route__cluster_weight__init
                     (Route__ClusterWeight         *message);
size_t route__cluster_weight__get_packed_size
                     (const Route__ClusterWeight   *message);
size_t route__cluster_weight__pack
                     (const Route__ClusterWeight   *message,
                      uint8_t             *out);
size_t route__cluster_weight__pack_to_buffer
                     (const Route__ClusterWeight   *message,
                      ProtobufCBuffer     *buffer);
Route__ClusterWeight *
       route__cluster_weight__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__cluster_weight__free_unpacked
                     (Route__ClusterWeight *message,
                      ProtobufCAllocator *allocator);
/* Route__HeaderMatcher methods */
void   route__header_matcher__init
                     (Route__HeaderMatcher         *message);
size_t route__header_matcher__get_packed_size
                     (const Route__HeaderMatcher   *message);
size_t route__header_matcher__pack
                     (const Route__HeaderMatcher   *message,
                      uint8_t             *out);
size_t route__header_matcher__pack_to_buffer
                     (const Route__HeaderMatcher   *message,
                      ProtobufCBuffer     *buffer);
Route__HeaderMatcher *
       route__header_matcher__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   route__header_matcher__free_unpacked
                     (Route__HeaderMatcher *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Route__VirtualHost_Closure)
                 (const Route__VirtualHost *message,
                  void *closure_data);
typedef void (*Route__Route_Closure)
                 (const Route__Route *message,
                  void *closure_data);
typedef void (*Route__RouteMatch_Closure)
                 (const Route__RouteMatch *message,
                  void *closure_data);
typedef void (*Route__RouteAction_Closure)
                 (const Route__RouteAction *message,
                  void *closure_data);
typedef void (*Route__RetryPolicy_Closure)
                 (const Route__RetryPolicy *message,
                  void *closure_data);
typedef void (*Route__WeightedCluster_Closure)
                 (const Route__WeightedCluster *message,
                  void *closure_data);
typedef void (*Route__ClusterWeight_Closure)
                 (const Route__ClusterWeight *message,
                  void *closure_data);
typedef void (*Route__HeaderMatcher_Closure)
                 (const Route__HeaderMatcher *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor route__virtual_host__descriptor;
extern const ProtobufCMessageDescriptor route__route__descriptor;
extern const ProtobufCMessageDescriptor route__route_match__descriptor;
extern const ProtobufCMessageDescriptor route__route_action__descriptor;
extern const ProtobufCMessageDescriptor route__retry_policy__descriptor;
extern const ProtobufCMessageDescriptor route__weighted_cluster__descriptor;
extern const ProtobufCMessageDescriptor route__cluster_weight__descriptor;
extern const ProtobufCMessageDescriptor route__header_matcher__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_api_2froute_2froute_5fcomponents_2eproto__INCLUDED */
