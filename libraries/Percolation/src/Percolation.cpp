#include "Percolation.hpp"

#include <queue>
#include <tuple>

const std::vector<std::pair<size_t, size_t>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

Percolation::Percolation(std::size_t _dim) : dimension(_dim), openedCount(0u), percolate(false) {
    opened.assign(dimension, std::vector<bool>(dimension, false));
}

void Percolation::open(std::size_t _row, std::size_t _column) {
    if (!isOpen(_row, _column)) {
        openedCount++;
    }
    opened[_row][_column] = true;
    if (!hasPercolation()) {
        updatePercolation();
    }
}

bool Percolation::isOpen(std::size_t _row, std::size_t _column) const {
    return opened[_row][_column];
}

bool Percolation::isFull(std::size_t _row, std::size_t _column) const {
    std::vector<std::vector<bool>> used(dimension, std::vector<bool>(dimension, false));
    return isFullDfs(_row, _column, used);
}

std::size_t Percolation::numberOfOpenCells() const {
    return openedCount;
}

bool Percolation::hasPercolation() const {
    return percolate;
}
void Percolation::updatePercolation() {
    std::queue<std::pair<int, int>> bfsQueue;
    for (size_t i = 0; i < dimension; i++) {
        if (isOpen(0, i)) {
            bfsQueue.emplace(0, i);
        }
    }
    if (bfsQueue.empty()) {
        percolate = false;
        return;
    }
    std::vector<std::vector<bool>> used(dimension, std::vector<bool>(dimension, false));
    while (!bfsQueue.empty()) {
        int row, column;
        std::tie(row, column) = bfsQueue.front();
        if (row + 1u == dimension) {
            percolate = true;
            return;
        }
        bfsQueue.pop();
        used[row][column] = true;
        for (auto &addition : moves) {
            int rowTo = row + addition.first, columnTo = column + addition.second;
            if (isPossible(rowTo, columnTo) && !used[rowTo][columnTo] && isOpen(rowTo, columnTo)) {
                bfsQueue.emplace(rowTo, columnTo);
            }
        }
    }
}
bool Percolation::isPossible(size_t row, size_t column) const {
    return std::max(row, column) < dimension && std::min(row, column) >= 0u;
}
bool Percolation::isFullDfs(std::size_t row, std::size_t column, std::vector<std::vector<bool>> &used) const {
    if (row == 0u) {
        return true;
    }
    used[row][column] = true;
    bool result       = false;
    for (auto &addition : moves) {
        int rowTo = row + addition.first, columnTo = column + addition.second;
        if (isPossible(rowTo, columnTo) && !used[rowTo][columnTo] && isOpen(rowTo, columnTo)) {
            result = result || isFullDfs(rowTo, columnTo, used);
        }
    }
    return result;
}
