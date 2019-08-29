#include <iostream>
#include <vector>
#include <random>

#include "IntersectionTwoSets.h"
#include "Permutation.h"
#include "DN_Flag.h"

using std::vector;
using std::cout;

const int Arr_Len = 20;

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}


int main() {
    vector<Point2D> plhs, prhs;
    for (int i = 0; i < Arr_Len; ++i) {
        plhs.emplace_back(i/2, i);
        prhs.emplace_back((i + 1)/ 2, i );
    }

    IntersectionTwoSets insect;
    for (int i = 0; i < Arr_Len; ++i) {
        insect.push_back(plhs[i]);
        insect.push_back(prhs[i]);
    }

    cout << "Intersection of two sets: \n";
    cout << "Array a/b contains " << Arr_Len << " elements each, where "
         << 2 * Arr_Len - insect.size() << " are the same.\n";

    cout << "\n\nPermutation: \n";
    vector<int> vec_a, vec_b;
    for (auto i = 0; i < 50; ++i) {
        vec_a.push_back(i);
        vec_b.push_back(49 - i);
    }
    cout << IsPermutation(vec_a, vec_b) << std::endl;


    cout << "\n\nDutch National Flag: \n";
    std::vector<int> flag_vec;
    flag_vec.reserve(10);
    for (int i = 0; i < 10; ++i) {
        flag_vec.push_back(get_random(2));
    }
    std::vector<int> stlsort_vec;

    DN_Flag(flag_vec);
    for (auto &i : flag_vec)
        cout << i << " ";
    cout << std::endl;



    return 0;
}