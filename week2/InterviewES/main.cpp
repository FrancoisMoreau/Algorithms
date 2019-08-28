#include <iostream>
#include <vector>


#include "IntersectionTwoSets.h"

using std::vector;
using std::cout;

int main() {
    vector<Point2D> plhs, prhs;
    for (int i = 0; i < 10; ++i) {
        plhs.emplace_back(i/2, i/ 2);
        prhs.emplace_back((i + 1)/ 2, (i + 1) / 2);
    }

    IntersectionTwoSets insect;
    for (int i = 0; i < 2; ++i) {
        insect.push_back(plhs[i]);
//        insect.push_back(prhs[i]);
    }

    cout << "Set size: " << insect.size() << "\n";




    return 0;
}