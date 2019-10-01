//
// Created by brayden on 2019-09-30.
//

#include "RangeSearch.h"

using std::string;

int get_random(int lo, int hi) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(lo, hi);
    int dice_roll = distribution(rng);
    return dice_roll;
}

string gen_rand_name() {
    string name;
    name += toupper('a' + get_random(0, 25));
    for (int i = 0; i < 5; ++i) {
        name += 'a' + get_random(0, 25);
    }
    return name;
}