#ifndef _DARRAY_FIXTURE_H_

#define _DARRAY_FIXTURE_H_


#include "container/darray.h"

namespace zxx { namespace core { namespace container { namespace test {

    template<typename T>
    class darray_test : public ::testing::Test
    {
    protected:
        void SetUp() override{}
        void TearDown() override{}
    public:
        void assert_correct_instantiation();
    };

}}}}


#endif // !_DARRAY_TEST_HPP