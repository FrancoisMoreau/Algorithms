//
// Created by brayden on 2019-10-19.
//

#include <sstream>
#include "Board.h"

std::string Board::toString() {
    std::ostringstream res;
    res << N << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res << " " << *(data + i * N + j) << " ";
        }
        res << "\n";
    }
    return res.str();
}

int Board::hamming() {
    int ham = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (data[i, j] != i * N + j + 1)
                ham++;
        }
    }
    return ham;
}

int Board::manhattan() {
    int manha = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num = data[i, j];
            if (num == 0) continue;
            int vertical_dist = abs((num - 1) / N - i);
            int horizontal_dist = abs((num - 1) % N - j);
            manha += (vertical_dist + horizontal_dist);
        }
    }
    return manha;
}
