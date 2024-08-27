
#include "PercolationStats.hpp"

#include <cstdlib>
#include <ctime>
#include <random>

PercolationStats::PercolationStats(std::size_t _dim, std::size_t _tries)
    : dimension(_dim), trials(_tries), x_(0.), s_(0.), high_(0.), low_(0.) {
    execute();
}

double PercolationStats::mean() const {
    return x_;
}

double PercolationStats::standardDeviation() const {
    return s_;
}

double PercolationStats::confidenceLow() const {
    return low_;
}

double PercolationStats::confidenceHigh() const {
    return high_;
}

void PercolationStats::execute() {
    std::vector<long double> x(trials);
    for (size_t t = 0; t < trials; t++) {
        Percolation perc(dimension);
        do {
            size_t row, column;
            do {
                row    = genRandomCoord();
                column = genRandomCoord();
            } while (perc.isOpen(row, column));

            perc.open(row, column);
        } while (perc.openedCount < dimension || !perc.hasPercolation());
        size_t openedCount = perc.numberOfOpenCells();
        x[t]               = (long double)openedCount / (long double)(dimension * dimension);
        x_ += x[t];
    }
    x_ /= (long double)trials;
    for (size_t i = 0; i < trials; i++) {
        s_ += pow(x[i] - x_, 2.);
    }
    s_    = sqrt(s_ / ((long double)(trials - 1)));
    low_  = x_ - ((long double)trustMultiplier * s_) / sqrt((double)trials - 1.);
    high_ = x_ + ((long double)trustMultiplier * s_) / sqrt((double)trials - 1.);
}

size_t PercolationStats::genRandomCoord() const {
    static std::mt19937 gen(std::chrono::high_resolution_clock ::now().time_since_epoch().count() ^ (size_t)(new char));
    return gen() % dimension;
}
