#pragma once

#include "input.hpp"
#include <utility>
#include "gmock/gmock.h"

class InputMock : public InputI
{
public:
    InputMock() = default;
    ~InputMock() override = default;

    MOCK_CONST_METHOD0(getInput, std::pair<std::size_t, std::size_t>());
};
