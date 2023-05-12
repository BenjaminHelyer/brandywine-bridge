#include <gtest/gtest.h>

class ApiTest : public ::testing::Test {

};

TEST(ApiTest, IsGoodTest) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}