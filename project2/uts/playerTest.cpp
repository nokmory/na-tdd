#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "boardMock.hpp"
#include "inputMock.hpp"
#include "player.hpp"

using testing::_;

struct PlayerTest : public ::testing::Test
{
    testing::NiceMock<BoardMock> boardMock;
    testing::NiceMock<InputMock> inputMock;
};

auto coordsMatch(const Coordinates& c)
{
    using testing::AllOf;
    using testing::Field;
    return AllOf(Field("x", &Coordinates::x, c.x), Field("y", &Coordinates::y, c.y));
}

TEST_F(PlayerTest, playerSetsTheFieldIndicatedByInputWithHisSymbol)
{
    Player player(boardMock, inputMock, Field::X);
    Coordinates expectedCoords{1, 2};

    EXPECT_CALL(inputMock, getInput()).WillOnce(
        testing::Return(std::pair<std::size_t, std::size_t>{
            expectedCoords.x,
            expectedCoords.y}));
    EXPECT_CALL(boardMock, getFieldState(coordsMatch(expectedCoords))).WillOnce(
        testing::Return(Field::Empty));
    EXPECT_CALL(boardMock, setFieldState(coordsMatch(expectedCoords), Field::X));

    EXPECT_TRUE(player.move());
}

TEST_F(PlayerTest, playerDoesNotSetFieldWhichIsAlreadySet)
{
    Player player(boardMock, inputMock, Field::X);
    Coordinates expectedCoords{1,0};

    EXPECT_CALL(inputMock, getInput()).WillOnce(
        testing::Return(std::pair<std::size_t, std::size_t>{
            expectedCoords.x,
            expectedCoords.y}));
    EXPECT_CALL(boardMock, getFieldState(coordsMatch(expectedCoords))).WillOnce(
        testing::Return(Field::Y));
    EXPECT_CALL(boardMock, setFieldState(_, _)).Times(0);

    EXPECT_FALSE(player.move());
}

TEST_F(PlayerTest, playerSetsTheFieldIndicatedByInputWithHisSymbolY)
{
    Player player(boardMock, inputMock, Field::Y);
    Coordinates expectedCoords{1, 2};

    EXPECT_CALL(inputMock, getInput()).WillOnce(
        testing::Return(std::pair<std::size_t, std::size_t>{
            expectedCoords.x,
            expectedCoords.y}));
    EXPECT_CALL(boardMock, getFieldState(coordsMatch(expectedCoords))).WillOnce(
        testing::Return(Field::Empty));
    EXPECT_CALL(boardMock, setFieldState(coordsMatch(expectedCoords), Field::Y));

    EXPECT_TRUE(player.move());
}