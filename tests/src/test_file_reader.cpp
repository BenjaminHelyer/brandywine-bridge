#include <gtest/gtest.h>

#include "../../src/file_reader.h"

class FileReaderTest : public ::testing::Test
{
protected:
    FileReaderTest() = default;
};

/*
* Test with a basic write operation on the file.
* Confirms that no errors are raised during this operation.
*/
TEST_F(FileReaderTest, writeIsValid)
{
    EXPECT_EQ("", "");
}

/*
* Test with a basic read operation on a known file.
* Confirms that no errors are raised during the operation.
*/
TEST_F(FileReaderTest, readIsValid)
{
    EXPECT_EQ("", "");
}

/*
* Test with a write followed by a read.
* Ensures that the operations perform as expected.
*/
TEST_F(FileReaderTest, writeThenReadIsSound) {
    EXPECT_EQ("", "");
}

/*
* Test with a read operation given a byte offset
* that is past the end of the file.
* Checks to see if we raise the appropriate error.
*/
TEST_F(FileReaderTest, badOffsetRaisesError) {
    EXPECT_EQ("", "");
}

/*
* Test to read on a deleted file, ensuring that we
* raise the appropriate error.
*/
TEST_F(FileReaderTest, readDeletedFileRaisesError) {
    EXPECT_EQ("", "");
}

/*
* Test to write on a deleted file, ensuring that we
* raise the appropriate error.
*/
TEST_F(FileReaderTest, writeDeletedFileRaisesError) {
    EXPECT_EQ("", "");
}