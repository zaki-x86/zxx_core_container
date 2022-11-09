#include "gtest/gtest.h"
#include "structs/structures.h"
#include "TestClasses/DynamicArrayTest.h"

TEST_F(DynamicArrayTest, IsEmptyInitially)
{
    EXPECT_EQ(a0.size(), 0);
}

TEST_F(DynamicArrayTest, InitializedWithSingleElementTest)
{
    // initialized with an (int) type
    EXPECT_EQ(b0.size(), 1);
    EXPECT_EQ(b0.get(0), 100);

    // .. TODO! ..
    // initialized with an (std::string) type

    // initialized with an (char) type

    // initialized with an (char*) type

    // initialized with an (double) type

    // initialized with an (float) type

    // initialized with an (any non-primitive) type
}

TEST_F(DynamicArrayTest, InitializedWithArrayTest)
{
    // initialized with an (int) array
    EXPECT_EQ(ba0.size(), 5);
    EXPECT_EQ(ba0.get(0), 0);
    EXPECT_EQ(ba0.get(1), 1);
    EXPECT_EQ(ba0.get(2), 2);
    EXPECT_EQ(ba0.get(3), 3);
    EXPECT_EQ(ba0.get(4), 4);

    // .. TODO! ..
    // initialized with an (std::string) array

    // initialized with an (char) array

    // initialized with an (char*) array

    // initialized with an (double) array

    // initialized with an (float) array

    // initialized with an (any non-primitive) array

}