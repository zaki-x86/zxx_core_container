#include "gtest/gtest.h"
#include "structs/structures.h"
#include "TestClasses/DynamicArrayTest.h"

TEST_F(DynamicArrayTest, IsEmptyInitially)
{
    EXPECT_EQ(a0.size(), 0);
}