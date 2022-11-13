/**
 * @file DynamicArrayTest.h
 * @author M Zaki (you@domain.com)
 * @brief Test suite for DynamicArray class
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright M Zaki Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <type_traits>
#include <memory>

#include "zx_containers/containers.hpp"
#include "gtest/gtest.h"
#include "helpers/generators.h"

#define TEST_INITIAL_SIZE INITIAL_SIZE - 2

namespace zx_containers
{
    namespace test
    {
        template<typename T>
        class DynamicArrayTest : public ::testing::Test
        {
        protected:
            void SetUp() override;
            void TearDown() override;
        public:
            zx_containers::darray<T> a0_;   // empty
            zx_containers::darray<T> a1_;   // filled upon initialization
            T value_;
            T array_[TEST_INITIAL_SIZE];
            std::vector<T> sample_values_;
        };
    } // namespace test
} // namespace zx_containers

using namespace zx_containers::test;

template <typename T>
void DynamicArrayTest<T>::SetUp()
{
    set_random_test_value(value_);
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        set_random_test_value(array_[i]);
    
    set_random_test_values(sample_values_);

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(generate_random_test_value<T>());
}

// --- Destructors ---
template <typename T>
void DynamicArrayTest<T>::TearDown()
{
    a1_.reset();
}

template <>
void DynamicArrayTest<int*>::TearDown()
{
    delete value_;

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
    {
        delete array_[i];
        delete sample_values_[i];
    }
}
