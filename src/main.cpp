#include "../external/httplib.h"

int main(void)
{
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    svr.listen("localhost", 8080);
}