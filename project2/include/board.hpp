#pragma once
#include "field.hpp"

enum class Field;

struct Size
{
    unsigned width;
    unsigned height;
};

struct Coordinates
{
    int x;
    int y;
};

class BoardI
{
public:
    virtual Size getSize() const = 0;
    virtual Field getFieldState(const Coordinates&) const =0;
    virtual void setFieldState(const Coordinates&, Field) = 0;
    virtual ~BoardI() = default;
};

class Board : public BoardI
{
public:
    Board(const Size& size): size(size){}
    Size getSize() const override;
    Field getFieldState(const Coordinates&) const override;
    void setFieldState(const Coordinates&, Field) override;
    ~Board() = default;
private:
    Size size;
    Field state{Field::Empty};
};
