#include <iostream>
#include <random>
#include <vector>


#include "NutsBolts.h"

using std::vector;
using std::cout;
using std::endl;

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

template <typename T>
void Knuth_shuffle(std::vector<T> &vec) {
    int N = vec.size();
    for (int i = 0; i < N; ++i) {
        std::swap(vec[i], vec[get_random(i)]);
    }
}

int main() {
    vector<int> nuts;
    vector<char> bolts;
    vector<size_t> position;
    for (int i = 0; i != 26; ++i) {
        nuts.push_back(i);
        bolts.push_back('a' + i);
        position.push_back(i);
    }

    //shuffle the nuts and bolts;
    Knuth_shuffle(nuts);
    Knuth_shuffle(bolts);

    for (auto &i : nuts)
        cout << i << " ";
    cout << endl;

    for (auto &j : bolts)
        cout << j << " ";
    cout << endl;


    cout << "after matching: \n";
    NutsBolts(nuts, bolts, position);
    for (auto &i : nuts)
        cout << i << " ";
    cout << endl;

    for (auto &j : bolts)
        cout << j << " ";
    cout << endl;
    for (auto &k : position)
        cout << k << " ";
    cout << endl;






    return 0;
}