#ifndef BEN_RED_BLACK_TREE_H
#define BEN_RED_BLACK_TREE_H

#include "ben_red_black_node.h"
#include "key_value_store.h"

#include <string>

namespace brandywine {

    class BenRedBlackTree : public KeyValueStore {
        private:
            BenRedBlackNode* root;

        public:
            std::string read_key(const std::string key) override;

            void write_key(const std::string key, const std::string val) override;

    };

} // namespace brandywine

#endif