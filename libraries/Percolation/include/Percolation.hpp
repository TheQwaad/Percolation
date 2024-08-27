#ifndef PERCOLATION_HPP
#define PERCOLATION_HPP

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <random>
#include <vector>

struct Percolation {
    std::vector<std::vector<bool>> opened;
    size_t dimension;
    size_t openedCount;
    bool percolate;

    Percolation(std::size_t _dim);

    void open(std::size_t row, std::size_t column);

    [[nodiscard]] bool isOpen(std::size_t row, std::size_t column) const;

    [[nodiscard]] bool isFull(std::size_t row, std::size_t column) const;

    [[nodiscard]] std::size_t numberOfOpenCells() const;

    [[nodiscard]] bool hasPercolation() const;

    void updatePercolation();

    bool isFullDfs(std::size_t _row, std::size_t _column, std::vector<std::vector<bool>> &used) const;


    bool isPossible(size_t row, size_t column) const;
};
#endif  // PERCOLATION_HPP
