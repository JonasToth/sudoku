#include "naive/cell.h"
#include "gtest/gtest.h"

using namespace naive;

TEST(cell, default_construction)
{
    Cell c;
    ASSERT_EQ(c.value(), 0u);
}

TEST(cell, value_construction)
{
    Cell c1{ 1u };
    ASSERT_EQ(c1.value(), 1u);
    Cell c2{ 2u };
    ASSERT_EQ(c2.value(), 2u);
    Cell c3{ 3u };
    ASSERT_EQ(c3.value(), 3u);
    Cell c4{ 4u };
    ASSERT_EQ(c4.value(), 4u);
    Cell c5{ 5u };
    ASSERT_EQ(c5.value(), 5u);
    Cell c6{ 6u };
    ASSERT_EQ(c6.value(), 6u);
    Cell c7{ 7u };
    ASSERT_EQ(c7.value(), 7u);
    Cell c8{ 8u };
    ASSERT_EQ(c8.value(), 8u);
    Cell c9{ 9u };
    ASSERT_EQ(c9.value(), 9u);
}

TEST(cell, bad_construction)
{
    ASSERT_THROW(Cell{ 0u }, std::invalid_argument);
    ASSERT_THROW(Cell{ 10u }, std::invalid_argument);
    ASSERT_THROW(Cell{ 255u }, std::invalid_argument);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
