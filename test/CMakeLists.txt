cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}Test
  LANGUAGES CXX
)

verbose_message("Initial setup...")

add_subdirectory(container)