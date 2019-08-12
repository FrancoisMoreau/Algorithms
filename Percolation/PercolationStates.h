//
// Created by brayden on 2019-08-12.
//

#ifndef PERCOLATION_PERCOLATIONSTATES_H
#define PERCOLATION_PERCOLATIONSTATES_H

#include "Percolation.h"

class PercolationStates {
public:
    PercolationStates(int n, int trials);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();

private:
    int gride_size;
    int trial_times;
    vector<double> trial_opensites_num;
    void cal_mean();
    void cal_stddev();
    void cal_confidence();
    double mean_val = 0.0;
    double stddev_val = 0.0;
    double conf_Lo = 0.0;
    double conf_Hi = 0.0;
};


#endif //PERCOLATION_PERCOLATIONSTATES_H
