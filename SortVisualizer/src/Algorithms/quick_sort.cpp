#include "../sort.h"

namespace Sort {
	void quickSort(SortArray&, int, int);

	void quickSort(SortArray &arr) {
		quickSort(arr, 0, arr.size - 1);

		arr.draw(0);
	}

	int partition(SortArray &arr, int low, int high) {
		int i = low, pivot = arr[high];

		for (int j = low; j < high; j++) {
			if (arr[j] <= pivot) {

				arr.swap(i, j);
				arr.draw(2, i, j);

				i++;
			}
		}

		arr.swap(i, high);

		return i;
	}

	void quickSort(SortArray &arr, int low, int high) {
		if (low < high) {
			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
}