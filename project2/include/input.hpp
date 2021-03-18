#pragma once

#include <utility>

// Do no change anything in this file,
// do not create a coresponding cpp file,
// instead use mocks!

class InputI
{
public:
    virtual ~InputI() = default;

    virtual std::pair<std::size_t, std::size_t> getInput() const = 0;
};

class HumanInput : public InputI // do not implement this class!
{
public:
    std::pair<std::size_t, std::size_t> getInput() const;
};

class AiInput : public InputI // do not implement this class!
{
public:
    std::pair<std::size_t, std::size_t> getInput() const;
};
