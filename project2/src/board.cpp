#include "board.hpp"
#include "field.hpp"

Field Board::getField(const Coordinates &) const
{
    return Field::Empty;
}
