#pragma once

enum class Field;

struct Coordinates
{
    int row;
    int column;
};

class BoardI
{
public:
    virtual ~BoardI() = default;
    virtual Field getField(const Coordinates &) const = 0;
};

class Board : public BoardI
{
    Field getField(const Coordinates &) const;
};
