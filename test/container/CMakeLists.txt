cmake_minimum_required(VERSION 3.15)

#
# Project details
#

project(
  ${CMAKE_PROJECT_NAME}ContainerTest
  LANGUAGES CXX
)

verbose_message("Setting up target ${CMAKE_PROJECT_NAME}ContainerTest...")


add_executable(
    ${CMAKE_PROJECT_NAME}_container_test
    ${container_test_sources}
)

add_executable(
    ${CMAKE_PROJECT_NAME}_container_test_cxx11
    ${container_test_sources}
    ${test_headers}
)

add_executable(
    ${CMAKE_PROJECT_NAME}_container_test_cxx17
    ${container_test_sources}
    ${test_headers}
)

add_executable(
    ${CMAKE_PROJECT_NAME}_container_test_cxx20
    ${container_test_sources}
    ${test_headers}
)

  #
  # Set the compiler standard
  #

target_compile_features(${CMAKE_PROJECT_NAME}_container_test_cxx11 PUBLIC cxx_std_11)
target_compile_features(${CMAKE_PROJECT_NAME}_container_test_cxx17 PUBLIC cxx_std_17)
target_compile_features(${CMAKE_PROJECT_NAME}_container_test_cxx20 PUBLIC cxx_std_20)

  #
  # Setup code coverage if enabled
  #

if (${CMAKE_PROJECT_NAME}_ENABLE_CODE_COVERAGE)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(${CMAKE_PROJECT_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
    verbose_message("Code coverage is enabled and provided with GCC.")
endif()

#
# Load the desired unit testing framework
#
# Currently supported: GoogleTest (and GoogleMock), Catch2.

if(${CMAKE_PROJECT_NAME}_BUILD_EXECUTABLE)
    set(${CMAKE_PROJECT_NAME}_TEST_LIB ${CMAKE_PROJECT_NAME}_LIB)
    else()
    set(${CMAKE_PROJECT_NAME}_TEST_LIB ${CMAKE_PROJECT_NAME})
endif()

if(${CMAKE_PROJECT_NAME}_USE_GTEST)
    include(FetchContent)
    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)


    if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
        set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
    endif()

    message(STATUS "linking gtest libraries to ${CMAKE_PROJECT_NAME}Test ..")
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test
        PUBLIC
        GTest::gtest_main
        ${GOOGLE_MOCK_LIBRARIES}
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )

    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx11
        PUBLIC
        GTest::gtest_main
        ${GOOGLE_MOCK_LIBRARIES}
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )

    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx17
        PUBLIC
        GTest::gtest_main
        ${GOOGLE_MOCK_LIBRARIES}
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )

    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx20
        PUBLIC
        GTest::gtest_main
        ${GOOGLE_MOCK_LIBRARIES}
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )

    message(STATUS "linking test directory to ${CMAKE_PROJECT_NAME}Test ..")
    target_include_directories(
        ${CMAKE_PROJECT_NAME}_container_test
        PUBLIC
        ${CMAKE_SOURCE_DIR}/test/container
    )
    target_include_directories(
        ${CMAKE_PROJECT_NAME}_container_test_cxx11
        PUBLIC
        ${CMAKE_SOURCE_DIR}/test/container
    )
    target_include_directories(
        ${CMAKE_PROJECT_NAME}_container_test_cxx17
        PUBLIC
        ${CMAKE_SOURCE_DIR}/test/container
    )
    target_include_directories(
        ${CMAKE_PROJECT_NAME}_container_test_cxx20
        PUBLIC
        ${CMAKE_SOURCE_DIR}/test/container
    )

elseif(${CMAKE_PROJECT_NAME}_USE_CATCH2)
    find_package(Catch2 REQUIRED)
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test
        PUBLIC
        Catch2::Catch2
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx11
        PUBLIC
        Catch2::Catch2
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx17
        PUBLIC
        Catch2::Catch2
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_container_test_cxx20
        PUBLIC
        Catch2::Catch2
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )
    
else()
    message(FATAL_ERROR "Unknown testing library. Please setup your desired unit testing library by using `target_link_libraries`.")  
endif()

#
# Add the unit tests
#

include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_container_test)
#gtest_discover_tests(${CMAKE_PROJECT_NAME}_container_test_cxx11)
#gtest_discover_tests(${CMAKE_PROJECT_NAME}_container_test_cxx17)
#gtest_discover_tests(${CMAKE_PROJECT_NAME}_container_test_cxx20)



verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.")