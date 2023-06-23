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
        std::string resp = svrApiLayer.hello_world_response();
        res.set_content(resp, "text/plain");
    });

    svr.listen("localhost", 8080);
}