#include <iostream>
#include "Board.h"

const int Arr_Size = 3;

using std::cout;
using std::endl;

int main() {
    int a[Arr_Size][Arr_Size];
    for (int i = 0; i < Arr_Size; ++i) {
        for (int j = 0; j < Arr_Size; ++j) {
            a[i][j] = i * Arr_Size + j;
        }
    }
    int *pt = &a[0][0];

    Board board(pt, Arr_Size);

    cout << board.toString() << endl;
    cout << "hamming: " << board.hamming() << endl;
    cout << "manhatten distance: " << board.manhattan() << endl;




    std::cout << "Hello, World!" << std::endl;
    return 0;
}