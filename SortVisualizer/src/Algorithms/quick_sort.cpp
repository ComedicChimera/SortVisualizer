#include "../sort.h"

namespace Sort {
	void quickSort(SortArray&, int, int);

	void quickSort(SortArray &arr) {
		quickSort(arr, 0, arr.size - 1);

		arr.draw(0);
	}

	void quickSort(SortArray &arr, int low, int high) {
		auto partition = [&]() -> int {
			int i = low, pivot = arr[high];

			for (int j = low; j < high; j++) {
				if (arr[j] <= pivot) {

					arr.swap(i, j);
					i++;

					arr.draw(i, j);
				}
			}

			arr.swap(i, high);

			return i;
		};

		if (low < high) {
			int pi = partition();

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
}