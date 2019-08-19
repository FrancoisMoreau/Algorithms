#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;

int binarysearch(vector<int> &vec, int k, int lo, int hi) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (k < vec[mid]) hi = mid - 1;
        else if (k > vec[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}
int binarysearch_reversed(vector<int> &vec, int k, int lo, int hi) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (k > vec[mid]) hi = mid - 1;
        else if (k < vec[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

bool bitonicsearch(vector<int> vec, int k) {
    int lo = 0, hi = vec.size() - 1, mid = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (vec[mid - 1] < vec[mid]) {
            lo = mid + 1;
        } else if (vec[mid + 1] < vec[mid]) {
            hi = mid - 1;
        } else {
            break;
        }
    }
    if (binarysearch(vec, k, 0, mid) != -1 || binarysearch_reversed(vec, k, mid, vec.size() - 1) != -1)
        return true;
    return false;
}

int main() {
//    vector<int> a{1, 3, 5, 8, 10, 13};
//    cout << binarysearch(a, 11) << "\n";

    vector<int> a{3, 5, 8, 10, 13, 1};
    cout << "res: " << bitonicsearch(a, 1) << std::endl;
    return 0;
}