//
// Created by brayden on 2019-08-12.
//

#include "PercolationStates.h"
#include <random>
#include <fstream>
#include <string>

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(1, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

PercolationStates::PercolationStates(int n, int trials):
    gride_size(n), trial_times(trials), trial_opensites_num(trials, 0.f) {
    for (int i = 0; i < trials; ++i) {
        printf("Trial %d: \n", i);
        Percolation test(n);
        vector<vector<int>> random_points;
        printf("came here\n");
        fflush(stdout);
        while (!test.percolates()) {
            int row = get_random(gride_size);
            int col = get_random(gride_size);
            if (!test.isOpen(row, col)) {
                test.open(row, col);
                random_points.push_back({row, col});
            }
//            printf("State point: (%d, %d), status: %d\n", row, col, test.percolates());
        }
        printf("came here2\n");
        fflush(stdout);
        double opensite_ratio = test.numberOfOpenSites() * 1.f / (gride_size * gride_size);
        printf("Percolates! open sites number: %f\n", opensite_ratio);
        trial_opensites_num[i] = opensite_ratio;
//        if (opensite_ratio < 0.1f) {
//            std::cout << "Attension: ratio = " << opensite_ratio << std::endl;
//            std::string filename = "random_" + std::to_string(i) + ".txt";
//            std::ofstream output;
//            output.open(filename);
//            if (!output)
//                std::cerr << "file open failed\n";
//            for (auto &i : random_points) {
//                output << (i)[0] << " " << (i)[1] << "\n";
//            }
//        }
    }
    cal_mean();
    cal_stddev();
    cal_confidence();
}

void PercolationStates::cal_mean() {
    double sum = 0.f;
    for (int i = 0; i < trial_times; ++i)
        sum  += trial_opensites_num[i];
    mean_val = sum / trial_times;
}

void PercolationStates::cal_stddev() {
    double devsum = 0.f;
    for (int i = 0; i < trial_times; ++i) {
        double diff = trial_opensites_num[i] - mean_val;
        devsum += diff * diff;
    }
    stddev_val = sqrt(devsum / (trial_times - 1));
}

void PercolationStates::cal_confidence() {
    conf_Lo = mean_val - 1.96 * stddev_val / sqrt(trial_times);
    conf_Hi = mean_val + 1.96 * stddev_val / sqrt(trial_times);
}

double PercolationStates::mean() {
    return mean_val;
}

double PercolationStates::stddev() {
    return stddev_val;
}

double PercolationStates::confidenceLo() {
    return conf_Lo;
}


double PercolationStates::confidenceHi(){
    return conf_Hi;
}