#include <gtest/gtest.h>
#include "../../external/httplib.h"

#include "../../src/api_layer.h"

class ApiLayerTest : public ::testing::Test {
    
};

TEST(ApiLayerTest, IsHelloResponseGood) {
    httplib::Client cli("localhost", 8080);
}