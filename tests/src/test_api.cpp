#include <gtest/gtest.h>

#include "../../src/api_layer.h"

class ApiLayerTest : public ::testing::Test {

};

TEST(ApiLayerTest, IsGoodTest) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}