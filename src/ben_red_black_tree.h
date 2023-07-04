#ifndef BEN_RED_BLACK_TREE_H
#define BEN_RED_BLACK_TREE_H

#include "key_value_store.h"

#include <string>

namespace brandywine {

    class BenRedBlackTree : public KeyValueStore {
        private:
            // instantiate a root node of class BenRedBlackNode

        public:
            std::string read_key(const std::string key) override;

            void write_key(const std::string key, const std::string val) override;

    };

} // namespace brandywine

#endif