
#include "gtest/gtest.h"
#include "zx_containers/containers.hpp"
#include "fixtures/dynamic_array_test.hpp"
#include "helpers/generators.hpp"

#include <iostream>
#include <type_traits>
#include <algorithm>

using namespace zx_containers::test;

TYPED_TEST_SUITE_P(DynamicArrayTest);

// #######################################################
//
//! Constructor Test Cases
//

/**

 */
TYPED_TEST_P(DynamicArrayTest, DefaultConstructorTest) 
{

}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, FillConstructorTest) 
{
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, RangeConstructorTest) 
{

}
// #######################################################
// #######################################################
//
// push_back() Test Cases - Array is not resized
//
TYPED_TEST_P(DynamicArrayTest, PushToEmptyArrayTest) 
{
    for (size_t i = 0; i < this->sample_values_.size(); i++)
        this->a0_.push_back(this->sample_values_[i]);
    
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    for (size_t i = 0; i < TEST_INITIAL_SIZE; i++)
        EXPECT_EQ(this->a0_.at(i), this->sample_values_[i]);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetMethodTest)
{
    size_t random_index = generate_numeric<size_t>(0, TEST_INITIAL_SIZE - 1);
    size_t initial_size = this->a1_.size();

    this->a1_.set(random_index, this->value_);

    // Value is properly set
    EXPECT_EQ(this->a1_.at(random_index), this->value_);
    // size didn't change
    EXPECT_EQ(this->a1_.size(), initial_size);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetAtIndexLessThanZeroTest)
{

    GTEST_SKIP();
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertAtIndexGreaterThanZeroTest)
{
    size_t random_index = generate_numeric<size_t>(1, TEST_INITIAL_SIZE);
    size_t initial_size = this->a1_.size();

    this->a1_.insert(random_index, this->value_);

    // Value is inserted at correct index
    EXPECT_EQ(this->a1_.at(random_index), this->value_);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);  
}
// #######################################################
/**
 * @brief Inserting a random a value at zero index for a non-empty array
 * 
 * @param a1_ array under test
 * @param initial_size a random value such that 1 =< initial_size < 9
 * @param first_element first element of a1_ before insertion
 *  
 * Checks value at index 0 if it is the same inserted value
 * Checks if value at index 1 is the same as previously first element
 * Checks if size is updated to become initial_size + 1
 */
