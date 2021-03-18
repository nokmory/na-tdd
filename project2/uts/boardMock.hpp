#pragma once

#include "gmock/gmock.h"

#include "board.hpp"

class BoardMock : public BoardI
{
public:
    BoardMock() = default;
    ~BoardMock() override = default;
};
