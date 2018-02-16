#ifndef SUDOKU_H_5WQRDNWG
#define SUDOKU_H_5WQRDNWG

#include "cell.h"
#include <array>

namespace naive {

/** Describe a sudoku game field.
 *
 * - Indices start with 1 and end with 9.
 * - Each cell encodes its value, 0 if there is no value and tracks possible
 *   values for the cell.
 */
class Sudoku {
public:
    Sudoku() noexcept = default;
    ~Sudoku() noexcept = default;

    Cell cellAt(uint8_t row, uint8_t col) const;
    uint8_t valueAt(uint8_t row, uint8_t col) const;

    std::array<uint8_t, 9> row(uint8_t row) const;
    std::array<uint8_t, 9> col(uint8_t col) const;

    /// Square numbering starts with 1 and is row wise.
    /// 1 - 2 - 3
    /// 4 - 5 - 6
    /// 7 - 8 - 9
    std::array<uint8_t, 9> square(uint8_t square) const;

private:
    std::array<Cell, 81> __field; //< all value of the field, row-wise.
};

} /* naive */

#endif /* end of include guard: SUDOKU_H_5WQRDNWG */
