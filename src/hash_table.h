#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "key_value_store.h"

#include <string>
#include <unordered_map>

namespace brandywine {

    class HashTable : public KeyValueStore {
        private:
            std::unordered_map<std::string, std::string> data;

        public:
            std::string read_key(const std::string key) override;

            void write_key(const std::string key, const std::string value) override;

    };

} // namespace brandywine

#endif