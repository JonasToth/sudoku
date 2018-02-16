#include "naive/sudoku.h"
#include "gtest/gtest.h"

using namespace naive;

TEST(sudoku, default_construction)
{
    Sudoku s;
}

TEST(sudoku, valueAt_dummy)
{
    Sudoku s;
    bool all_zero = true;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (s.valueAt(i, j) != 0)
                all_zero = false;

            EXPECT_EQ(s.valueAt(i, j), 0);
        }
    }
    ASSERT_TRUE(all_zero);
}
TEST(sudoku, valueAt_exception)
{
    Sudoku s;
    ASSERT_THROW(s.valueAt(0, 0), std::invalid_argument);
    ASSERT_THROW(s.valueAt(2, 0), std::invalid_argument);
    ASSERT_THROW(s.valueAt(0, 2), std::invalid_argument);
    ASSERT_THROW(s.valueAt(10, 10), std::invalid_argument);
    ASSERT_THROW(s.valueAt(10, 9), std::invalid_argument);
    ASSERT_THROW(s.valueAt(9, 10), std::invalid_argument);
}

TEST(sudoku, cellAt_dummy)
{
    Sudoku s;
    bool all_zero = true;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (s.cellAt(i, j).value() != 0)
                all_zero = false;

            EXPECT_EQ(s.cellAt(i, j).value(), 0);
        }
    }
    ASSERT_TRUE(all_zero);
}
TEST(sudoku, cellAt_exception)
{
    Sudoku s;
    ASSERT_THROW(s.cellAt(0, 0), std::invalid_argument);
    ASSERT_THROW(s.cellAt(2, 0), std::invalid_argument);
    ASSERT_THROW(s.cellAt(0, 2), std::invalid_argument);
    ASSERT_THROW(s.cellAt(10, 10), std::invalid_argument);
    ASSERT_THROW(s.cellAt(10, 9), std::invalid_argument);
    ASSERT_THROW(s.cellAt(9, 10), std::invalid_argument);
}

TEST(sudoku, row_dummy)
{
    Sudoku s;
    for(int i = 1; i <= 9; ++i) {
        const auto row = s.row(i);
        bool all_zero = true;

        for(const auto value: row) {
            if(value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, row_exception)
{
    Sudoku s;

    ASSERT_THROW(s.row(0), std::invalid_argument);
    ASSERT_THROW(s.row(10), std::invalid_argument);
}

TEST(sudoku, col_dummy)
{
    Sudoku s;
    for(int i = 1; i <= 9; ++i) {
        const auto col = s.col(i);
        bool all_zero = true;

        for(const auto value: col) {
            if(value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, col_exception)
{
    Sudoku s;

    ASSERT_THROW(s.col(0), std::invalid_argument);
    ASSERT_THROW(s.col(10), std::invalid_argument);
}

TEST(sudoku, square_dummy)
{
    Sudoku s;
    for(int i = 1; i <= 9; ++i) {
        const auto square = s.square(i);
        bool all_zero = true;

        for(const auto value: square) {
            if(value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, square_exception)
{
    Sudoku s;

    ASSERT_THROW(s.square(0), std::invalid_argument);
    ASSERT_THROW(s.square(10), std::invalid_argument);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
