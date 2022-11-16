cmake_minimum_required(VERSION 3.10)

project(
    DynamicArray
    DESCRIPTION "Example code snippets for using dynamic_array.hpp"
    LANGUAGES CXX
)

set(sources
    main.cpp
)

add_executable(${PROJECT_NAME}Constructor constructors)
