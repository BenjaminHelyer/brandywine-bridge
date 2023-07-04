#include "../external/httplib.h"

#include "api_layer.h"
#include "hash_table.h"

#include <memory>

/*
 * We base these routes off the API specification as follows:
 * /create/<key>/<val> -- creates a key with value val
 * /read/<key> -- reads the key
 * /update/<key>/<val> -- updates the key
 * /delete/<key>/<val> -- deletes the key
 */
int main(void)
{
    httplib::Server svr;

    brandywine::HashTable svrHashTable; // just use a hash table for the store for now, we can swap it out later
    std::shared_ptr<brandywine::KeyValueStore> svrKeyValueStore = std::make_shared<brandywine::HashTable>(svrHashTable);
    brandywine::ApiLayer svrApiLayer(svrKeyValueStore);

    svr.Get("/hi", [&svrApiLayer](const httplib::Request &req, httplib::Response &res)
            {
        std::string hello = svrApiLayer.hello_world_response();
        res.set_content(hello, "text/plain"); });

    svr.Get(R"(/create/([^/]+)/([^/]+))", [&svrApiLayer](const httplib::Request &req, httplib::Response &res)
            {
        auto key = req.matches[1];
        auto val = req.matches[2];
        std::string confirmation = svrApiLayer.create_key(key, val);
        res.set_content(confirmation, "text/plain"); });

    svr.Get(R"(/read/([^/]+))", [&svrApiLayer](const httplib::Request &req, httplib::Response &res)
            {
        auto key = req.matches[1];
        std::string confirmation = svrApiLayer.read_key(key);
        res.set_content(confirmation, "text/plain"); });

    svr.Get(R"(/update/([^/]+)/([^/]+))", [&svrApiLayer](const httplib::Request &req, httplib::Response &res)
            {
        auto key = req.matches[1];
        auto val = req.matches[2];
        std::string confirmation = svrApiLayer.update_key(key, val);
        res.set_content(confirmation, "text/plain"); });

    svr.Get(R"(/delete/([^/]+))", [&svrApiLayer](const httplib::Request &req, httplib::Response &res)
            {
        auto key = req.matches[1];
        std::string confirmation = svrApiLayer.delete_key(key);
        res.set_content(confirmation, "text/plain"); });

    svr.listen("localhost", 8080);
}