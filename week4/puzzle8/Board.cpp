//
// Created by brayden on 2019-10-19.
//

#include <sstream>
#include "Board.h"

Board::Board(int *tiles, const int size) : N(size) {
    for (int i = 0; i < N; ++i) {
        std::vector<int> temp;
        for (int j = 0; j < N; ++j) {
            temp.push_back(*(tiles + i * N + j));
        }
        data.push_back(temp);
    }
    calculate_hamming();
    calculate_manhattan();
}

std::string Board::toString() {
    std::ostringstream res;
    res << N << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res << " " << data[i][j] << " ";
        }
        res << "\n";
    }
    return res.str();
}

void Board::calculate_hamming(){
    int ham = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (data[i][j] != i * N + j + 1)
                ham++;
        }
    }
    if (data[N - 1][N - 1] == 0) ham--;
    hamming_dis =  ham;
}

void Board::calculate_manhattan(){
    int manha = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num = data[i][j];
            if (num == 0) continue;
            int vertical_dist = abs((num - 1) / N - i);
            int horizontal_dist = abs((num - 1) % N - j);
            manha += (vertical_dist + horizontal_dist);
        }
    }
    manhattan_dis = manha;
}

bool Board::equals(const Board &rhs) {
    if (rhs.N != N) return false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rhs.data[i][j] != data[i][j])
                return false;
        }
    }
    return true;
}

std::pair<int, int> Board::find0() {
    for (int i = 0; i < N; ++i ) {
        for (int j = 0; j < N; ++j) {
            if (data[i][j] == 0)
                return {i, j};
        }
    }
    return {0, 0};
}

std::vector<Board> Board::neighbors() {
    std::vector<Board> res;
    auto pos = find0();
    if (pos.first != 0) {
        res.push_back(*this);
        std::swap(res.back().data[pos.first - 1][pos.second],
                res.back().data[pos.first][pos.second]);
    }
    if (pos.first != N - 1) {
        res.push_back(*this);
        std::swap(res.back().data[pos.first + 1][pos.second],
                res.back().data[pos.first][pos.second]);
    }
    if (pos.second != 0) {
        res.push_back(*this);
        std::swap(res.back().data[pos.first][pos.second - 1],
                res.back().data[pos.first][pos.second]);
    }
    if (pos.second != N - 1) {
        res.push_back(*this);
        std::swap(res.back().data[pos.first][pos.second],
                res.back().data[pos.first][pos.second + 1]);
    }
    for (auto &i : res) {
        i.calculate_hamming();
        i.calculate_manhattan();
    }
    return res;
}