
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
    structs::DynamicArray<TypeParam> xx(this->array_, TEST_INITIAL_SIZE);

    EXPECT_EQ(xx.size(), TEST_INITIAL_SIZE);

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        EXPECT_EQ(xx.get(i), this->array_[i]);    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PushBackMethodTest) 
{
    for (size_t i = 0; i < this->sample_values_.size(); i++)
        this->a0_.push_back(this->sample_values_[i]);
    
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        EXPECT_EQ(this->a0_.get(i), this->sample_values_[i]);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetMethodTest)
{
    size_t random_index = generate_numeric(0, TEST_INITIAL_SIZE - 1);
    size_t initial_size = this->a1_.size();

    this->a1_.set(random_index, this->value_);

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
TYPED_TEST_P(DynamicArrayTest, AddAtIndexGreaterThanZeroTest)
{
    size_t random_index = generate_numeric(1, TEST_INITIAL_SIZE);
    size_t initial_size = this->a1_.size();

    this->a1_.add(random_index, this->value_);

    // Value is added at correct index
    EXPECT_EQ(this->a1_.get(random_index), this->value_);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);  
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, AddAtIndexZeroTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam first_element = this->a1_.get(0);

    this->a1_.add(0, this->value_);

    // Value is added at correct index
    EXPECT_EQ(this->a1_.get(0), this->value_);
    // Next value is correct
    EXPECT_EQ(this->a1_.get(1), first_element);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);  
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, AddToEmptyArrayTest)
{
    size_t random_index = generate_numeric(1, TEST_INITIAL_SIZE);

    EXPECT_ANY_THROW(this->a0_.add(random_index, this->value_));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, AddAtIndexOutOfRangeTest)
{

    EXPECT_ANY_THROW(this->a1_.add(100, this->value_));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, GetIndexOutOfRangeTest)
{
    // get() has been used frequently in the previous tests 
    // a1_ is only of size 10
    EXPECT_ANY_THROW(this->a1_.get(100));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopEmptyArrayTest)
{
    EXPECT_ANY_THROW(this->a0_.pop());
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopArrayWithSingleElementTest)
{
    this->a0_.push_back(this->value_);
    TypeParam popped = this->a0_.pop();

    EXPECT_EQ(popped, this->value_);
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopRandomArrayTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_popped = this->a1_.get( initial_size - 1);

    EXPECT_EQ(to_be_popped, this->a1_.pop());
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveFirstElementTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.get(0);
    TypeParam next_to_be_deleted = this->a1_.get(1);

    EXPECT_EQ(this->a1_.remove(0), to_be_deleted);
    EXPECT_EQ(this->a1_.get(0), next_to_be_deleted);
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveFromSingleElementArrayTest)
{
    this->a0_.push_back(this->value_);
    TypeParam deleted = this->a0_.remove(0);

    EXPECT_EQ(deleted, this->value_);
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveFromEmptyArrayTest)
{
    EXPECT_ANY_THROW(this->a0_.remove(generate_numeric<int>(0, 5)));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveLastElementTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.get(initial_size - 1);
    TypeParam previous_to_be_deleted = this->a1_.get(initial_size - 2);

    EXPECT_EQ(to_be_deleted, this->a1_.remove(initial_size - 1));
    size_t curr_size = this->a1_.size();
    EXPECT_EQ(curr_size, initial_size - 1);
    EXPECT_EQ(previous_to_be_deleted, this->a1_.get(curr_size - 1));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveElementRandomIndexTest)
{
    size_t initial_size = this->a1_.size();
    size_t rand_index = generate_numeric<int>(1, initial_size - 2);
    TypeParam to_be_deleted = this->a1_.get(rand_index);
    TypeParam next_to_be_deleted =  this->a1_.get(rand_index + 1);
    TypeParam previous_to_be_deleted =  this->a1_.get(rand_index - 1);
    
    EXPECT_EQ(to_be_deleted, this->a1_.remove(rand_index));
    EXPECT_EQ(next_to_be_deleted, this->a1_.get(rand_index));
    EXPECT_EQ(previous_to_be_deleted, this->a1_.get(rand_index - 1));
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RemoveIndexOutOfRangeTest)
{
    size_t last_index = this->a1_.size() - 1;
    size_t error_index = generate_numeric(last_index + 1, last_index + 100);

    EXPECT_ANY_THROW(this->a1_.remove(error_index));
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
    AddAtIndexGreaterThanZeroTest,
    AddAtIndexZeroTest,
    AddToEmptyArrayTest,
    AddAtIndexOutOfRangeTest,
    GetIndexOutOfRangeTest,
    PopEmptyArrayTest,
    PopArrayWithSingleElementTest,
    PopRandomArrayTest,
    RemoveFirstElementTest,
    RemoveFromEmptyArrayTest,
    RemoveLastElementTest,
    RemoveElementRandomIndexTest,
    RemoveFromSingleElementArrayTest,
    RemoveIndexOutOfRangeTest,
    ResizeMethodTest,
    ResetMethodTest,
    IsEmptyMethodTest
    );

using MyTypes = ::testing::Types<char, int, char*, int*, std::string> ;

INSTANTIATE_TYPED_TEST_SUITE_P(DynamicArrayTest_, DynamicArrayTest, MyTypes);

// #######################################################
