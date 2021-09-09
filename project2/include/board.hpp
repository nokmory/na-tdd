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
    virtual void setField(const Coordinates &, Field) = 0;
    virtual Field getField(const Coordinates &) const = 0;
};

class Board : public BoardI
{
public:
    Board();
    void setField(const Coordinates &, Field) override;
    Field getField(const Coordinates &) const override;

private:
    Field _field;
};
