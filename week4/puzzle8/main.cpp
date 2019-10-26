#include <iostream>
#include "Board.h"
#include "Solver.h"

const int Arr_Size = 3;

using std::cout;
using std::endl;

int main() {
    int a[Arr_Size][Arr_Size] = {{0, 1, 3}, {4, 2, 5}, {7, 8, 6}};
//    for (int i = 0; i < Arr_Size; ++i) {
//        for (int j = 0; j < Arr_Size; ++j) {
//            a[i][j] = i * Arr_Size + j;
//        }
//    }
    int *pt = &a[0][0];

    Board board(pt, Arr_Size);

    cout << board.toString() << endl;
//    cout << "hamming: " << board.hamming() << endl;
//    cout << "manhatten distance: " << board.manhattan() << endl;

//    cout << "now show the neighbours: \n";
//    std::vector<Board> neighbours = board.neighbors();
//    for (auto &i : neighbours) {
//        cout << i.toString() << endl;
//    }

    cout << "Solution to this puzzle: " << endl;
    Solver puzzleSolution(board);

    cout << "moves: " << puzzleSolution.moves() << endl;
    for (auto &i : puzzleSolution.solution())
        cout << i.toString() << endl;


    return 0;
}