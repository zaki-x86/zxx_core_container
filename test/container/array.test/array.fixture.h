#ifndef _ARRAY_FIXTURE_H_

#define _ARRAY_FIXTURE_H_


#include "container/array.h"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class array_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    };


END_NS_ZXX_CORE_CONTAINER_TEST

#endif // !_DARRAY_TEST_HPP