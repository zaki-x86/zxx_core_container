#pragma once

#include "helpers/ultimate.h"

BEGIN_NS_ZXX_CORE_CONTAINER_TEST

    template<typename T>
    class darray_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    public:
        void assert_correct_instantiation();
    };

END_NS_ZXX_CORE_CONTAINER_TEST