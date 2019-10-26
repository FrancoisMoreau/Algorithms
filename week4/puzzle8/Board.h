//
// Created by brayden on 2019-10-19.
//

#ifndef PUZZLE8_BOARD_H
#define PUZZLE8_BOARD_H

#include <string>
#include <vector>
#include <cstddef>

class Board {
public:
    Board() = delete;
    Board(int *tiles, int size);
    std::string toString();
    int hamming() const { return hamming_dis; };
    int manhattan() const { return manhattan_dis; };
    bool isGoal() { return hamming_dis == 0; };
    bool equals(const Board &rhs);
    std::vector<Board> neighbors();


private:
    std::pair<int, int> find0();
    void calculate_hamming();
    void calculate_manhattan();
    std::vector<std::vector<int>> data;
    int N = 0;
    int hamming_dis = 0, manhattan_dis = 0;
};


#endif //PUZZLE8_BOARD_H
