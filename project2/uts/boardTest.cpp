#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "board.hpp"
#include "field.hpp"

class BoardTest : public ::testing::Test
{
    protected:
    BoardTest() {};
    ~BoardTest() override {};

    void SetUp() override{};
    void TearDown() override {};
};

TEST_F(BoardTest, givenBoardHasSize0By0ItReturns0By0)
{
    Board board{Size{0,0}};
    Size expectedSize{0,0};

    EXPECT_THAT(board.getSize(), testing::AllOf(
        testing::Field("width", &Size::width, expectedSize.width),
        testing::Field("height", &Size::height, expectedSize.height)
    ));
}

TEST_F(BoardTest, givenBoardHasSize4By3ItReturns4By3)
{
    Board board{Size{4,3}};
    Size expectedSize{4,3};

    EXPECT_THAT(board.getSize(), testing::AllOf(
        testing::Field("width", &Size::width, expectedSize.width),
        testing::Field("height", &Size::height, expectedSize.height)
    ));
}

TEST_F(BoardTest, givenFresh3By3BoardWhenStateOfUpperLeftfieldIsCheckedItReturnsFree)
{
    Board board{Size{3,3}};

    EXPECT_EQ(board.getFieldState(0,0), Field::Empty);
}

TEST_F(BoardTest, givenStateOfUpperLeftfieldIsSetToXCheckedItReturnsX)
{
    Board board{Size{3,3}};
    board.setFieldState(0,0,Field::X);

    EXPECT_EQ(board.getFieldState(0,0), Field::X);
}