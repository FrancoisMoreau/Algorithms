#include <iostream>
#include <string>
#include <random>

#include "RedBlackST.h"

using std::string;
using std::cout;
using std::endl;
typedef unsigned Score;

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

int main() {
    int height = 0;
    for (int m = 0; m < 10; ++m) {
        RedBlackST<string, Score> grades;
        std::vector<string> names;
        for (int i = 0; i < 1024; ++i) {
            string name = gen_rand_name();
            names.push_back(name);
            grades.put(name, get_random(60, 100));
        }
//    for (int i = 10; i < 20; ++i) {
//        cout << names[i] << " : " << grades.get(names[i]) << endl;
//    }
        height += grades.height();
    }
    cout << "Height: " << height / 10 << endl;

    return 0;
}