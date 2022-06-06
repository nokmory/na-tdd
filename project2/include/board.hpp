#pragma once
#include "field.hpp"

enum class Field;

struct Size
{
    unsigned width;
    unsigned height;
};

class BoardI
{
public:
    virtual Size getSize() const = 0;
    virtual Field getFieldState(int, int) const =0;
    virtual void setFieldState(int, int, Field) = 0;
    virtual ~BoardI() = default;
};

class Board : public BoardI
{
public:
    Board(const Size& size): size(size){}
    Size getSize() const override;
    Field getFieldState(int, int) const override;
    void setFieldState(int, int, Field) override;
    ~Board() = default;
private:
    Size size;
    Field state{Field::Empty};
};
