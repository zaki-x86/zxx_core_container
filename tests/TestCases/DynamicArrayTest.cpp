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

TEST_F(DynamicArrayTest, PushingElementsToDynamicArray)
{
    // Pushing to empty list
    EXPECT_EQ(a1.size(), 1);
    EXPECT_EQ(a1.get(0), -1);

    // Pushing to non empty list
    EXPECT_EQ(a2.size(), 2);
    EXPECT_EQ(a2.get(0), 1);
    EXPECT_EQ(a2.get(0), 2);

    // Pushing in a loop until full capacity of initial size is reached
    EXPECT_EQ(a3.size(), INITIAL_SIZE);
    EXPECT_EQ(a3.get(0), 1);
    EXPECT_EQ(a3.get(5), 5);
    EXPECT_EQ(a3.get(6), 6);
    EXPECT_EQ(a3.get(9), 9);
}