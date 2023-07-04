#ifndef BEN_RED_BLACK_NODE_H
#define BEN_RED_BLACK_NODE_H

#include <string>

namespace brandywine
{

    class BenRedBlackNode
    {
    public:
        BenRedBlackNode(std::string color,
                        int key,
                        std::string val,
                        BenRedBlackNode *parent,
                        BenRedBlackNode *left_child,
                        BenRedBlackNode *right_child) : color(color),
                                                        key(key),
                                                        val(val),
                                                        left_child(left_child),
                                                        right_child(right_child)
        {
        }

        std::string color;
        int key;
        std::string val;
        BenRedBlackNode *parent;
        BenRedBlackNode *left_child;
        BenRedBlackNode *right_child;
    };

} // namespace brandywine

#endif