#include "board.hpp"


Size Board::getSize() const {return size;}
Field Board::getFieldState(const Coordinates&) const {return state;}
void Board::setFieldState(const Coordinates&, Field newState) {state = newState;}