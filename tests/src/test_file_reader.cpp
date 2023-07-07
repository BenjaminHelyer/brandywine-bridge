#include <gtest/gtest.h>

class FileReaderTest : public ::testing::Test
{
protected:
    FileReaderTest() = default;
};

TEST_F(FileReaderTest, placeholderCheck)
{
    EXPECT_EQ("", "");
}