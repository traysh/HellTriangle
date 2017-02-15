#include "hell_triangle.hpp"
#include "algorithms.hpp"

#include <iostream>
#include <stdio.h>

using namespace B2W;

int main()
{
    auto numbers = { 6, 3, 5, 9, 7, 1, 4, 6, 8, 4 };
    HellTriangle ht(numbers);
    
    auto root = ht.root();
    std::cout << "maximum total from top to bottom: " << Algorithms::accumulate(root, ht) << std::endl;
    
    return EXIT_SUCCESS;
}
