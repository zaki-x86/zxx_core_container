#ifndef _ARRAY_TESTS_H_

#define _ARRAY_TESTS_H_

#include "container/array.test/array.fixture.h"
#include <iostream>
#include <array>

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

TYPED_TEST_SUITE_P(array_test);


TYPED_TEST_P(array_test, DefaultConstructorTest) 
{

}

REGISTER_TYPED_TEST_SUITE_P(array_test,
    DefaultConstructorTest

);

using TestTypeParameters = ::testing::Types<
    char, 
    int, 
    long, 
    char*,
    int*,
    std::string*, 
    std::string, 
    std::array<int, 10>
    >;

INSTANTIATE_TYPED_TEST_SUITE_P(Array_Test, array_test, TestTypeParameters);

END_NS_ZXX_CORE_CONTAINER_TEST


#endif // !_ARRAY_TESTS_H_