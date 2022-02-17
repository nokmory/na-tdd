#include "quadraticEquation.hpp"
#include "gtest/gtest.h"

// https://github.com/google/googletest/blob/main/googletest/docs/advanced.md <- here you can find how to properly handle floating point numbers in EXPECTs and ASSERTs

using Solution = std::pair<unsigned, std::pair<float, float>>;

class QuadraticEquationTest : public ::testing::Test
{
protected:
    QuadraticEquationTest(){};
    ~QuadraticEquationTest() override{};

    void SetUp() override{};
    void TearDown() override{};
};

// ax^2 + bx + c = 0
TEST_F(QuadraticEquationTest, whenAIsEqualOneBIsEqualMinusTwoAndCIsEqualOneThenThereIsOneSolutionEqualOne)
{
    // (x-1)^2 = 0
    //  x^2 - 2x + 1
    Solution expectedSolution{1, {1, 0}};
    EXPECT_EQ(utils::quadraticEquation(1, -2, 1), expectedSolution);
}

TEST_F(QuadraticEquationTest, whenAIsEqualOneBIsEqualZeroAndCIsEqualMinusOneThenThereAreTwoSolutionsEqualOneAndMinusOne)
{
    // x^2 -1 = 0
    Solution expectedSolution{2, {-1, 1}};
    EXPECT_EQ(utils::quadraticEquation(1, 0, -1), expectedSolution);
}

TEST_F(QuadraticEquationTest, whenAIsEqualOneBIsEqualMinusEighteenTwoAndCIsEqualSeventyTwoThenThereAreTwoSolutionsEqualSixAndTwelve)
{
    //(x-6)(x-12)
    // x^2 -18x +72
    Solution expectedSolution{2, {6, 12}};
    EXPECT_EQ(utils::quadraticEquation(1, -18, 72), expectedSolution);
}

TEST_F(QuadraticEquationTest, equationWithRealNumbers)
{
    //(x-6)(x-12)
    // x^2 -18x +72
    Solution expectedSolution{2, {-0.75, 1.25}};
    auto solution = utils::quadraticEquation(12, -7, -14);
    auto firstSolution = solution.second.first;
    auto secondSolution = solution.second.second;
    EXPECT_EQ(solution.first, 2);
    EXPECT_NEAR(firstSolution, -0.75, 0.5);
    EXPECT_NEAR(secondSolution, 1.25, 0.5);
}
