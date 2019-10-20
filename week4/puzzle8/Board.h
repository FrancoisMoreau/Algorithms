//
// Created by brayden on 2019-10-19.
//

#ifndef PUZZLE8_BOARD_H
#define PUZZLE8_BOARD_H

#include <string>
#include <cstddef>

class Board {
public:
    Board() = delete;
    Board(int *tiles, const int size) : data(tiles), N(size) {}
    std::string toString();
    int hamming();
    int manhattan();
    bool isGoal();
    bool equals(const Board &rhs);


private:
    int *data;
    int N;
};


#endif //PUZZLE8_BOARD_H
