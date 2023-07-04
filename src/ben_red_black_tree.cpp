#include <string>

#include "ben_red_black_tree.h"
#include "key_value_store.h"

namespace brandywine {

    std::string BenRedBlackTree::read_key(std::string key) {
        int treeKey = std::stoi(key); // for this impl of red-black tree, we assume all keys are ints (at least for now)
        return "";
    }

    void BenRedBlackTree::write_key(std::string key, std::string val) {
        int treeKey = std::stoi(key);
    }

} // namespace brandywine