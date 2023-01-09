cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  container_test
  LANGUAGES CXX
)

option(TEST_ALL "toggle option to execute all unit tests from all test suites" OFF)
option(TEST_ARRAY "toggle option to execute array container test cases" OFF)
option(TEST_DARRAY "toggle option to execute darray container test cases" OFF)


if(TEST_ALL)
  add_subdirectory(container/array.test)
  add_subdirectory(container/darray.test)
elseif(TEST_ARRAY)
  add_subdirectory(container/array.test)
elseif(TEST_DARRAY)
  add_subdirectory(container/darray.test)
endif()


verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")