#include "../sort.h"

#include <cmath>
#include <iostream>

namespace Sort {
	void stoogeSort(SortArray &arr, int begin, int end) {
		if (begin >= end)
			return;

		if (arr[begin] > arr[end]) {
			arr.swap(begin, end);
			arr.draw(2, begin, end);
		}

		if (end - begin + 1 > 2) {
			int t = floor((end - begin + 1) / 3);

			stoogeSort(arr, begin, end - t);
			stoogeSort(arr, begin + t, end);

			stoogeSort(arr, begin, end - t);
		}
	}

	void stoogeSort(SortArray &arr) {
		stoogeSort(arr, 0, arr.size - 1);
		arr.draw(0);
	}
}