#ifndef _DARRAY_TESTS_H_

#define _DARRAY_TESTS_H

#include "container/darray.test/darray.fixture.h"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(darray_test);

// #######################################################
// Testing Standards:
// .................
// - For each unit test `T_n()` belongs to a test suit TS, it comprises of 3 parts:
//      0. initial setup for the objects and mockups in-use.
//      1. checks against API output
//      2. checks against internal behavior 
// - Checks are done on the basis of a comparison between standard library behavior
// and our library behavior
// #######################################################


// ##################
// # Constructor Test
// ##################

TYPED_TEST_P(darray_test, DefaultConstructorWithDefaultAllocatorTest) 
{
    // darray a;
    // assert_true: a.empty() == 0
    // assert_true: a.get_allocator() = default_allocator
    // assert true: container should allocate no storage
    darray<TypeParam> x;
}
// #######################################################
TYPED_TEST_P(darray_test, DefaultConstructorWithCustomAllocatorTest) 
{
    // darray a(m), where m is a custom allocator object
    // assert true: a.empty()
    // assert true: a.get_allocator() = m
}
// #######################################################
TYPED_TEST_P(darray_test, CopyConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, CopyConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, MoveConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, MoveConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, FillConstructorWithDefaultValueAndDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, FillConstructorWithInitValueAndDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, FillConstructorWithDefaultValueAndCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, FillConstructorWithInitValueAndCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, RangeConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, RangeConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, InitializerListConstructorWithDefaultAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, InitializerListConstructorWithCustomAllocatorTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, CopyAssignmentTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, MoveAssignmentTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, InitializerListAssignmentTest) 
{

}
// #######################################################
// #######################################################

// #################
// # API Test
// #################

TYPED_TEST_P(darray_test, EmplaceBackTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, EmplaceTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, PushBackLvTest) 
{

}
// #######################################################
TYPED_TEST_P(darray_test, PushBackRvTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, PopBackTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, InsertLvTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, InsertRvTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, FillInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, RangeInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, InitializerListInsertTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, SingleEraseTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, RangeEraseTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, ClearTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, SwapTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, CapacityTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, SizeTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, MaxSizeTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, EmptyTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, ReserveTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, ShrinkToFitTest)
{
   
}
// #######################################################
TYPED_TEST_P(darray_test, GetAllocatorTest)
{
   
}

// #################
// # Register Tests
// #################

REGISTER_TYPED_TEST_SUITE_P(darray_test, 
    // Construction Unit Tests 
    DefaultConstructorWithDefaultAllocatorTest,
    DefaultConstructorWithCustomAllocatorTest,
    CopyConstructorWithDefaultAllocatorTest,
    CopyConstructorWithCustomAllocatorTest,
    MoveConstructorWithDefaultAllocatorTest,
    MoveConstructorWithCustomAllocatorTest,
    FillConstructorWithDefaultValueAndDefaultAllocatorTest,
    FillConstructorWithInitValueAndDefaultAllocatorTest,
    FillConstructorWithDefaultValueAndCustomAllocatorTest,
    FillConstructorWithInitValueAndCustomAllocatorTest,
    RangeConstructorWithDefaultAllocatorTest,
    RangeConstructorWithCustomAllocatorTest,
    InitializerListConstructorWithDefaultAllocatorTest,
    InitializerListConstructorWithCustomAllocatorTest,

    // Assignment Unit Tests
    CopyAssignmentTest,
    MoveAssignmentTest,
    InitializerListAssignmentTest,

    // Modifiers Unit Tests
    EmplaceBackTest,
    EmplaceTest,
    PushBackLvTest,
    PushBackRvTest,
    PopBackTest,
    InsertLvTest,
    InsertRvTest,
    FillInsertTest,
    RangeInsertTest,
    InitializerListInsertTest,
    SingleEraseTest,
    RangeEraseTest,
    ClearTest,
    SwapTest,

    // Storage and Size Unit Tests
    CapacityTest,
    SizeTest,
    MaxSizeTest,
    EmptyTest,
    ReserveTest,
    ShrinkToFitTest,

    // Observers Unit Tests
    GetAllocatorTest
);

using TestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    // error:darray.imp.h:58:45: error: invalid use of array with unspecified bounds
   // 58 | _m_impl._m_end_of_storage - _m_impl._m_start);
    // char[], error:  
    // int[],  error: 
    int*,
    std::string*, 
    std::string, 
    std::vector<int>,
    std::array<int, 10>
    > ;

INSTANTIATE_TYPED_TEST_SUITE_P(darray_test_, darray_test, TestTypeParameters);

// #######################################################

END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_DARRAY_TESTS_H_
