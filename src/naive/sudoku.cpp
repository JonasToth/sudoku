#include "sudoku.h"

namespace {
void check_indices(uint8_t row, uint8_t col)
{
    if (row == 0 || row > 9)
        throw std::invalid_argument{ "Row only between [1-9] allowed" };
    if (col == 0 || col > 9)
        throw std::invalid_argument{ "Column only between [1-9] allowed" };
}
} /* namespace */

namespace naive {

Cell Sudoku::cellAt(uint8_t row, uint8_t col) const
{
    check_indices(row, col);
    row = row - 1;
    col = col - 1;

    return __field[(row * 9) + col];
}

uint8_t Sudoku::valueAt(uint8_t row, uint8_t col) const
{
    check_indices(row, col);
    row = row - 1;
    col = col - 1;

    return __field[(row * 9) + col].value();
}

} /* naive */
