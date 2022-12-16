cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}GraphTest
  LANGUAGES CXX
)

set(TEST_NAME  ${CMAKE_PROJECT_NAME}_graph_test)

verbose_message("Setting up ${TEST_NAME}...")