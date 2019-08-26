#include <iostream>
#include <random>
#include <chrono>
#include "QuickSort.h"
#include "FastQuickSort.h"

#include "QuickSelect.h"
#include "ThreeWayPartition.h"


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
	std::vector<int> quick_vec(stl_vector);
	std::vector<int> fast_quick_vec(stl_vector);

	TimeVar t1 = timeNow();
	std::sort(stl_vector.begin(), stl_vector.end());
	TimeVar t2 = timeNow();
	
	std::cout << "STL sort: " << duration(t2 - t1) << " ms \n";

	t1 = timeNow();
	QuickSort(quick_vec);
	t2 = timeNow();
	std::cout << "QuickSort: " << duration(t2 - t1) << " ms \n";


    t1 = timeNow();
    FastQuickSort(fast_quick_vec);
    t2 = timeNow();
    std::cout << "Fast QuickSort: " << duration(t2 - t1) << " ms \n";

	for (size_t i = 0; i != Arr_Len; ++i) {
		if (stl_vector[i] != quick_vec[i]) {
			std::cout << "not same at " << i << " : " << stl_vector[i] << " vs " << quick_vec[i] << " \n";
		}
		if (stl_vector[i] != fast_quick_vec[i])
		    std::cout << "not same!\n";
	}

	std::vector<int> select_vec;
	for (auto i = 0; i < 10; ++i) {
	    select_vec.push_back(get_random(120));
	}
	std::cout << "\nQuick Select Res of 3: " << QuickSelect(select_vec, 3) << std::endl;
	std::sort(select_vec.begin(), select_vec.end());
	for (auto &i : select_vec)
	    std::cout << i << " ";
	printf("\n");

	printf("\n\n-------------------------------------\n");
	printf("Three way quick sort: 10 keys \n");
	std::vector<int> threeway_vec;
	for (auto i = 0; i < Arr_Len; ++i) {
	    threeway_vec.push_back(get_random(10));
	}

    std::vector<int> fastquick_3way(threeway_vec);
    stl_vector = threeway_vec;


    t1 = timeNow();
    ThreeWayQuickSort(threeway_vec);
    t2 = timeNow();
    std::cout << "Three-Way Quick Partition: " << duration(t2 - t1) << " ms \n";

	t1 = timeNow();
	FastQuickSort(fastquick_3way);
	t2 = timeNow();
	std::cout << "Fast Quick for 3 way: " << duration(t2 - t1) << " ms \n";

	t1 = timeNow();
	std::sort(stl_vector.begin(), stl_vector.end());
	t2 = timeNow();
	std::cout << "STL Sort for 3 way: " << duration(t2 - t1) << " ms \n";

	for (int i = 0; i != Arr_Len; ++i) {
	    if (threeway_vec[i] != stl_vector[i] || fastquick_3way[i] != stl_vector[i])
	        std::cout << "not same in 3 way\n";
	}

    return 0;
}