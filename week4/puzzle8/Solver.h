//
// Created by brayden on 2019-10-23.
//

#ifndef PUZZLE8_SOLVER_H
#define PUZZLE8_SOLVER_H

#include "Board.h"


class Solver {
public:
    Solver(Board &initial);
    int moves() { return ans.size() - 1; };
    std::vector<Board> solution();

private:
    std::vector<Board> ans;

};


#endif //PUZZLE8_SOLVER_H
