set(sources
  # ${PROJECT_SOURCE_DIR}/src/main.cpp
)

set(exe_sources
  # ${PROJECT_SOURCE_DIR}/src/main.cpp
  # ${sources}
)

set(container_header
  ${PROJECT_SOURCE_DIR}/include/container/container.h
)

set(graph_header
  ${PROJECT_SOURCE_DIR}/include/graph/graph.h
)

set(headers ${container_header} ${graph_header})

set(container_test_sources
  ${PROJECT_SOURCE_DIR}/test/container/runner.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/sequence_container/darray_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/sequence_container/forward_list_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/sequence_container/list_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/sequence_container/array_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/hash_table_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/map_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/multimap_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/unordered_map_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/unordered_multimap_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/set_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/multiset_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/unordered_set_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/associative_container/unordered_multiset_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/adaptor_container/queue_test.cpp
  ${PROJECT_SOURCE_DIR}/test/container/test_suites/adaptor_container/stack_test.cpp
)
