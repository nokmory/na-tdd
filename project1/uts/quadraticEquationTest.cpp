#include "quadraticEquation.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md <- here you can find how to properly
// handle floating point numbers in EXPECTs and ASSERTs

using Solution = std::pair<unsigned, std::pair<float, float>>;

class QuadraticEquationTest : public ::testing::Test
{
};

TEST_F(
    QuadraticEquationTest,
    givenEquationXSquareMinus9WithTwoSymmetricRootsFunctionReturnsSolutionWithTwoRootsMinusThreeAndThree)
{
    Solution expectedResult{2, {-3, 3}};
    EXPECT_EQ(expectedResult, utils::quadraticEquation(1, 0, -9));
}

TEST_F(QuadraticEquationTest, givenEquationXSquareMinus6Plus9FunctionReturnsSolutionWith1RootIn3_normal)
{
    unsigned expectedNumberOfRoots{1};
    float expectedRoot{3};

    auto solution = utils::quadraticEquation(1, -6, 9);

    EXPECT_EQ(expectedNumberOfRoots, solution.first);
    EXPECT_EQ(expectedRoot, solution.second.first);
}

TEST_F(QuadraticEquationTest, givenEquationXSquareMinus6Plus9FunctionReturnsSolutionWith1RootIn3_matcher)
{
    using testing::AllOf;
    using testing::AnyOf;
    using testing::Field;

    unsigned expectedNumberOfRoots{1};
    auto expectedRoot{3.0f};

    EXPECT_THAT(
        utils::quadraticEquation(1, -6, 9),
        AllOf(
            Field("num_of_roots", &Solution::first, expectedNumberOfRoots),
            Field("roots", &Solution::second, Field("root1", &std::pair<float, float>::first, expectedRoot))));
}

// TEST_F(QuadraticEquationTest, givenEquationYEqual9FunctionReturnsNoSolutions)
// {
//     Solution expectedSolution{0, {0, 0}};
//     EXPECT_EQ(expectedSolution, utils::quadraticEquation(0, 0, 9));
// }

//(x-3.5)(x+4)
TEST_F(QuadraticEquationTest, test)
{
    Solution expectedSolution{2, {-1, 0}};
    EXPECT_EQ(expectedSolution, utils::quadraticEquation(1, 1, 0));
}