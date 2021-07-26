#include "board.hpp"
#include "field.hpp"
#include "gtest/gtest.h"

std::ostream& operator<<(std::ostream& str, Field in)
{
    switch (in)
    {
        case Field::EMPTY:
            return str << "EMPTY";
        case Field::X:
            return str << "X";
    }
    return str;
}

class BoardTest : public ::testing::Test
{
};

TEST_F(BoardTest, whenFreshlyCreatedAll9FieldsAreEmpty)
{
    Board sut;

    EXPECT_EQ(sut.at({0, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({0, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({0, 2}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({1, 2}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 0}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 1}), Field::EMPTY);
    EXPECT_EQ(sut.at({2, 2}), Field::EMPTY);
}

TEST_F(BoardTest, whenXPutOnEmptyCoodinate1and2ThenXIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({1, 2}, Field::X);

    EXPECT_EQ(sut.at({1, 2}), Field::X);
}

TEST_F(BoardTest, whenXPutOnEmptyCoodinate0and0ThenXIsReturnedForThisCoordinate)
{
    Board sut;

    sut.put({0, 0}, Field::X);

    EXPECT_EQ(sut.at({0, 0}), Field::X);
}