TYPED_TEST_P(DynamicArrayTest, InsertAtIndexZeroTest)
{
    zx_containers::darray<TypeParam> a;
    size_t initial_size = generate_numeric<size_t>(1, 9);
    
    std::cout << "initial_size: " << initial_size << std::endl;
    
    for (size_t i = 0; i < initial_size; i++)
        a.push_back(generate_random_test_value<TypeParam>());
    
    std::cout << a << std::endl;
    
    TypeParam first_element = a.at(0);

    a.insert(0, this->value_);

    // Value is inserted at correct index
    EXPECT_EQ(a.at(0), this->value_);
    // Next value is correct
    EXPECT_EQ(a.at(1), first_element);
    // size is updated
    EXPECT_EQ(a.size(), initial_size + 1);  
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertToEmptyArrayTest)
{
    size_t random_index = generate_numeric<size_t>(1, TEST_INITIAL_SIZE);

    EXPECT_ANY_THROW(this->a0_.insert(random_index, this->value_));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertAtIndexOutOfRangeTest)
{

    EXPECT_ANY_THROW(this->a1_.insert(100, this->value_));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, GetIndexOutOfRangeTest)
{
    // at() has been used frequently in the previous tests 
    // a1_ is only of size 10
    EXPECT_ANY_THROW(this->a1_.at(100));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopEmptyArrayTest)
{
    EXPECT_ANY_THROW(this->a0_.pop_back());
    
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopArrayWithSingleElementTest)
{
    this->a0_.push_back(this->value_);
    TypeParam popped = this->a0_.pop_back();

    EXPECT_EQ(popped, this->value_);
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PopRandomArrayTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_popped = this->a1_.at( initial_size - 1);

    EXPECT_EQ(to_be_popped, this->a1_.pop_back());
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseFirstElementTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.at(0);
    TypeParam next_to_be_deleted = this->a1_.at(1);

    EXPECT_EQ(this->a1_.erase(0), to_be_deleted);
    EXPECT_EQ(this->a1_.at(0), next_to_be_deleted);
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseFromSingleElementArrayTest)
{
    this->a0_.push_back(this->value_);
    TypeParam deleted = this->a0_.erase(0);

    EXPECT_EQ(deleted, this->value_);
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseFromEmptyArrayTest)
{
    EXPECT_ANY_THROW(this->a0_.erase(generate_numeric<size_t>(0, 5)));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseLastElementTest)
{
    size_t initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.at(initial_size - 1);
    TypeParam previous_to_be_deleted = this->a1_.at(initial_size - 2);

    EXPECT_EQ(to_be_deleted, this->a1_.erase(initial_size - 1));
    size_t curr_size = this->a1_.size();
    EXPECT_EQ(curr_size, initial_size - 1);
    EXPECT_EQ(previous_to_be_deleted, this->a1_.at(curr_size - 1));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseElementRandomIndexTest)
{
    size_t initial_size = this->a1_.size();
    size_t rand_index = generate_numeric<size_t>(1, initial_size - 2);
    TypeParam to_be_deleted = this->a1_.at(rand_index);
    TypeParam next_to_be_deleted =  this->a1_.at(rand_index + 1);
    TypeParam previous_to_be_deleted =  this->a1_.at(rand_index - 1);
    
    EXPECT_EQ(to_be_deleted, this->a1_.erase(rand_index));
    EXPECT_EQ(next_to_be_deleted, this->a1_.at(rand_index));
    EXPECT_EQ(previous_to_be_deleted, this->a1_.at(rand_index - 1));
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseIndexOutOfRangeTest)
{
    size_t last_index = this->a1_.size() - 1;
    size_t error_index = generate_numeric<size_t>(last_index + 1, last_index + 100);

    EXPECT_ANY_THROW(this->a1_.erase(error_index));
}
// #######################################################
// #######################################################
//
// resize() Test Cases for operations that trigger resize()
//
TYPED_TEST_P(DynamicArrayTest, PushBackCausesResizeSimpleTest) 
{
   // Given: a1_.size() = 8, will push a random value 3 times to exceed initial size
   this->a1_.push_back(this->value_);
   this->a1_.push_back(this->value_);
   this->a1_.push_back(this->value_);
   
   EXPECT_EQ(this->a1_.size(), 11);
   EXPECT_EQ(this->a1_.capacity(), 20);
   EXPECT_EQ(this->a1_.at(10), this->value_);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PatchPushBackCausesResizeSimpleTest) 
{
    size_t samples_size = this->sample_values_.size();
    size_t initial_size = this->a1_.size();

    for (size_t i = 0; i < samples_size; i++)
        this->a1_.push_back(this->sample_values_[i]);

    size_t curr_size = this->a1_.size();

    EXPECT_EQ(curr_size, samples_size + initial_size);
    for (size_t i = initial_size; i < curr_size; i++)
        EXPECT_EQ(this->a1_.at(i), this->sample_values_[i - initial_size]);
}
// #######################################################
/**
 * @brief Setting a value at an index i such that: m_size < i < m_capacity, 
 * where m_size > 0
 */
TYPED_TEST_P(DynamicArrayTest, SettingValueAtIndexExceedsSizeTest) 
{
    //init(x): x.m_size = 0, x.m_capacity = 10
    zx_containers::darray<TypeParam> x; 
    // let: 1 =< initial_size < m_capacity
    size_t initial_size = generate_numeric<size_t>( 1, x.capacity() - 5 );
    std::cout << "[----------] initial_size = " << initial_size << "\n";
    // let: n - 1 < rand_index < x.m_capacity
    size_t rand_index = generate_numeric<size_t>( initial_size, x.capacity() - 1 );
    std::cout << "[----------] rand_index = " << rand_index << "\n";
    // set a rand_value to be set
     TypeParam rand_value = generate_random_test_value<TypeParam>();
     std::cout << "[----------] rand_value = " << rand_value << "\n";
    
    // push n random values to x
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < initial_size; i++)
    {
        x.push_back( generate_random_test_value<TypeParam>() );
        std::cout << x.at(i) << ", ";
    }
    std::cout << " }\n";

    std::cout << "[----------] x.set(rand_index, rand_value)" << "\n";
    x.set(rand_index, rand_value);   
    std::cout << "[----------] x.at(rand_index)  = " << x.at(rand_index) << "\n";
    std::cout << "[----------] x.at(rand_index - 1)  = " << x.at(rand_index - 1) << "\n";

    std::cout << "[----------] x After setting \n";
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < x.size(); i++)
    {
        std::cout << x.at(i) << ", ";
    }
    std::cout << " }\n";
    
    EXPECT_EQ(x.at(rand_index), rand_value);
    EXPECT_GE(x.size(), initial_size);

    // if rand_index >= initial_size
    // 
    
}
// #######################################################
/**
 * @brief Setting a value at an index i such that: i > m_capacity,
 * where m_size > 0
 */
