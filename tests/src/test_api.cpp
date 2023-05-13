#include <gtest/gtest.h>
#include "../../external/httplib.h"

#include "../../src/api_layer.h"

class ApiLayerTest : public ::testing::Test {
    protected:
        void SetUp() override {
            uutApiLayer = brandywine::ApiLayer();
        }
    
        brandywine::ApiLayer uutApiLayer;
};

TEST_F(ApiLayerTest, IsHelloResponseGood) {
    std::string resp = uutApiLayer.hello_world_response();
    EXPECT_EQ("Hello, World!", resp);
}