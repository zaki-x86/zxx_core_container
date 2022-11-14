
#include "gtest/gtest.h"
#include "zx_containers/containers.hpp"
#include "fixtures/dynamic_array_test.hpp"
#include "helpers/generators.hpp"

#include <iostream>
#include <type_traits>


using namespace zx_containers::test;

TYPED_TEST_SUITE_P(DynamicArrayTest);

// #######################################################
//
// Constructor Test Cases
//
TYPED_TEST_P(DynamicArrayTest, IsEmptyInitially) 
{
    EXPECT_EQ(this->a0_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InitializeWithSingleElement) 
{
    zx_containers::darray<TypeParam> x{this->value_};
    EXPECT_EQ(x.size(), 1);
    EXPECT_EQ(x.get(0), this->value_);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InitializeWithArrayTest) 
{
    zx_containers::darray<TypeParam> xx(this->array_, TEST_INITIAL_SIZE);

    EXPECT_EQ(xx.size(), TEST_INITIAL_SIZE);

    for (long i = 0; i < TEST_INITIAL_SIZE; i++)
        EXPECT_EQ(xx.get(i), this->array_[i]);    
}
// #######################################################
// #######################################################
//
// push_back() Test Cases - Array is not resized
//
TYPED_TEST_P(DynamicArrayTest, PushToEmptyArrayTest) 
{
    for (long i = 0; i < this->sample_values_.size(); i++)
        this->a0_.push_back(this->sample_values_[i]);
    
    EXPECT_EQ(this->a0_.size(), this->sample_values_.size());

    for (long i = 0; i < TEST_INITIAL_SIZE; i++)
        EXPECT_EQ(this->a0_.get(i), this->sample_values_[i]);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, SetMethodTest)
{
    long random_index = generate_numeric(0, TEST_INITIAL_SIZE - 1);
    long initial_size = this->a1_.size();

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
    long random_index = -5;

    std::cout << "[----------] " << "set at index: " << random_index 
    << ", this value: " << this->value_ << "\n";

    GTEST_SKIP();
    EXPECT_ANY_THROW(this->a1_.set(random_index, this->value_));

}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertAtIndexGreaterThanZeroTest)
{
    long random_index = generate_numeric(1, TEST_INITIAL_SIZE);
    long initial_size = this->a1_.size();

    this->a1_.insert(random_index, this->value_);

    // Value is inserted at correct index
    EXPECT_EQ(this->a1_.get(random_index), this->value_);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);  
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertAtIndexZeroTest)
{
    long initial_size = this->a1_.size();
    TypeParam first_element = this->a1_.get(0);

    this->a1_.insert(0, this->value_);

    // Value is inserted at correct index
    EXPECT_EQ(this->a1_.get(0), this->value_);
    // Next value is correct
    EXPECT_EQ(this->a1_.get(1), first_element);
    // size is updated
    EXPECT_EQ(this->a1_.size(), initial_size + 1);  
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, InsertToEmptyArrayTest)
{
    long random_index = generate_numeric(1, TEST_INITIAL_SIZE);

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
    // get() has been used frequently in the previous tests 
    // a1_ is only of size 10
    EXPECT_ANY_THROW(this->a1_.get(100));
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
    long initial_size = this->a1_.size();
    TypeParam to_be_popped = this->a1_.get( initial_size - 1);

    EXPECT_EQ(to_be_popped, this->a1_.pop_back());
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseFirstElementTest)
{
    long initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.get(0);
    TypeParam next_to_be_deleted = this->a1_.get(1);

    EXPECT_EQ(this->a1_.erase(0), to_be_deleted);
    EXPECT_EQ(this->a1_.get(0), next_to_be_deleted);
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
    EXPECT_ANY_THROW(this->a0_.erase(generate_numeric<int>(0, 5)));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseLastElementTest)
{
    long initial_size = this->a1_.size();
    TypeParam to_be_deleted = this->a1_.get(initial_size - 1);
    TypeParam previous_to_be_deleted = this->a1_.get(initial_size - 2);

    EXPECT_EQ(to_be_deleted, this->a1_.erase(initial_size - 1));
    long curr_size = this->a1_.size();
    EXPECT_EQ(curr_size, initial_size - 1);
    EXPECT_EQ(previous_to_be_deleted, this->a1_.get(curr_size - 1));
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseElementRandomIndexTest)
{
    long initial_size = this->a1_.size();
    long rand_index = generate_numeric<int>(1, initial_size - 2);
    TypeParam to_be_deleted = this->a1_.get(rand_index);
    TypeParam next_to_be_deleted =  this->a1_.get(rand_index + 1);
    TypeParam previous_to_be_deleted =  this->a1_.get(rand_index - 1);
    
    EXPECT_EQ(to_be_deleted, this->a1_.erase(rand_index));
    EXPECT_EQ(next_to_be_deleted, this->a1_.get(rand_index));
    EXPECT_EQ(previous_to_be_deleted, this->a1_.get(rand_index - 1));
    EXPECT_EQ(this->a1_.size(), initial_size - 1);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, EraseIndexOutOfRangeTest)
{
    long last_index = this->a1_.size() - 1;
    long error_index = generate_numeric(last_index + 1, last_index + 100);

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
   EXPECT_EQ(this->a1_.get(10), this->value_);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PatchPushBackCausesResizeSimpleTest) 
{
    long samples_size = this->sample_values_.size();
    long initial_size = this->a1_.size();

    for (long i = 0; i < samples_size; i++)
        this->a1_.push_back(this->sample_values_[i]);

    long curr_size = this->a1_.size();

    EXPECT_EQ(curr_size, samples_size + initial_size);
    for (long i = initial_size; i < curr_size; i++)
        EXPECT_EQ(this->a1_.get(i), this->sample_values_[i - initial_size]);
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
    int initial_size = generate_numeric<int>( 1, x.capacity() - 5 );
    std::cout << "[----------] initial_size = " << initial_size << "\n";
    // let: n - 1 < rand_index < x.m_capacity
    int rand_index = generate_numeric<int>( initial_size, x.capacity() - 1 );
    std::cout << "[----------] rand_index = " << rand_index << "\n";
    // set a rand_value to be set
     TypeParam rand_value = generate_random_test_value<TypeParam>();
     std::cout << "[----------] rand_value = " << rand_value << "\n";
    
    // push n random values to x
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < initial_size; i++)
    {
        x.push_back( generate_random_test_value<TypeParam>() );
        std::cout << x.get(i) << ", ";
    }
    std::cout << " }\n";

    std::cout << "[----------] x.set(rand_index, rand_value)" << "\n";
    x.set(rand_index, rand_value);   
    std::cout << "[----------] x.get(rand_index)  = " << x.get(rand_index) << "\n";
    std::cout << "[----------] x.get(rand_index - 1)  = " << x.get(rand_index - 1) << "\n";

    std::cout << "[----------] x After setting \n";
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < x.size(); i++)
    {
        std::cout << x.get(i) << ", ";
    }
    std::cout << " }\n";
    
    EXPECT_EQ(x.get(rand_index), rand_value);
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
    int initial_size = generate_numeric<int>( 1, x.capacity() - 5 );
    std::cout << "[----------] initial_size = " << initial_size << "\n";
    // let: rand_index > x.m_capacity
    int rand_index = generate_numeric<int>( x.capacity() - 1, 100 );
    std::cout << "[----------] rand_index = " << rand_index << "\n";
    // set a rand_value to be set
    TypeParam rand_value = generate_random_test_value<TypeParam>();
    std::cout << "[----------] rand_value = " << rand_value << "\n";

    // push n random values to x
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < initial_size; i++)
    {
        x.push_back( generate_random_test_value<TypeParam>() );
        std::cout << x.get(i) << ", ";
    }
    std::cout << " }\n";

    std::cout << "[----------] x.set(rand_index, rand_value)" << "\n";
    x.set(rand_index, rand_value);   
    std::cout << "[----------] x.get(rand_index)  = " << x.get(rand_index) << "\n";
    std::cout << "[----------] x.get(rand_index - 1)  = " << x.get(rand_index - 1) << "\n";

    std::cout << "[----------] x After setting \n";
    std::cout << "[----------] x = { ";
    for (size_t i = 0; i < x.size(); i++)
    {
        std::cout << x.get(i) << ", ";
    }
    std::cout << " }\n";
    
    EXPECT_EQ(x.get(rand_index), rand_value);
    //EXPECT_GE(x.size(), initial_size);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, IsEmptyAfterClearingArrayTest)
{
    this->a1_.reset();
    EXPECT_EQ(this->a1_.size(), 0);
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, PrintArrayTest)
{
    zx_containers::darray<TypeParam> x(this->array_, TEST_INITIAL_SIZE);
    std::cout << "[----------] x =";
    std::cout << x << std::endl;
}
// #######################################################
TYPED_TEST_P(DynamicArrayTest, ResetMethodTest)
{
    // test started empty
    EXPECT_EQ(this->a0_.size(), 0);

    // fill out with values
    for (long i = 0; i < this->sample_values_.size(); i++)
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
    ResetMethodTest,
    IsEmptyAfterClearingArrayTest,
    PrintArrayTest
    );

using MyTypes = ::testing::Types<char, int, char*, int*, std::string> ;

INSTANTIATE_TYPED_TEST_SUITE_P(DynamicArrayTest_, DynamicArrayTest, MyTypes);

// #######################################################
