#include <gtest/gtest.h>
#include "../../external/httplib.h"

#include "../../src/key_value_store.h"
#include "../../src/api_layer.h"
#include "../../src/hash_table.h"

#include <memory>

class ApiLayerTest : public ::testing::Test {
    protected:
        ApiLayerTest() = default;

        void SetUp() override {
            mockKeyVal->write_key("test_key", "test_val");
        }

        brandywine::HashTable exampleHashTable;
        std::shared_ptr<brandywine::KeyValueStore> mockKeyVal = std::make_shared<brandywine::HashTable>(exampleHashTable);
        brandywine::ApiLayer uutApiLayer = brandywine::ApiLayer(mockKeyVal);
};

/*
Sanity check for a "Hello, World!" response.
*/
TEST_F(ApiLayerTest, IsHelloResponseGood) {
    std::string resp = uutApiLayer.hello_world_response();
    EXPECT_EQ("Hello, World!", resp);
}

/*
Tests the ApiLayer's acknowledgement of create
requests, e.g., whether or not it sends back
appropriate content.

We don't care about the exact details of the
content, but we want to ensure that the content
makes sense.
*/
TEST_F(ApiLayerTest, IsCreateRequestAcknowledged) {
    std::string resp = uutApiLayer.create_key("test", "val");
    EXPECT_EQ("Create request received.", resp);
}

/*
Similar to the test for create, but this time for read.
*/
TEST_F(ApiLayerTest, IsReadRequestAcknowledged) {
    std::string resp = uutApiLayer.read_key("test");
    EXPECT_EQ("Read request received. Value not found in store.", resp);
}

/*
Similar to the test for create, but this time for update.
*/
TEST_F(ApiLayerTest, IsUpdateRequestAcknowledged) {
    std::string resp = uutApiLayer.update_key("test", "val");
    EXPECT_EQ("Update request received.", resp);
}

/*
Similar to test for create, but this time for delete.
*/
TEST_F(ApiLayerTest, IsDeleteRequestAcknowledged) {
    std::string resp = uutApiLayer.delete_key("test");
    EXPECT_EQ("Delete request received.", resp);
}

/*
Uses a mock hash table (and possibly log) to check
if the API Layer works appropraitely with that hash
table (and possibly log) to create an entry.

In this case, we do care about the specific details,
i.e., we care about what the hash table and/or log
look like afterwards.
*/
TEST_F(ApiLayerTest, IsCreateSuccessful) {
    std::string resp = uutApiLayer.create_key("key1", "val1");
    std::string received_val = mockKeyVal->read_key("key1");
    EXPECT_EQ("val1", received_val);
}

/*
In this case we don't care about what the hash
table and/or log looks afterwards, but we do care
about what the content returned looks like given
a known state of the hash table and/or log.
*/
TEST_F(ApiLayerTest, IsReadSuccessful) {
    std::string resp_found = uutApiLayer.read_key("test_key");
    EXPECT_EQ("Read request received. Value is: test_val", resp_found);
}

/*
Similar to test for create, but this time for update.
*/
TEST_F(ApiLayerTest, IsUpdateSuccessful) {
    std::string resp_update_1 = uutApiLayer.update_key("test_key", "new_val");
    std::string received_val_1 = mockKeyVal->read_key("test_key");
    EXPECT_EQ("new_val", received_val_1);
    std::string resp_update_2 = uutApiLayer.update_key("test_key", "another_val");
    std::string received_val_2 = mockKeyVal->read_key("test_key");
    EXPECT_EQ("another_val", received_val_2);
}

/*
Similar to test for create, but this time for delete.
*/
TEST_F(ApiLayerTest, IsDeleteSuccessful) {

}

/*
Tests that the ApiLayer remains stable upon not
finding a key in the database.
*/
TEST_F(ApiLayerTest, IsStableUponKeyNotFound) {
    std::string resp_not_found = uutApiLayer.read_key("Nonexistent key");
    EXPECT_EQ("Read request received. Value not found in store.", resp_not_found);
}