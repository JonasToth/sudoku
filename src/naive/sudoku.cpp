#include "sudoku.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>

namespace {
void check_indices(uint8_t row, uint8_t col) {
    if (row == 0 || row > 9)
        throw std::invalid_argument{"Row only between [1-9] allowed"};
    if (col == 0 || col > 9)
        throw std::invalid_argument{"Column only between [1-9] allowed"};
}
} /* namespace */

namespace naive {

Cell Sudoku::cellAt(uint8_t row, uint8_t col) const {
    check_indices(row, col);
    row = row - 1;
    col = col - 1;

    return __field[(row * 9) + col];
}

uint8_t Sudoku::valueAt(uint8_t row, uint8_t col) const {
    check_indices(row, col);
    row = row - 1;
    col = col - 1;

    return __field[(row * 9) + col].value();
}

void Sudoku::valueAt(uint8_t row, uint8_t col, uint8_t value) {
    check_indices(row, col);
    row = row - 1;
    col = col - 1;

    if (value < 1 || value > 9)
        throw std::invalid_argument{"values from [1-9] are allowed only"};

    __field[(row * 9) + col].value(value);
}

std::array<uint8_t, 9> Sudoku::row(uint8_t row) const {
    std::array<uint8_t, 9> result;
    for (uint8_t i = 0u; i < 9; ++i)
        result[i] = valueAt(row, i + 1);

    return result;
}

std::array<uint8_t, 9> Sudoku::col(uint8_t col) const {
    std::array<uint8_t, 9> result;
    for (uint8_t i = 0u; i < 9; ++i)
        result[i] = valueAt(i + 1, col);

    return result;
}

std::array<uint8_t, 9> Sudoku::square(uint8_t square) const {
    std::array<uint8_t, 9> result;

    if (square < 1 || square > 9)
        throw std::invalid_argument{"Square only between [1-9] allowed"};

    // Subtract 1 from the square index to use module arithmetic to calculate
    // the offsets into the sudoku indexing.
    --square;

    const int row = square / 3;
    const int col = square % 3;

    const int i_start_row = 1 + (row * 3);
    const int i_end_row = 3 + (row * 3);

    const int i_start_col = 1 + (col * 3);
    const int i_end_col = 3 + (col * 3);

    int sq_index = 0;
    for (int i = i_start_row; i <= i_end_row; ++i) {
        for (int j = i_start_col; j <= i_end_col; ++j) {
            result[sq_index] = valueAt(i, j);
            ++sq_index;
        }
    }

    return result;
}

namespace {
/// Strip whitespace and replace '_' with '0'.
std::string preprocess_row(std::string row) noexcept {
    row.erase(std::remove_if(std::begin(row), std::end(row), ::isspace),
              std::end(row));
    std::replace(std::begin(row), std::end(row), '_', '0');
    return row;
}
} // namespace

Sudoku from_string(const std::string& input) {
    Sudoku result;
    std::istringstream ss(input);
    std::string line;

    int row = 1;
    while (std::getline(ss, line)) {
        line = preprocess_row(line);

        if (line.length() != 9)
            throw std::invalid_argument{"Expect 9 values per row!"};

        int col = 1;
        for (const auto letter : line) {
            if (col > 9)
                throw std::invalid_argument{"Expect 9 columns, got more!"};
            // ASCII 48 is the letter 0
            int number = letter - 48;

            if (number < 0 || number > 9)
                throw std::invalid_argument{"invalid letter conversion"};

            // Don't write '0' becasue that is semantically invalid.
            if (number >= 1)
                result.valueAt(row, col, number);
            ++col;
        }
        if (col < 9)
            throw std::invalid_argument{"Expect 9 columns, got less!"};

        ++row;
    }
    if (row != 10)
        throw std::invalid_argument{"Expect 9 rows!"};

    return result;
} // namespace

} // namespace naive
