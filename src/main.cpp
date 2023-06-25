#include "../external/httplib.h"

#include "api_layer.h"
#include "hash_table.h"

#include <memory>

int main(void)
{
    httplib::Server svr;

    brandywine::HashTable svrHashTable;
    std::shared_ptr<brandywine::KeyValueStore> svrKeyValueStore = std::make_shared<brandywine::HashTable>(svrHashTable);
    brandywine::ApiLayer svrApiLayer(svrKeyValueStore);

    // set the first get request, passing our response function as a callback
    svr.Get("/hi", [&svrApiLayer](const httplib::Request& req, httplib::Response& res) {
        std::string hello = svrApiLayer.hello_world_response();
        res.set_content(hello, "text/plain");
    });

    // pattern match two strings on this create route
    svr.Get(R"(/create/([^/]+)/([^/]+))", [&svrApiLayer](const httplib::Request& req, httplib::Response& res) {
        auto key = req.matches[1];
        auto val = req.matches[2];
        std::string confirmation = svrApiLayer.create_key(key, val);
        res.set_content(confirmation, "text/plain");
    });

    svr.Get(R"(/read/([^/]+))", [&svrApiLayer](const httplib::Request& req, httplib::Response& res) {
        auto key = req.matches[1];
        std::string confirmation = svrApiLayer.read_key(key);
        res.set_content(confirmation, "text/plain");
    });

    svr.listen("localhost", 8080);
}