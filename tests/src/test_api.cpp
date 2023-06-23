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
            // TODO: load some initial keys in the hash table for tests
        }

        brandywine::HashTable mockHashTable;
        std::shared_ptr<brandywine::KeyValueStore> mockKeyVal = std::make_shared<brandywine::HashTable>(mockHashTable);
        brandywine::ApiLayer uutApiLayer = brandywine::ApiLayer(mockKeyVal);
};

/*
Sanity check for a "Hello, World!" response.
*/
TEST_F(ApiLayerTest, IsHelloResponseGood) {
    std::string resp = uutApiLayer.hello_world_response();
    EXPECT_EQ("Hello, World!", resp);
}

// /*
// Tests the ApiLayer's acknowledgement of create
// requests, e.g., whether or not it sends back
// appropriate content.

// We don't care about the exact details of the
// content, but we want to ensure that the content
// makes sense.
// */
// TEST_F(ApiLayerTest, IsCreateRequestAcknowledged) {
//     std::string resp = uutApiLayer.create_key("test", "val");
//     EXPECT_EQ("Create request received.", resp);
// }

// /*
// Similar to the test for create, but this time for read.
// */
// TEST_F(ApiLayerTest, IsReadRequestAcknowledged) {
//     std::string resp = uutApiLayer.read_key("test");
//     EXPECT_EQ("Read request received.", resp);
// }

// /*
// Similar to the test for create, but this time for update.
// */
// TEST_F(ApiLayerTest, IsUpdateRequestAcknowledged) {
//     std::string resp = uutApiLayer.update_key("test", "val");
//     EXPECT_EQ("Update request received.", resp);
// }

// /*
// Similar to test for create, but this time for delete.
// */
// TEST_F(ApiLayerTest, IsDeleteRequestAcknowledged) {
//     std::string resp = uutApiLayer.delete_key("test");
//     EXPECT_EQ("Delete request received.", resp);
// }

// /*
// Uses a mock hash table (and possibly log) to check
// if the API Layer works appropraitely with that hash
// table (and possibly log) to create an entry.

// In this case, we do care about the specific details,
// i.e., we care about what the hash table and/or log
// look like afterwards.
// */
// TEST_F(ApiLayerTest, IsCreateSuccessful) {

// }

// /*
// In this case we don't care about what the hash
// table and/or log looks afterwards, but we do care
// about what the content returned looks like given
// a known state of the hash table and/or log.
// */
// TEST_F(ApiLayerTest, IsReadSuccessful) {

// }

// /*
// We check the hash table and/or log look like
// after a read, ensuring it has no side effects.
// I.e., we want the key-value entries to remain
// entirely the same after a read request.
// */
// TEST_F(ApiLayerTest, ReadHasNoSideEffects) {

// }

// /*
// Similar to test for create, but this time for update.
// */
// TEST_F(ApiLayerTest, IsUpdateSuccessful) {

// }

// /*
// Similar to test for create, but this time for delete.
// */
// TEST_F(ApiLayerTest, IsDeleteSuccessful) {

// }

// /*
// With the mock table and log sleeping to simulate
// a real database lookup, we see whether the ApiLayer
// can handle such requests and does not drop any.
// */
// TEST_F(ApiLayerTest, ParallelRequestsNotDropped) {

// }

// /*
// Test to see if the ApiLayer actually handles the
// requests in parallel. In this case, we'll set the
// mock hash table and/or log to sleep for a long time
// on some keys and a short time on others, and see
// if the ApiLayer returns the requests with the shorter
// wait times more quickly than the requests for the 
// longer wait times.
// */
// TEST_F(ApiLayerTest, ParallelRequestActuallyParallel) {

// }

// /*
// Tests that the ApiLayer remains stable upon receiving
// no data or bad data from the database.
// */
// TEST_F(ApiLayerTest, IsStableUponBadDatabaseRead) {

// }