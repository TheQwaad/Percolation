#ifndef PERCOLATIONSTATS_HPP
#define PERCOLATIONSTATS_HPP

#include <cstddef>
#include <cstdint>

#include "Percolation.hpp"

struct PercolationStats {
    /**
     * Construct a new Percolation Stats object
     * @param dimension dimension of percolation grid
     * @param trials amount of experiments
     */
    size_t dimension;
    size_t trials;
    long double x_;
    long double s_;
    long double high_;
    long double low_;

    const long double trustMultiplier = 1.96;
    PercolationStats(std::size_t dimension, std::size_t trials);

    /**
     * Returns mean of percolation threshold (x¯ from description)
     */
    [[nodiscard]] double mean() const;

    /**
     * Returns standard deviation of percolation threshold (s from description)
     */
    [[nodiscard]] double standardDeviation() const;

    /**
     * Returns log edge of condidence interval
     */
    [[nodiscard]] double confidenceLow() const;

    /**
     * Returns high edge of confidence interval
     */
    [[nodiscard]] double confidenceHigh() const;

    /**
     * Makes all experiments, calculates statistic values
     */
    void execute();

    size_t genRandomCoord() const;
};

#endif  // PERCOLATIONSTATS_HPP
