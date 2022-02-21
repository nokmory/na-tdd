#include "gtest/gtest.h"
#include "board.hpp"
#include "fieldState.hpp"

std::ostream &operator<<(std::ostream &str, FieldState in)
{
    switch (in)
    {
    case FieldState::EMPTY:
        return str << "Empty";
    case FieldState::X:
        return str << "X";
    case FieldState::O:
        return str << "O";
    }
    return str;
}

class BoardTest : public ::testing::Test
{
};

TEST_F(BoardTest, field00isEmptyAfterBoardInitialisation)
{
    Board sut;
    EXPECT_EQ(FieldState::EMPTY, sut.getState({0, 0}));
}

TEST_F(BoardTest, whenFieldIsSetToXThenItsStateBecomesX)
{
    Board sut;
    sut.setState({0, 0}, FieldState::X);
    EXPECT_EQ(FieldState::X, sut.getState({0, 0}));
}

TEST_F(BoardTest, whenDifferentFieldIsSetToXThenFieldStateDoesNotchange)
{
    Board sut;
    sut.setState({0, 0}, FieldState::X);
    EXPECT_EQ(FieldState::EMPTY, sut.getState({0, 1}));
}

TEST_F(BoardTest, whenFieldIsSetToOThenItsStateBecomesO)
{
    Board sut;
    sut.setState({1, 0}, FieldState::O);
    EXPECT_EQ(FieldState::O, sut.getState({1, 0}));
}