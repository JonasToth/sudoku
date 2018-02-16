#include "naive/sudoku.h"
#include "gtest/gtest.h"

using namespace naive;

TEST(sudoku, default_construction) { Sudoku s; }

TEST(sudoku, valueAt_dummy) {
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
TEST(sudoku, valueAt_exception) {
    Sudoku s;
    ASSERT_THROW(s.valueAt(0, 0), std::invalid_argument);
    ASSERT_THROW(s.valueAt(2, 0), std::invalid_argument);
    ASSERT_THROW(s.valueAt(0, 2), std::invalid_argument);
    ASSERT_THROW(s.valueAt(10, 10), std::invalid_argument);
    ASSERT_THROW(s.valueAt(10, 9), std::invalid_argument);
    ASSERT_THROW(s.valueAt(9, 10), std::invalid_argument);
}
TEST(sudoku, set_valueAt) {
    Sudoku s;

    s.valueAt(1, 1, 5);
    ASSERT_EQ(s.valueAt(1, 1), 5);

    ASSERT_THROW(s.valueAt(0, 0, 1), std::invalid_argument);
    ASSERT_THROW(s.valueAt(0, 1, 1), std::invalid_argument);
    ASSERT_THROW(s.valueAt(1, 0, 1), std::invalid_argument);
    ASSERT_THROW(s.valueAt(1, 1, 0), std::invalid_argument);
    ASSERT_THROW(s.valueAt(1, 1, 10), std::invalid_argument);
}

TEST(sudoku, cellAt_dummy) {
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
TEST(sudoku, cellAt_exception) {
    Sudoku s;
    ASSERT_THROW(s.cellAt(0, 0), std::invalid_argument);
    ASSERT_THROW(s.cellAt(2, 0), std::invalid_argument);
    ASSERT_THROW(s.cellAt(0, 2), std::invalid_argument);
    ASSERT_THROW(s.cellAt(10, 10), std::invalid_argument);
    ASSERT_THROW(s.cellAt(10, 9), std::invalid_argument);
    ASSERT_THROW(s.cellAt(9, 10), std::invalid_argument);
}

TEST(sudoku, row_dummy) {
    Sudoku s;
    for (int i = 1; i <= 9; ++i) {
        const auto row = s.row(i);
        bool all_zero = true;

        for (const auto value : row) {
            if (value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, row_exception) {
    Sudoku s;

    ASSERT_THROW(s.row(0), std::invalid_argument);
    ASSERT_THROW(s.row(10), std::invalid_argument);
}

TEST(sudoku, col_dummy) {
    Sudoku s;
    for (int i = 1; i <= 9; ++i) {
        const auto col = s.col(i);
        bool all_zero = true;

        for (const auto value : col) {
            if (value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, col_exception) {
    Sudoku s;

    ASSERT_THROW(s.col(0), std::invalid_argument);
    ASSERT_THROW(s.col(10), std::invalid_argument);
}

TEST(sudoku, square_dummy) {
    Sudoku s;
    for (int i = 1; i <= 9; ++i) {
        const auto square = s.square(i);
        bool all_zero = true;

        for (const auto value : square) {
            if (value != 0)
                all_zero = false;
            EXPECT_EQ(value, 0);
        }
        ASSERT_TRUE(all_zero);
    }
}
TEST(sudoku, square_exception) {
    Sudoku s;

    ASSERT_THROW(s.square(0), std::invalid_argument);
    ASSERT_THROW(s.square(10), std::invalid_argument);
}

TEST(sudoku, from_string_full_errors) {
    std::string bad = "3 5 1 9 8 4 6 7 2\n";
    ASSERT_THROW(from_string(bad), std::invalid_argument);

    bad = "3 1 3 5 1 9 8 4 6 7 2\n";
    ASSERT_THROW(from_string(bad), std::invalid_argument);

    bad = "9 8 4 6 7 2\n";
    ASSERT_THROW(from_string(bad), std::invalid_argument);

    std::string full = "3 5 1 9 8 4 6 7 2\n"
                       "4 6 9 2 5 7 8 3 1\n"
                       "2 8 7 6 1 3 5 4 9\n"
                       "2 8 7 6 1 3 5 4 9\n"
                       "9 4 6 8 3 2 1 5 7\n"
                       "9 4 6 8 3 2 1 5 7\n"
                       "1 2 8 7 4 5 3 9 6\n"
                       "5 7 3 1 9 6 2 8 4\n"
                       "6 9 2 3 7 8 4 1 5\n"
                       "7 3 4 5 6 1 9 2 8\n"
                       "8 1 5 4 2 9 7 6 3";
    ASSERT_THROW((void)from_string(full), std::invalid_argument);
}
TEST(sudoku, from_string_full_0) {
    std::string full = "3 5 1 9 8 4 6 7 2\n"
                       "4 6 9 2 5 7 8 3 1\n"
                       "2 8 7 6 1 3 5 4 9\n"
                       "9 4 6 8 3 2 1 5 7\n"
                       "1 2 8 7 4 5 3 9 6\n"
                       "5 7 3 1 9 6 2 8 4\n"
                       "6 9 2 3 7 8 4 1 5\n"
                       "7 3 4 5 6 1 9 2 8\n"
                       "8 1 5 4 2 9 7 6 3";
    const auto sudoku_full = from_string(full);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_full.valueAt(1, 1), 3);
    ASSERT_EQ(sudoku_full.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_full.valueAt(5, 5), 4);
    ASSERT_EQ(sudoku_full.valueAt(7, 7), 4);
    ASSERT_EQ(sudoku_full.valueAt(9, 9), 3);
}
TEST(sudoku, from_string_full_1) {
    std::string full = "351984672\n"
                       "469257831\n"
                       "287613549\n"
                       "946832157\n"
                       "128745396\n"
                       "573196284\n"
                       "692378415\n"
                       "734561928\n"
                       "815429763";
    const auto sudoku_full = from_string(full);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_full.valueAt(1, 1), 3);
    ASSERT_EQ(sudoku_full.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_full.valueAt(5, 5), 4);
    ASSERT_EQ(sudoku_full.valueAt(7, 7), 4);
    ASSERT_EQ(sudoku_full.valueAt(9, 9), 3);
}
TEST(sudoku, from_string_full_2) {
    std::string full = "  351984672  \n"
                       "    469257831   \n"
                       "  287613549 \n"
                       "946832157   \n"
                       "128745396   \n"
                       " 57319   6284\n"
                       "        692378415\n"
                       "     73 45  61 92  8\n"
                       "815429763";
    const auto sudoku_full = from_string(full);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_full.valueAt(1, 1), 3);
    ASSERT_EQ(sudoku_full.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_full.valueAt(5, 5), 4);
    ASSERT_EQ(sudoku_full.valueAt(7, 7), 4);
    ASSERT_EQ(sudoku_full.valueAt(9, 9), 3);
}


TEST(sudoku, from_string_sparse_0) {
    std::string sparse = "_ _ _ _ _ 4 _ _ 2\n"
                         "_ 6 _ 2 _ _ _ 3 _\n"
                         "_ 8 _ _ _ 3 5 _ 9\n"
                         "_ 4 _ _ _ _ 1 _ _\n"
                         "1 _ _ 7 _ 5 _ _ _\n"
                         "5 _ 3 _ _ _ _ _ _\n"
                         "_ 9 _ 3 _ _ _ _ _\n"
                         "_ _ 4 _ 6 1 _ _ _\n"
                         "_ _ 5 _ _ _ 7 _ _";
    const auto sudoku_sparse = from_string(sparse);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_sparse.valueAt(1, 4), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_sparse.valueAt(3, 8), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(5, 9), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(9, 7), 7);
}
TEST(sudoku, from_string_sparse_1) {
    std::string sparse = "0_0__4__2\n"
                         "_6_2___3_\n"
                         "_80__35_9\n"
                         "_4____1__\n"
                         "1_07_5___\n"
                         "5_3__0___\n"
                         "_9_3__0__\n"
                         "__4_61___\n"
                         "__5___7__";
    const auto sudoku_sparse = from_string(sparse);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_sparse.valueAt(1, 4), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_sparse.valueAt(3, 8), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(5, 9), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(9, 7), 7);
}
TEST(sudoku, from_string_sparse_2) {
    std::string sparse = "      _ _ _ _ _ 4 _ _   2   \n"
                         "_ 6 _     2 _  _ _ 3 _\n"
                         "  _ 8 _ _ 0 3 5 _ 9\n"
                         "        _ 4 _ _ _ _ 1 _ _\n"
                         "  1 _ _ 7 0 5 _ 0 _    \n"
                         "  5 _ 3 _ _ _ _ _ _   \n"
                         "_ 9 _ 3 _ 0 _ _ _\n"
                         "_ _ 4 _ 6 1 _ 0 _          \n"
                         "_ _ 5 _ _ _ 7 _ _";
    const auto sudoku_sparse = from_string(sparse);

    // Sample the sudoku to check the result.
    ASSERT_EQ(sudoku_sparse.valueAt(1, 4), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(2, 2), 6);
    ASSERT_EQ(sudoku_sparse.valueAt(3, 8), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(5, 9), 0);
    ASSERT_EQ(sudoku_sparse.valueAt(9, 7), 7);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
