// Copyright 2019 Steven Hicken
#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid {
    public:
        Grid() : connect_(4), grid_(7, std::vector<int>(6)) {}
        int Winner();  // 0 is false, 1 is red, 2 is yellow
        bool AddDisc(int column, int disc);  // false if disc can't be added
        std::vector<std::vector<std::vector<int>>> Rows();
    private:
        int connect_;
        std::vector<std::vector<int>> grid_;
};

#endif  // } GRID_H
