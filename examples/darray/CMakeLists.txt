cmake_minimum_required(VERSION 3.10)

project(
    darray
    DESCRIPTION "Example code snippets for using dynamic_array.hpp"
    LANGUAGES CXX
)

set(sources
    darray_examples.cpp
)

foreach(FILE ${sources})
    message(STATUS "detected example source file: ${FILE}")
endforeach()

add_executable(${PROJECT_NAME}_examples ${sources})
message(STATUS "Built executable target: ${${PROJECT_NAME}Examples}")

target_link_libraries(${PROJECT_NAME}_examples
    PRIVATE
    ${CMAKE_PROJECT_NAME}
)
message(STATUS "Linked ${${PROJECT_NAME}_examples} against the following libraries: 
            ${CMAKE_PROJECT_NAME}"
            )
