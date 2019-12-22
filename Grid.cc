// Copyright 2019 Steven Hicken
#include "Grid.h"

// TODO(sahicken): add testing
// TODO(sahicken): support diagonals
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
