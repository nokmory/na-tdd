#pragma once

enum class Field;

struct Coordinates
{
    int x;
    int y;
};

class BoardI
{
public:
    virtual ~BoardI() = default;
    virtual Field at(const Coordinates&) const = 0;
    virtual void put(const Coordinates&, Field) = 0;
};

class Board : public BoardI
{
public:
    Board();
    Field at(const Coordinates&) const override;
    void put(const Coordinates&, Field) override;

private:
    Field field12;
};
