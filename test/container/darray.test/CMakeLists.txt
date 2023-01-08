cmake_minimum_required(VERSION 3.15)

project(darray.test)

include(${CMAKE_SOURCE_DIR}/scripts/cmake/SetupTestFramework.cmake)
include(GoogleTest)

message(STATUS "Setting up testing tool")
setup_gtest()

message(STATUS "gtest found: " ${GTEST_FOUND})

foreach( std cxx_std_11;cxx_std_17;cxx_std_20 )
    # build test executable
    set(test_exe ${PROJECT_NAME}.${std})
    message(STATUS "setting up target: ${test_exe}" )
    add_executable(
        ${test_exe}
        runner.cc
        )

    # set cxx standard
    message(STATUS "Setting c++ standard: '${std}' to target: '${test_exe}' ..")
    target_compile_features( ${test_exe} PUBLIC ${std} )

    # link gtest to executable target
    message(STATUS "linking gtest library to target '${test_exe}' ..")
    target_link_libraries(
        ${test_exe}
        PUBLIC
        GTest::gtest_main
        ${GOOGLE_MOCK_LIBRARIES}
        # TODO: How to link with container library
    )

    # include directories
    message(STATUS "linking directories to target '${test_exe}' ..")
    target_include_directories(
        ${test_exe}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/test
        ${CMAKE_SOURCE_DIR}/include
    )

    # add unit tests
    message(STATUS "Adding unit tests")
    gtest_discover_tests(${test_exe})

endforeach()