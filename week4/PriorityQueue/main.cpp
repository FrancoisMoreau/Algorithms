#include <iostream>
#include <random>
#include "MaxPQ.h"

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}


int main() {
    MaxPQ maxpriq;

    for (int i = 0; i < 20; ++i) {
        maxpriq.insert(get_random(20));
    }
    for (int i = 0; i < 20; ++i) {
        std::cout << maxpriq.delMax() << " ";
    }

    return 0;
}