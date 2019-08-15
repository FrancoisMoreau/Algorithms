#include <iostream>
#include <fstream>
#include "PercolationStates.h"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Input Error!\n";
        return -1;
    }
    int grid_size = atoi(argv[1]);
    int trial_number = atoi(argv[2]);
    cout << "size: " << grid_size << ", trial times: " << trial_number << endl;
    PercolationStates ps(grid_size, trial_number);
    cout << "mean: " << ps.mean() << endl;
    cout << "stddev: " << ps.stddev() << endl;
    printf("confidence interval: [%f, %f]\n", ps.confidenceLo(), ps.confidenceHi());

//    Percolation pc(20);
//    std::ifstream input("random_5.txt");
//    int row = 0, col = 0;
//    vector<vector<int>> points;
//    while (input) {
//        input >> row;
//        input >> col;
//        points.push_back({row, col});
//        printf("open point (%d, %d)\n", row, col);
//        pc.open(row, col);
//    }
//    cout << "Res: \n";
//    cout << pc.percolates() << endl;
//
//        PercolationStates ps(20, 1, points);
//    cout << "mean: " << ps.mean() << endl;
//    cout << "stddev: " << ps.stddev() << endl;
//    printf("confidence interval: [%f, %f]\n", ps.confidenceLo(), ps.confidenceHi());




    return 0;
}