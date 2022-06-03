#include "gtest/gtest.h"
#include "stableSort.hpp"

class StableSortTest : public ::testing::Test
{
    protected:
    StableSortTest() {};
    ~StableSortTest() override {};

    void SetUp() override {};
    void TearDown() override {};

};

template<typename T>
struct Distinguishable
{
    T value;
    int orderingNumber;
};

template<typename T>
bool operator==(const Distinguishable<T>& lhs, const Distinguishable<T>& rhs)
{
    return (lhs.value == rhs.value) and (lhs.orderingNumber == rhs.orderingNumber);
}

template<typename T>
std::strong_ordering operator<=>(const Distinguishable<T>& lhs, const Distinguishable<T>& rhs)
{
    return lhs.value <=> rhs.value;
}

template<typename T>
std::ostream& operator<<(std::ostream& str, const Distinguishable<T>& in)
{
    return str << "{ val: " << in.value << " ord: " << in.orderingNumber << " }";
}

TEST_F(StableSortTest, change_this_name)
{

std::vector<Distinguishable<int>> input{{6, 1},{5,2},{5,3},{1,4}};
std::vector<Distinguishable<int>> expectedOutput{{1,4}, {5,2}, {5,3}, {6, 1}};

utils::stableSort(input);

EXPECT_EQ(expectedOutput, input);

}

TEST_F(StableSortTest, change_this_name2)
{

}

TEST_F(StableSortTest, change_this_name3)
{

}