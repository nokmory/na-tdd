#include "board.hpp"


Size Board::getSize() const {return size;}
Field Board::getFieldState(int, int) const {return state;}
void Board::setFieldState(int, int, Field newState) {state = newState;}