#include "gtest/gtest.h"

#include "../src/inc/hell_triangle.hpp"
#include "test_data.hpp"

using namespace B2W;

TEST(HELL_TRIANGLE, EMPTY_DATA) 
{
    HellTriangle ht(test_data::empty);
    
    auto root = ht.root();
    EXPECT_EQ(root, false);
}

TEST(HELL_TRIANGLE, UNIQUE_NODE) 
{
    HellTriangle ht(test_data::unique_node);
    
    auto root = ht.root();
    auto child_left = ht.child_left(root);
    auto child_right = ht.child_right(root);
    
    EXPECT_EQ(root, true);
    EXPECT_EQ(root.i(), 0);
    EXPECT_EQ(root.j(), 0);
    EXPECT_EQ(root.index(), 0);
    EXPECT_EQ(root.value(), 33);
    
    EXPECT_EQ(child_left, false);
    EXPECT_EQ(child_right, false);
}

TEST(HELL_TRIANGLE, THREE_NODES) 
{
    HellTriangle ht(test_data::three_nodes);
    
    auto root = ht.root();
    auto child_left = ht.child_left(root);
    auto child_right = ht.child_right(root);
    auto grandchild_left = ht.child_left(child_left);
    auto grandchild_right = ht.child_right(child_right);
    
    EXPECT_EQ(root, true);
    EXPECT_EQ(root.i(), 0);
    EXPECT_EQ(root.j(), 0);
    EXPECT_EQ(root.index(), 0);
    EXPECT_EQ(root.value(), 33);
    
    EXPECT_EQ(child_left, true);
    EXPECT_EQ(child_left.i(), 1);
    EXPECT_EQ(child_left.j(), 0);
    EXPECT_EQ(child_left.index(), 1);
    EXPECT_EQ(child_left.value(), -10);
    
    EXPECT_EQ(child_right, true);
    EXPECT_EQ(child_right.i(), 1);
    EXPECT_EQ(child_right.j(), 1);
    EXPECT_EQ(child_right.index(), 2);
    EXPECT_EQ(child_right.value(), 17);
    
    EXPECT_EQ(grandchild_left, false);
    EXPECT_EQ(grandchild_right, false);
}

