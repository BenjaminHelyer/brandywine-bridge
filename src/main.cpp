#include "../external/httplib.h"

#include "api_layer.h"
#include <iostream>

int main(void)
{
    httplib::Server svr;

    brandywine::ApiLayer svrApiLayer;

    // set the first get request, passing our response function as a callback
    svr.Get("/hi", [&svrApiLayer](const httplib::Request& req, httplib::Response& res) {
        std::string resp = svrApiLayer.hello_world_response();
        res.set_content(resp, "text/plain");
    });

    svr.listen("localhost", 8080);
}