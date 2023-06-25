#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H

#include <string>

namespace brandywine {
    class KeyValueStore {

        public:
            virtual std::string read_key(std::string key) = 0;
            
            virtual void write_key(std::string key, std::string val) = 0;

            virtual void remove_key(std::string key) = 0;

    };
} // namespace brandywine

#endif