TEST(HELL_TRIANGLE, EXAMPLE_DATA) 
{
    HellTriangle ht(test_data::example);
    
    auto root = ht.root();
    EXPECT_EQ(root, true);
    EXPECT_EQ(root.i(), 0);
    EXPECT_EQ(root.j(), 0);
    EXPECT_EQ(root.index(), 0);
    EXPECT_EQ(root.value(), 6);
    
    auto node_10 = ht.child_left(root);
    EXPECT_EQ(node_10, true);
    EXPECT_EQ(node_10.i(), 1);
    EXPECT_EQ(node_10.j(), 0);
    EXPECT_EQ(node_10.index(), 1);
    EXPECT_EQ(node_10.value(), 3);
    
    auto node_11 = ht.child_right(root);
    EXPECT_EQ(node_11, true);
    EXPECT_EQ(node_11.i(), 1);
    EXPECT_EQ(node_11.j(), 1);
    EXPECT_EQ(node_11.index(), 2);
    EXPECT_EQ(node_11.value(), 5);
    
    auto node_20 = ht.child_left(node_10);
    EXPECT_EQ(node_20, true);
    EXPECT_EQ(node_20.i(), 2);
    EXPECT_EQ(node_20.j(), 0);
    EXPECT_EQ(node_20.index(), 3);
    EXPECT_EQ(node_20.value(), 9);
    
    auto node_21 = ht.child_right(node_10);
    EXPECT_EQ(node_21, true);
    EXPECT_EQ(node_21.i(), 2);
    EXPECT_EQ(node_21.j(), 1);
    EXPECT_EQ(node_21.index(), 4);
    EXPECT_EQ(node_21.value(), 7);
    
    auto node_21_2 = ht.child_left(node_11);
    EXPECT_EQ(node_21_2, true);
    EXPECT_EQ(node_21_2.i(), 2);
    EXPECT_EQ(node_21_2.j(), 1);
    EXPECT_EQ(node_21_2.index(), 4);
    EXPECT_EQ(node_21_2.value(), 7);
    
    auto node_22 = ht.child_right(node_11);
    EXPECT_EQ(node_22, true);
    EXPECT_EQ(node_22.i(), 2);
    EXPECT_EQ(node_22.j(), 2);
    EXPECT_EQ(node_22.index(), 5);
    EXPECT_EQ(node_22.value(), 1);
    
    auto node_30 = ht.child_left(node_20);
    EXPECT_EQ(node_30, true);
    EXPECT_EQ(node_30.i(), 3);
    EXPECT_EQ(node_30.j(), 0);
    EXPECT_EQ(node_30.index(), 6);
    EXPECT_EQ(node_30.value(), 4);
    
    auto node_31 = ht.child_right(node_20);
    EXPECT_EQ(node_31, true);
    EXPECT_EQ(node_31.i(), 3);
    EXPECT_EQ(node_31.j(), 1);
    EXPECT_EQ(node_31.index(), 7);
    EXPECT_EQ(node_31.value(), 6);
    
    auto node_31_2 = ht.child_left(node_21);
    EXPECT_EQ(node_31_2, true);
    EXPECT_EQ(node_31_2.i(), 3);
    EXPECT_EQ(node_31_2.j(), 1);
    EXPECT_EQ(node_31_2.index(), 7);
    EXPECT_EQ(node_31_2.value(), 6);
    
    auto node_32 = ht.child_right(node_21);
    EXPECT_EQ(node_32, true);
    EXPECT_EQ(node_32.i(), 3);
    EXPECT_EQ(node_32.j(), 2);
    EXPECT_EQ(node_32.index(), 8);
    EXPECT_EQ(node_32.value(), 8);
    
    auto node_32_2 = ht.child_left(node_22);
    EXPECT_EQ(node_32_2, true);
    EXPECT_EQ(node_32_2.i(), 3);
    EXPECT_EQ(node_32_2.j(), 2);
    EXPECT_EQ(node_32_2.index(), 8);
    EXPECT_EQ(node_32_2.value(), 8);
    
    auto node_33 = ht.child_right(node_22);
    EXPECT_EQ(node_33, true);
    EXPECT_EQ(node_33.i(), 3);
    EXPECT_EQ(node_33.j(), 3);
    EXPECT_EQ(node_33.index(), 9);
    EXPECT_EQ(node_33.value(), 4);
}

TEST(HELL_TRIANGLE, INCOMPLETE_TRIANGLE) 
{
    HellTriangle ht(test_data::incomplete_triangle);
    
    auto root = ht.root();
    EXPECT_EQ(root, true);
    EXPECT_EQ(root.value(), 6);
    
    auto node_10 = ht.child_left(root);
    EXPECT_EQ(node_10, true);
    EXPECT_EQ(node_10.value(), 3);
    
    auto node_11 = ht.child_right(root);
    EXPECT_EQ(node_11, true);
    EXPECT_EQ(node_11.value(), 5);
    
    auto node_20 = ht.child_left(node_10);
    EXPECT_EQ(node_20, true);
    EXPECT_EQ(node_20.value(), 9);
    
    auto node_21 = ht.child_right(node_10);
    EXPECT_EQ(node_21, true);
    EXPECT_EQ(node_21.value(), 7);
    
    auto node_21_2 = ht.child_left(node_11);
    EXPECT_EQ(node_21_2, true);
    EXPECT_EQ(node_21_2.value(), 7);
    
    auto node_22 = ht.child_right(node_11);
    EXPECT_EQ(node_22, true);
    EXPECT_EQ(node_22.value(), 1);
    
    auto node_30 = ht.child_left(node_20);
    EXPECT_EQ(node_30, true);
    EXPECT_EQ(node_30.value(), 4);
    
    auto node_31 = ht.child_right(node_20);
    EXPECT_EQ(node_31, true);
    EXPECT_EQ(node_31.value(), 6);
    
    auto node_31_2 = ht.child_left(node_21);
    EXPECT_EQ(node_31_2, true);
    EXPECT_EQ(node_31_2.value(), 6);
    
    auto node_32 = ht.child_right(node_21);
    EXPECT_EQ(node_32, false);
    
    auto node_32_2 = ht.child_left(node_22);
    EXPECT_EQ(node_32_2, false);
    
    auto node_33 = ht.child_right(node_22);
    EXPECT_EQ(node_33, false);
}
