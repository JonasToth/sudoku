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
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
