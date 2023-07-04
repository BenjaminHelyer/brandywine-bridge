#ifndef BEN_RED_BLACK_NODE_H
#define BEN_RED_BLACK_NODE_H

#include <string>

namespace brandywine {

    class BenRedBlackNode {
        public:
            // TODO: make a constructor that initializes all this
            std::string color;
            int key;
            std::string val;
            BenRedBlackNode* parent;
            BenRedBlackNode* left_child;
            BenRedBlackNode* right_child;

    };

} // namespace brandywine

#endif