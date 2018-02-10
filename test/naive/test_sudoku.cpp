#include "naive/sudoku.h"
#include "gtest/gtest.h"

using namespace naive;

TEST(sudoku, default_construction)
{
    Sudoku s;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
