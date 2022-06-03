#include "quadraticEquation.hpp"
#include "gtest/gtest.h"

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md <- here you can find how to properly handle floating point numbers in EXPECTs and ASSERTs

class QuadraticEquationTest : public ::testing::Test
{
    protected:
    QuadraticEquationTest() {};
    ~QuadraticEquationTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

using Solution = std::pair<unsigned, std::pair<float, float>>;

// // 0x^2 + 0x + 0 =0
// TEST_F(QuadraticEquationTest, Equation0XSquaredPlus0XPlus0HasSingleSoultionIn0)
// {
//     Solution expectedSolution{1,{0, 0}};

//     EXPECT_EQ(expectedSolution, utils::quadraticEquation(0,0,0));
// }

// x^2 + 0x - 1 = 0
TEST_F(QuadraticEquationTest, EquationXSquaredPlus0XMinus1HasTwoSoultionsInMinus1AndPlus1)
{
    Solution expectedSolution{2,{-1, 1}};

    EXPECT_EQ(expectedSolution, utils::quadraticEquation(1,0,-1));

}

// (x - 5)(x + 4) = x^2 -x -20 = 0
TEST_F(QuadraticEquationTest, EquationXSquaredMinusXMinus20HasTwoSoultionsInMinus4AndPlus5)
{
    Solution expectedSolution{2,{-4, 5}};

    EXPECT_EQ(expectedSolution, utils::quadraticEquation(1,-1,-20));

}