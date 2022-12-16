set(sources
  # ${PROJECT_SOURCE_DIR}/src/main.cpp
)

set(exe_sources
  # ${PROJECT_SOURCE_DIR}/src/main.cpp
  # ${sources}
)

set(headers
  ${PROJECT_SOURCE_DIR}/include/container/container.h
)

set(test_sources
  ${PROJECT_SOURCE_DIR}/test/runner.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/darray_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/binary_tree_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/bst_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/graph_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/hash_table_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/linked_list_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/queue_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/stack_test.cpp
  ${PROJECT_SOURCE_DIR}/test/test_suites/red_black_tree_test.cpp
)

set(test_fixtures
  ${PROJECT_SOURCE_DIR}/test/fixtures/darray_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/binary_tree_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/bst_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/graph_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/hash_table_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/linked_list_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/queue_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/stack_test.hpp
  ${PROJECT_SOURCE_DIR}/test/fixtures/red_black_tree_test.hpp
)