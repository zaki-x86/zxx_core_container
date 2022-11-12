
#include "gtest/gtest.h"
#include "structs/structures.h"
#include "TestClasses/DynamicArrayTest.h"
#include "TestHelpers/generators.h"

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
        this->a0_.push_back(this->sample_values_[i]);
    
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    for (size_t i = 0; i < INITIAL_SIZE; i++)
        EXPECT_EQ(this->a0_.get(i), this->sample_values_[i]);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetMethodTest)
{
    size_t random_index = generate_numeric(0, INITIAL_SIZE - 1);
    size_t initial_size = this->a1_.size();

    this->a1_.set(random_index, this->value_);

    std::cout << "[----------] " << "set at index: " << random_index 
    << ", this value: " << this->value_ << "\n";

    // Value is properly set
    EXPECT_EQ(this->a1_.get(random_index), this->value_);
    // size didn't change
    EXPECT_EQ(this->a1_.size(), initial_size);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetAtIndexLessThanZeroTest)
{
    /**
     * @brief This test will always fail!
     * Since get() method accepts unsigned long params, the negative will be converted to unsigned integer value. This test will be skipped
     */
    size_t random_index = -5;

    std::cout << "[----------] " << "set at index: " << random_index 
    << ", this value: " << this->value_ << "\n";

    GTEST_SKIP();
    EXPECT_ANY_THROW(this->a1_.set(random_index, this->value_));

}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, AddMethodTest)
{
    //structs::DynamicArray<TypeParam> initial_a1 = this->a1_;
    size_t random_index = generate_numeric(0, INITIAL_SIZE - 2);
    size_t initial_size = this->a1_.size();

    this->a1_.add(random_index, this->value_);

    std::cout << "[----------] " << "set at index: " << random_index 
    << ", this value: " << this->value_ << "\n";

    // Value is added at correct index
    EXPECT_EQ(this->a1_.get(random_index), this->value_);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);
    
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
TYPED_TEST_P(DynamicArrayTest, ResetMethodTest)
{
    // test started empty
    EXPECT_EQ(this->a0_.size(), 0);

    // fill out with values
    for (size_t i = 0; i < this->sample_values_.size(); i++)
        this->a0_.push_back(this->sample_values_[i]);
    
    // test size
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    // call reset() and test size
    this->a0_.reset();
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
REGISTER_TYPED_TEST_SUITE_P(DynamicArrayTest, 
    IsEmptyInitially,
    InitializeWithSingleElement,
    InitializeWithArrayTest,
    PushBackMethodTest,
    SetMethodTest,
    SetAtIndexLessThanZeroTest,
    AddMethodTest,
    GetMethodTest,
    PopMethodTest,
    RemoveMethodTest,
    ResizeMethodTest,
    ResetMethodTest,
    IsEmptyMethodTest
    );

using MyTypes = ::testing::Types<char, int, char*, int*, std::string> ;

INSTANTIATE_TYPED_TEST_SUITE_P(DynamicArrayTest_, DynamicArrayTest, MyTypes);

// #######################################################
