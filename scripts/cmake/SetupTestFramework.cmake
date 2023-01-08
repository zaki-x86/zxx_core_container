
## setup_testframework

# Description:
    # Links test executable and lib against the detected test framework

# Args:
    # test_exe: test executable
    # [libs]: libraries to link executable against


macro(setup_gtest)  
  # import gtest
  if(${CMAKE_PROJECT_NAME}_USE_GTEST)

    include(FetchContent)

    FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Prevent gtest libs from being installed
    option(INSTALL_GMOCK "Install Googletest's GMock?" OFF)
    option(INSTALL_GTEST "Install Googletest's GTest?" OFF)
    FetchContent_MakeAvailable(googletest)

    # build gmock if needed
    if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
        set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
    endif()


  endif()

endmacro()

macro(setup_catch2)
    if(${CMAKE_PROJECT_NAME}_USE_CATCH2)
        find_package(Catch2 REQUIRED) # Catch2::Catch2
    endif()
endmacro()
