#include "board.hpp"

FieldState Board::getState(Coordinates coords) const
{
    return fields.at(coords.x).at(coords.y);
}

void Board::setState(Coordinates coords, FieldState state)
{
    fields.at(coords.x).at(coords.y) = state;
}