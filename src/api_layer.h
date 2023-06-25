#ifndef API_LAYER_H
#define API_LAYER_H

#include <string>
#include <memory>

#include "key_value_store.h"

namespace brandywine {
    class ApiLayer {
        private:
            std::shared_ptr<KeyValueStore> store;

        public:
            ApiLayer(std::shared_ptr<KeyValueStore> keyValueStore) : store(keyValueStore) {}

            std::string hello_world_response();
            std::string create_key(std::string key, std::string val);
            std::string read_key(std::string key);
            std::string update_key(std::string key, std::string val);
            std::string delete_key(std::string key);
    };
} // namespace brandywine

#endif