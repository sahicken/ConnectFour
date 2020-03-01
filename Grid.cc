// Copyright 2019 Steven Hicken
#include "Grid.h"

// TODO(sahicken): add testing
// TODO(sahicken): support diagonals
// TODO(sahicken): update variable names
// TODO(sahicken): make call to Rows()
int Grid::Winner() {
    auto potential = 0;  // potential winner
    auto countdown = connect_;  // remaining connections

    // VERTICAL
    for (const auto& column : grid_) {
        for (auto i : column) {
            if (potential != i) {  // if potential changes
                countdown = connect_;  // reset connections
            }
            potential = i;
            // if countdown complete and potential not empty
            if (!--countdown && potential) {
                return potential;
            }
        }
        countdown = connect_;
    }

    // HORIZONTAL
    for (auto i = 0u; i < grid_.back().size(); ++i) {
        for (auto j = 0u; j < grid_.size(); ++j) {
            if (potential != grid_[i][j]) {
                countdown = connect_;
            }
            potential = grid_[i][j];
            if (!--countdown && potential) {
                return potential;
            }
        }
        countdown = connect_;
    }

    return 0;
}

// TODO(sahicken): allocations
// supports diagonals
std::vector<std::vector<std::vector<int>>> Grid::Rows() {
    std::vector<std::vector<std::vector<int>>> rows;

    for (auto i = 0u; i < grid_.size(); ++i) {
        for (auto j = 0u; j < grid_[i].size(); ++j) {
            rows[0][i].push_back(grid_[i][j]);
            // TODO(sahicken): use TDD
            rows[1][j].push_back(grid_[i][j]);
            rows[2][i+j].push_back(grid_[i][j]);
            rows[3][i-j+grid_[i].size()].push_back(grid_[i][j]);
        }
    }

    return rows;
}
