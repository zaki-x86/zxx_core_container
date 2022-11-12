## 
# CMake version 
##

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

############################################################################
############################################################################
## 
# Project info 
##

project(Structs  
    VERSION 1.0.0
    DESCRIPTION "data structus in c++"
    LANGUAGES CXX
)

############################################################################
############################################################################
## 
# Variables 
##

## Compile flags
SET(GCC_DEBUGGING_COMPILE_FLAGS "-Wall -ggdb3")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_DEBUGGING_COMPILE_FLAGS}")

set(SRCS
    src/main.cpp
)

set(EXEC_SRCS
    src/main.cpp
)

set(HEADERS
    include/structs/structures.h
)

set(TEST_SRCS
    tests/TestCases/DynamicArrayTest.cpp
    tests/test_runner.cpp
)
############################################################################
############################################################################
##
# Get external packages
##

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

############################################################################
############################################################################
## 
# Build targets
##

if(${PROJECT_NAME}_BUILD_EXECUTABLE)

    add_executable(${PROJECT_NAME} ${EXEC_SRCS} ${SRCS})

    if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
        add_library(${PROJECT_NAME}_LIB ${HEADERS} ${SRCS})
    endif()
    
elseif(${PROJECT_NAME}_BUILD_HEADERS_ONLY)
    add_library(${PROJECT_NAME} INTERFACE)


else()
  add_library(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SRCS}
  )

endif()

############################################################################
############################################################################
## 
# Including Directories 
##

target_include_directories(Structs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

############################################################################
############################################################################
## 
# Installation 
##

############################################################################
############################################################################
## 
# Tests 
##
enable_testing()

add_executable(StructsTest
  ${TEST_SRCS}
)
target_compile_options(StructsTest PRIVATE -ggdb3)

target_link_libraries(
    StructsTest
    GTest::gtest_main
)

target_include_directories(StructsTest
    PUBLIC ${PROJECT_SOURCE_DIR}/tests
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

include(GoogleTest)
gtest_discover_tests(StructsTest)

