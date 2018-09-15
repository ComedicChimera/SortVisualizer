#include "../sort.h"

namespace Sort {
	int min(SortArray &arr, int start = 0) {
		int min = arr.size + 1;
		int ndx = 0;

		for (int i = start; i < arr.size; i++) {
			if (arr[i] < min) {
				min = arr[i];
				ndx = i;
			}

			arr.draw(1, i);
		}

		return ndx;
	}

	void bubbleSort(SortArray &arr) {
		for (int max = arr.size - 2; max > 1; max--) {
			for (int i = 0; i < max; i++) {
				if (arr[i] > arr[i + 1]) {
					arr.swap(i, i + 1);

					arr.draw(2, i, i + 1);
				}
			}
		}

		arr.draw(0);
	}

	void selectionSort(SortArray &arr) {
		for (int i = 0; i < arr.size; i++) {
			int ndx = min(arr, i);

			arr.swap(i, ndx);
			arr.draw(2, i, ndx);
		}

		arr.draw(0);
	}

	void pancakeSort(SortArray &arr) {
		auto reverse = [&](int start) {
			for (int i = 0; i < (arr.size - start) / 2; i++) {
				arr.swap(i + start, arr.size - (i + 1));

				arr.draw(2, i + start, arr.size - (i + 1));
			}
		};

		for (int i = 0; i < arr.size; i++) {
			int minNdx = min(arr, i);
			reverse(minNdx);
			reverse(i);
		}

		arr.draw(0);
	}
}