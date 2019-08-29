#include <iostream>
#include <vector>


#include "IntersectionTwoSets.h"

using std::vector;
using std::cout;

const int Arr_Len = 20;

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

    cout << "Array a/b contains " << Arr_Len << " elements each, where "
         << 2 * Arr_Len - insect.size() << " are the same.\n";



    return 0;
}