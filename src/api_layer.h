#ifndef API_LAYER_H
#define API_LAYER_H

#include <string>

namespace brandywine {
    class ApiLayer {
        public:
            std::string hello_world_response();
            std::string create_key(std::string key, std::string val);
            std::string read_key(std::string key);
            std::string update_key(std::string key, std::string val);
            std::string delete_key(std::string key);
    };
}

#endif