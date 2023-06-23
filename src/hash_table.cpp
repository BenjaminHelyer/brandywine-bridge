#include <string>
#include <unordered_map>

#include "hash_table.h"
#include "key_value_store.h"

namespace brandywine {
    std::string HashTable::read_key(const std::string key) {
        return data[key];
    }
    
    void HashTable::write_key(const std::string key, const std::string value) {
        data[key] = value;
    }

} // namespace brandywine