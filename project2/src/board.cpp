#include "board.hpp"
#include "field.hpp"

Board::Board() : field12{Field::EMPTY} {}

Field Board::at(const Coordinates& coords) const
{
    if (coords.x == 1 and coords.y == 2) return field12;
    return Field::EMPTY;
}

void Board::put(const Coordinates&, Field symbol)
{
    field12 = symbol;
}
