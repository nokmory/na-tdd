#include "board.hpp"
#include "field.hpp"

Field Board::at(const Coordinates& coords) const
{
    return fields[coords.x][coords.y];
}

void Board::put(const Coordinates& coords, Field symbol)
{
    fields[coords.x][coords.y] = symbol;
}
