//
// Created by brayden on 2019-10-23.
//

#include "Solver.h"
#include <queue>

bool compare_hamming(const Board &lhs, const Board &rhs) {
    return rhs.hamming() < lhs.hamming();
}

Solver::Solver(Board &initial) : ans({initial}) {
    std::priority_queue<Board, std::vector<Board>, decltype(compare_hamming)*> minpq(compare_hamming);
    if (initial.isGoal()) return;
    Board prev = initial;
    while (!ans.back().isGoal()) {
        std::vector<Board> neighbors = ans.back().neighbors();
        for (auto &i : neighbors) {
            if (!i.equals(prev))
                minpq.push(i);
        }
        Board temp = minpq.top();

        ans.push_back(minpq.top());
        prev = ans.back();
        minpq.pop();
    }
}

std::vector<Board> Solver::solution() {
    return ans;
}
