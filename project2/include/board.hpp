#pragma once


class BoardI
{
public:
    virtual ~BoardI() = default;
};

class Board : public BoardI
{
};
