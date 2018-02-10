#ifndef CELL_H_ODI8ALJC
#define CELL_H_ODI8ALJC

#include <cstdint>

namespace naive {
/**
 * @brief One single cell of a sudoku representing the value and all possible 
 * values [1-9].
 */
class Cell {
public:
    Cell() noexcept = default;
    /// Initialize with valid value for the cell.
    Cell(const uint8_t value);
    ~Cell() noexcept = default;

    /// Set the new value of the cell.
    void value(uint8_t new_value) noexcept { __value = new_value; }

    /// Return the value of the cell.
    uint8_t value() const noexcept { return __value; }

private:
    uint8_t __value = 0u; ///< Value of the field.
};

} /* naive */

#endif /* end of include guard: CELL_H_ODI8ALJC */
