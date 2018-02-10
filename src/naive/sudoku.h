#ifndef SUDOKU_H_5WQRDNWG
#define SUDOKU_H_5WQRDNWG

#include "cell.h"
#include <array>

namespace naive {

class Sudoku {
public:
    Sudoku() noexcept = default;
    ~Sudoku() noexcept = default;

    Cell cellAt(uint8_t row, uint8_t col) const;
    uint8_t valueAt(uint8_t row, uint8_t col) const;

private:
    std::array<Cell, 81> __field; //< all value of the field, row-wise.
};

} /* naive */

#endif /* end of include guard: SUDOKU_H_5WQRDNWG */
