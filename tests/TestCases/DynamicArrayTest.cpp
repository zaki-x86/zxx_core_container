
#include "gtest/gtest.h"
#include "structs/structures.h"
#include "TestClasses/DynamicArrayTest.h"

#include <iostream>
#include <type_traits>


using namespace structs::test;

TYPED_TEST_SUITE_P(DynamicArrayTest);

// #######################################################
TYPED_TEST_P(DynamicArrayTest, IsEmptyInitially) 
{
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InitializeWithSingleElement) 
{
    structs::DynamicArray<TypeParam> x{this->value_};
    EXPECT_EQ(x.size(), 1);
    EXPECT_EQ(x.get(0), this->value_);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InitializeWithArrayTest) 
{
    structs::DynamicArray<TypeParam> xx(this->array_, INITIAL_SIZE);

    EXPECT_EQ(xx.size(), INITIAL_SIZE);

    for (size_t i = 0; i < INITIAL_SIZE; i++)
        EXPECT_EQ(xx.get(i), this->array_[i]);    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PushBackMethodTest) 
{
    for (size_t i = 0; i < this->sample_values_.size(); i++)
    {
        this->a0_.push_back(this->sample_values_[i]);
    }
    
    
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());


    for (size_t i = 0; i < INITIAL_SIZE; i++)
        EXPECT_EQ(this->a0_.get(i), this->sample_values_[i]);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetMethodTest)
{

}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, AddMethodTest)
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, GetMethodTest)
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopMethodTest)
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveMethodTest)
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, ResizeMethodTest)
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, IsEmptyMethodTest)
{
    
}
// #######################################################
REGISTER_TYPED_TEST_SUITE_P(DynamicArrayTest, 
    IsEmptyInitially,
    InitializeWithSingleElement,
    InitializeWithArrayTest,
    PushBackMethodTest,
    SetMethodTest,
    AddMethodTest,
    GetMethodTest,
    PopMethodTest,
    RemoveMethodTest,
    ResizeMethodTest,
    IsEmptyMethodTest
    );

using MyTypes = ::testing::Types<char, int, char*, int*, std::string> ;

INSTANTIATE_TYPED_TEST_SUITE_P(DynamicArrayTest_, DynamicArrayTest, MyTypes);

// #######################################################
