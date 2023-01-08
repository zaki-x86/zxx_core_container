cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  container_test
  LANGUAGES CXX
)


add_subdirectory(container/darray.test)


verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")