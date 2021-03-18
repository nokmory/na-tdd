#include "gtest/gtest.h"
#include "fileManipulator.hpp"

// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md <- here you can find how to check for exceptions, but where will FileManipulator throw an exception?

class FileManipulatorTest : public ::testing::Test
{
    protected:
    FileManipulatorTest() {};
    ~FileManipulatorTest() override {};

    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(FileManipulatorTest, change_this_name)
{

}

TEST_F(FileManipulatorTest, change_this_name2)
{

}

TEST_F(FileManipulatorTest, change_this_name3)
{

}