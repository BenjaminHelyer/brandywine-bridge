#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H

#include <string>

namespace brandywine
{

    /*
     * Abstract base class for the key value store.
     * We assume that our store will at least support
     * these three operations: read, write, and remove.
     */
    class KeyValueStore
    {

    public:
        virtual std::string read_key(std::string key) = 0;

        virtual void write_key(std::string key, std::string val) = 0;

        virtual void remove_key(std::string key) = 0;
    };
} // namespace brandywine

#endif