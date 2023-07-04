#include <string>
#include <unordered_map>
#include <iostream>

#include "hash_table.h"
#include "key_value_store.h"

namespace brandywine
{
    std::string HashTable::read_key(const std::string key)
    {
        if (HashTable::has_key(key) == false)
        {
            // prevent creating a default key as a side-effect
            return "";
        }
        else
        {
            return data[key];
        }
    }

    void HashTable::write_key(const std::string key, const std::string value)
    {
        data[key] = value;
    }

    bool HashTable::has_key(const std::string key)
    {
        if (data.find(key) == data.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void HashTable::remove_key(const std::string key)
    {
        data.erase(key);
    }

} // namespace brandywine