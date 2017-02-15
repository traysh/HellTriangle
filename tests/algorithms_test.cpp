#include "gtest/gtest.h"

#include "../src/inc/hell_triangle.hpp"
#include "../src/inc/algorithms.hpp"
#include "test_data.hpp"

using namespace B2W;

TEST(ALGORITHMS, EMPTY_DATA) 
{
    HellTriangle ht(test_data::empty);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 0);
}

TEST(ALGORITHMS, UNIQUE_NODE) 
{
    HellTriangle ht(test_data::unique_node);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 33);
}

TEST(ALGORITHMS, THREE_NODES) 
{
    HellTriangle ht(test_data::three_nodes);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 50);
}

TEST(ALGORITHMS, EXAMPLE_DATA) 
{
    HellTriangle ht(test_data::example);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 26);
}

TEST(ALGORITHMS, INCOMPLETE_TRIANGLE) 
{
    HellTriangle ht(test_data::incomplete_triangle);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 24);
}

TEST(ALGORITHMS, THREE_HUNDRED_NODES)
{
    HellTriangle ht(test_data::three_hundred_nodes);
    
    auto root = ht.root();
    auto result = Algorithms::accumulate(root, ht);
    EXPECT_EQ(result, 368582);
}
