#ifndef SUDOKU_H_5WQRDNWG
#define SUDOKU_H_5WQRDNWG

#include "cell.h"
#include <array>

namespace naive {
class Sudoku {
public:
    Sudoku() noexcept = default;

    ~Sudoku() noexcept = default;

private:
    std::array<Cell, 81> __field; //< all value of the field, row-wise.
};
} /* naive */

#endif /* end of include guard: SUDOKU_H_5WQRDNWG */
