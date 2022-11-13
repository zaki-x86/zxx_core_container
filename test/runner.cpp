/**
 * @file test_runner.cpp
 * @author M Zaki 
 * @brief test driver for the test cases created in tests/ and src/test_structs
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright Zaki (c) 2022
 * 
 */

#include <iostream>
#include "gtest/gtest.h"
#include <zx_containers/containers.hpp>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
