#include "gtest/gtest.h"
#include "structs/structures.h"
#include "TestClasses/DynamicArrayTest.h"

TEST_F(DynamicArrayTest, IsEmptyInitially)
{
    EXPECT_EQ(a0.size(), 0);
}

TEST_F(DynamicArrayTest, InitializedWithSingleElementTest)
{
    // size is equal to 1
    EXPECT_EQ(b0.size(), 1);
}