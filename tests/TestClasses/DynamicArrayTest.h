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

#include "structs/structures.h"
#include "gtest/gtest.h"

namespace structs
{
    namespace tests
    {
        /**
         * @brief Test class for DynamicArray class.
         * 
         */
        class DynamicArrayTest : public ::testing::Test
        {
        protected:
            DynamicArray<int> a0;
            DynamicArray<int> a1;
            DynamicArray<int> a2;

            /**
             * @brief Construct a new Dynamic Array Test object
             * 
             */
            DynamicArrayTest();
            /**
             * @brief Destroy the Dynamic Array Test object
             * 
             */
            ~DynamicArrayTest() override;
            
            /**
             * @brief Class members declared here can be used by all tests in the test suite
             * 
             */
            void method_placeholder();
        };


    } // namespace tests
    
    
} // namespace structs

typedef structs::tests::DynamicArrayTest DynamicArrayTest;

DynamicArrayTest::DynamicArrayTest()
{

}