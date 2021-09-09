#include "board.hpp"
#include "field.hpp"

Board::Board() : _field(Field::Empty)
{
}

Field Board::getField(const Coordinates &) const
{
    return _field;
}

void Board::setField(const Coordinates &, Field field)
{
    _field = field;
}