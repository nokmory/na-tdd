#pragma once

class InputI;
class BoardI;
enum class Field;

class Player
{
public:
    Player(BoardI& board, InputI& input, Field symbol);
    bool move();
private:
    InputI& input;
    BoardI& board;
    Field symbol;
};
