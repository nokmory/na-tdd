#pragma once

#include "gmock/gmock.h"

#include "board.hpp"

class BoardMock : public BoardI
{
public:
    BoardMock() = default;
    ~BoardMock() override = default;
    MOCK_METHOD(Size, getSize, (), (const, override));
    MOCK_METHOD(Field, getFieldState, (const Coordinates&), (const, override));
    MOCK_METHOD(void, setFieldState, (const Coordinates&, Field), (override));
};