TYPED_TEST_P(DynamicArrayTest, SettingValueAtIndexExceedsCapacityTest) 
{
    zx_containers::darray<TypeParam> x; 
     // let: 1 =< initial_size < m_capacity
    size_t initial_size = generate_numeric<size_t>( 1, x.capacity() - 5 );
    std::cout << "[----------] initial_size = " << initial_size << "\n";
    // let: rand_index > x.m_capacity
    size_t rand_index = generate_numeric<size_t>( x.capacity() - 1, 100 );
    std::cout << "[----------] rand_index = " << rand_index << "\n";
    // set a rand_value to be set
    TypeParam rand_value = generate_random_test_value<TypeParam>();
    std::cout << "[----------] rand_value = " << rand_value << "\n";

    // push n random values to x
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < initial_size; i++)
    {
        x.push_back( generate_random_test_value<TypeParam>() );
        std::cout << x.at(i) << ", ";
    }
    std::cout << " }\n";

    std::cout << "[----------] x.set(rand_index, rand_value)" << "\n";
    x.set(rand_index, rand_value);   
    std::cout << "[----------] x.at(rand_index)  = " << x.at(rand_index) << "\n";
    std::cout << "[----------] x.at(rand_index - 1)  = " << x.at(rand_index - 1) << "\n";

    std::cout << "[----------] x After setting \n";
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < x.size(); i++)
    {
        std::cout << x.at(i) << ", ";
    }
    std::cout << " }\n";
    
    EXPECT_EQ(x.at(rand_index), rand_value);
    //EXPECT_GE(x.size(), initial_size);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, IsEmptyAfterClearingArrayTest)
{
    this->a1_.clear();
    EXPECT_EQ(this->a1_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PrintArrayTest)
{
    GTEST_SKIP();
    //zx_containers::darray<TypeParam> x;
    zx_containers::darray<TypeParam> x(5, generate_random_test_value<TypeParam>());
    std::cout << "[----------] x =";
    std::cout << x << std::endl;
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, ClearMethodTest)
{
    // test started empty
    EXPECT_EQ(this->a0_.size(), 0);

    // fill out with values
    for (size_t i = 0; i < this->sample_values_.size(); i++)
        this->a0_.push_back(this->sample_values_[i]);
    
    // test size
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    // call clear() and test size
    this->a0_.clear();
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
REGISTER_TYPED_TEST_SUITE_P(DynamicArrayTest, 
    DefaultConstructorTest,
    FillConstructorTest,
    RangeConstructorTest,
    PushToEmptyArrayTest,
    SetMethodTest,
    SetAtIndexLessThanZeroTest,
    InsertAtIndexGreaterThanZeroTest,
    InsertAtIndexZeroTest,
    InsertToEmptyArrayTest,
    InsertAtIndexOutOfRangeTest,
    GetIndexOutOfRangeTest,
    PopEmptyArrayTest,
    PopArrayWithSingleElementTest,
    PopRandomArrayTest,
    EraseFirstElementTest,
    EraseFromEmptyArrayTest,
    EraseLastElementTest,
    EraseElementRandomIndexTest,
    EraseFromSingleElementArrayTest,
    EraseIndexOutOfRangeTest,
    PushBackCausesResizeSimpleTest,
    PatchPushBackCausesResizeSimpleTest,
    SettingValueAtIndexExceedsSizeTest,
    SettingValueAtIndexExceedsCapacityTest,
    ClearMethodTest,
    IsEmptyAfterClearingArrayTest,
    PrintArrayTest
    );

using MyTypes = ::testing::Types<char, int, char*, int*, std::string> ;

INSTANTIATE_TYPED_TEST_SUITE_P(DynamicArrayTest_, DynamicArrayTest, MyTypes);

// #######################################################
