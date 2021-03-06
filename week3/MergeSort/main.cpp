#include <iostream>
#include <random>
#include <chrono>

#include "MergeSort.h"
#include "FastMergeSort.h"

const int Arr_Len = 10000;

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

int get_random(int n) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n);
    int dice_roll = distribution(rng);
    return dice_roll;
}

int main() {
	std::vector<int> stl_vector;
	stl_vector.reserve(Arr_Len);
	for (size_t i = 0; i != Arr_Len; ++i) {
		stl_vector.push_back(get_random(Arr_Len));
	}
	std::vector<int> merge_vector(stl_vector), fast_merge_vec(stl_vector);
	std::vector<int> bumerge_vector(stl_vector);

	TimeVar t1 = timeNow();
	std::sort(stl_vector.begin(), stl_vector.end());
	TimeVar t2 = timeNow();
	
	std::cout << "STL sort: " << duration(t2 - t1) << " ms \n";

	t1 = timeNow();
	MergeSort(merge_vector);
	t2 = timeNow();
	std::cout << "MergeSort: " << duration(t2 - t1) << " ms \n";


    t1 = timeNow();
    FastMergeSort(fast_merge_vec);
    t2 = timeNow();
    std::cout << "Fast MergeSort: " << duration(t2 - t1) << " ms \n";

    t1 = timeNow();
    BUMergeSort(bumerge_vector);
    t2 = timeNow();
    std::cout << "Bottom Up Merge Sort: " << duration(t2 - t1) << " ms \n";

	for (size_t i = 0; i != Arr_Len; ++i) {
		if (stl_vector[i] != merge_vector[i]) {
			std::cout << "not same at " << i << " : " << stl_vector[i] << " vs " << merge_vector[i] << " \n";
		}
		if (stl_vector[i] != fast_merge_vec[i])
		    std::cout << "not same!\n";
		if (stl_vector[i] != bumerge_vector[i])
		    std::cout << "not same in bu\n";
	}	

    return 0;
}