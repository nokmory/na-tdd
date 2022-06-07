#include "player.hpp"
#include "input.hpp"
#include "board.hpp"
#include <tuple>

Player::Player(BoardI& board, InputI& input, Field symbol):
    input(input),
    board(board),
    symbol(symbol)
{

}

bool Player::move()
{
    Coordinates coords;
    std::tie(coords.x, coords.y) = input.getInput();

    if(Field::Empty == board.getFieldState(coords))
    {
        board.setFieldState(coords, symbol);
        return true;
    }
    return false;
}