#include "cell.h"
#include <stdexcept>

Cell::Cell(const uint8_t value)
{
    if (value > 9u || value == 0u)
        throw std::invalid_argument{ "Value for cell must be in range [1,9]" };

    __value = value;
}
