#include <iostream>

#include "Percolation.hpp"
#include "PercolationStats.hpp"

void ASSERT_TRUE(bool v) {
    std::cout << v << std::endl;
}

void ASSERT_FALSE(bool v) {
    std::cout << v << std::endl;
}

int main() {
    /*
    constexpr std::size_t dimension = 5;
    constexpr std::size_t trials    = 100;
    PercolationStats percolation_stats(dimension, trials);
    std::cout << "mean = " << percolation_stats.mean() << std::endl;
     */
    PercolationStats testPerc(1, 1000);

    const size_t dimension = 3;
    Percolation percolation(dimension);
    std::cout << percolation.isOpen(1, 0) << std::endl;
    ASSERT_FALSE(percolation.isFull(1, 0));
    ASSERT_FALSE(percolation.isOpen(1, 2));
    ASSERT_FALSE(percolation.isFull(1, 2));
    ASSERT_FALSE(percolation.hasPercolation());

    // 0 x x x
    // 1 o x x
    // 2 x x x
    percolation.open(1, 0);
    ASSERT_TRUE(percolation.isOpen(1, 0));
    ASSERT_FALSE(percolation.isFull(1, 0));
    ASSERT_FALSE(percolation.isOpen(1, 2));
    ASSERT_FALSE(percolation.isFull(1, 2));
    ASSERT_FALSE(percolation.hasPercolation());

    // 0 x x x
    // 1 o x o
    // 2 x x x
    percolation.open(1, 2);
    ASSERT_TRUE(percolation.isOpen(1, 0));
    ASSERT_FALSE(percolation.isFull(1, 0));
    ASSERT_TRUE(percolation.isOpen(1, 2));
    ASSERT_FALSE(percolation.isFull(1, 2));
    ASSERT_FALSE(percolation.hasPercolation());

    // 0 x o x
    // 1 o x o
    // 2 x x x
    percolation.open(0, 1);
    ASSERT_TRUE(percolation.isOpen(1, 0));
    ASSERT_FALSE(percolation.isFull(1, 0));
    ASSERT_TRUE(percolation.isOpen(1, 2));
    ASSERT_FALSE(percolation.isFull(1, 2));
    ASSERT_FALSE(percolation.hasPercolation());

    // 0 x o x
    // 1 o o o
    // 2 x x x
    percolation.open(1, 1);
    ASSERT_TRUE(percolation.isOpen(1, 0));
    ASSERT_TRUE(percolation.isFull(1, 0));
    ASSERT_TRUE(percolation.isOpen(1, 2));
    ASSERT_TRUE(percolation.isFull(1, 2));
    ASSERT_FALSE(percolation.hasPercolation());

    // 0 x o x
    // 1 o o o
    // 2 x o x
    percolation.open(2, 1);
    ASSERT_TRUE(percolation.isOpen(1, 0));
    ASSERT_TRUE(percolation.isFull(1, 0));
    ASSERT_TRUE(percolation.isOpen(1, 2));
    ASSERT_TRUE(percolation.isFull(1, 2));
    ASSERT_TRUE(percolation.hasPercolation());
    PercolationStats perc(10, 1000);

    std::cout << perc.mean() << std::endl;

    return 0;
}
