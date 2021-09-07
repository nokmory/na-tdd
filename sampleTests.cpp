#include <cmath>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

constexpr double PI{std::acos(-1)};

// basic test

TEST(environmentTest, passingTest)
{
    EXPECT_EQ(true, true);
}

// test with fixture

struct Fixture : public testing::Test
{
    int sth;
    Fixture() : sth(7) {}
};

TEST_F(Fixture, testUsingFixture)
{
    EXPECT_EQ(sth, 7);
}

// test with mock

using ReturnType = int;
using ArgType1 = char;
using ArgType2 = double;

class FreeInterface
{
public:
    virtual ReturnType methodName(ArgType1, ArgType2) const = 0;
};

struct FreeMock : public FreeInterface
{
    MOCK_METHOD(ReturnType, methodName, (ArgType1, ArgType2), (const, override));
    // MOCK_CONST_METHOD2(methodName, ReturnType(ArgType1, ArgType2)); //Ye olde way
};

TEST(environmentTest, mockPassingTest)
{
    testing::NiceMock<FreeMock> niceMock;
    testing::StrictMock<FreeMock> strictMock;
    EXPECT_CALL(niceMock, methodName(testing::_, 0.4)).Times(1);
    niceMock.methodName('a', 0.4);
}

// parametric test

struct Params
{
    int val;
};

bool operator==(const Params& lhs, const Params& rhs)
{
    return lhs.val == rhs.val;
}

struct ParametricTests : public ::testing::TestWithParam<Params>
{
};

TEST_P(ParametricTests, aTest)
{
    auto params = GetParam();
    EXPECT_EQ(params.val % 2, 0);
}

INSTANTIATE_TEST_CASE_P(ParametricInstatiation, ParametricTests, ::testing::Values(Params{2}, Params{4}));

// matcher instead of equality

struct CoordCart
{
    double x;
    double y;
    double z;
};

struct CoordEuler
{
    double theta;
    double phi;
    double xsi;
};

struct Coords6D
{
    CoordCart location;
    CoordEuler orientation;
};

TEST(ComplicatedTest, checkXAndYEqual0)
{
    Coords6D coords{{0, 0, 35}, {0, PI, PI / 4}};

    EXPECT_THAT(
        coords,
        testing::Field(
            "location",
            &Coords6D::location,
            testing::AllOf(testing::Field("X", &CoordCart::x, 0), testing::Field("Y", &CoordCart::y, 0))));
}