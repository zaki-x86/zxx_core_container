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

#include "structs/structures.h"
#include "gtest/gtest.h"
#include "TestHelpers/generators.h"

#define TEST_INITIAL_SIZE 9

namespace structs
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
            structs::DynamicArray<T> a0_;   // empty
            structs::DynamicArray<T> a1_;   // filled upon initialization
            T value_;
            T array_[TEST_INITIAL_SIZE];
            std::vector<T> sample_values_;
        };
    } // namespace test
} // namespace structs

using namespace structs::test;

template <typename T>
void DynamicArrayTest<T>::SetUp()
{
}

template <>
void DynamicArrayTest<int>::SetUp()
{
    const int range_from  = INT32_MIN + 10;
    const int range_to    = INT32_MAX - 10;
    value_ = generate_numeric(range_from, range_to);
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        array_[i] = generate_numeric(range_from, range_to);

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        sample_values_.push_back(generate_numeric(range_from, range_to));

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(generate_numeric(INT32_MIN + 10, INT32_MAX - 10));
}

template <>
void DynamicArrayTest<char>::SetUp()
{
    value_ = generate_char();

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        array_[i] = generate_char();

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        sample_values_.push_back(generate_char());
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(generate_char());
}

template <>
void DynamicArrayTest<char*>::SetUp()
{
    value_ = strdup(generate_string(generate_numeric(0, 20)).c_str());

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        array_[i] = strdup(generate_string(generate_numeric<int>(0, 20)).c_str());

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        sample_values_.push_back(strdup(generate_string(generate_numeric<int>(0, 20)).c_str()));
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(strdup(generate_string(generate_numeric<int>(0, 20)).c_str()));
}

template <>
void DynamicArrayTest<int*>::SetUp()
{
    value_ = new int(generate_numeric<int>(INT32_MIN, INT32_MAX - 10));
    sample_values_.reserve(TEST_INITIAL_SIZE);

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        array_[i] = new int(generate_numeric<int>(INT32_MIN + 10, INT32_MAX - 10));

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        sample_values_.push_back(new int(generate_numeric<int>(INT32_MIN + 10, INT32_MAX - 10)));
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(new int(generate_numeric<int>(INT32_MIN + 10, INT32_MAX - 10)));
}

template<>
void DynamicArrayTest<std::string>::SetUp()
{
    value_ = generate_string(generate_numeric<int>(0, 20));

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        array_[i] = generate_string(generate_numeric<int>(0, 20));

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        sample_values_.push_back(generate_string(generate_numeric<int>(0, 20)));
    
    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
            a1_.push_back(generate_string(generate_numeric<int>(0, 20)));
}

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