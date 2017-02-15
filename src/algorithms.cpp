#include "algorithms.hpp"

namespace B2W
{
    namespace Algorithms
    {
        int accumulate(HellTriangle::Node& node, HellTriangle& hellTriangle)
        {
            if (!node)
                return 0;
            
            auto child_left = hellTriangle.child_left(node);
            int left_subtree_value = accumulate(child_left, hellTriangle);
            
            auto child_right = hellTriangle.child_right(node);
            int right_subtree_value = accumulate(child_right, hellTriangle);
            
            if (left_subtree_value > right_subtree_value)
                return left_subtree_value + node.value();
            
            return right_subtree_value + node.value();
        }
    }
}
