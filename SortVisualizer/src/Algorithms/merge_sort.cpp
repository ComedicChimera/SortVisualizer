#include "../sort.h"

namespace Sort {
	void merge(SortArray &arr, int low, int high, int middle) {
		std::vector<int> sorted;

		int i = low, j = middle;
		
		while (i < middle && j < high) {
			if (arr[i] <= arr[j]) {
				sorted.push_back(arr[i]);
				i++;
			}
			else {
				sorted.push_back(arr[j]);
				j++;
			}
		}

		while (i < middle) {
			sorted.push_back(arr[i]);
			i++;
		}

		while (j < high) {
			sorted.push_back(arr[j]);
			j++;
		}

		for (int k = 0; k < sorted.size(); k++) {
			arr[k + low] = sorted[k];
			arr.draw(2, k + low);
		}
	}

	void mergeSort(SortArray &arr, int low, int high) {
		if (low < high - 1) {
			int middle = low + (high - low) / 2;

			mergeSort(arr, low, middle);
			mergeSort(arr, middle, high);

			merge(arr, low, high, middle);
		}
	}

	void mergeSort(SortArray &arr) {
		mergeSort(arr, 0, arr.size);

		arr.draw(0);
	}
}