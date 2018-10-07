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
		}

		return ndx;
	}

	void bubbleSort(SortArray &arr) {
		for (int max = arr.size - 1; max > 0; max--) {
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

	void doubleSelectionSort(SortArray &arr) {
		int i = 0, j = arr.size - 1;

		int ndx, val = arr.size + 1;
		while (i < j) {
			for (int k = i; k <= j; k++) {
				if (arr[k] < val) {
					ndx = k;
					val = arr[k];
				}
			}

			arr.swap(ndx, i);
			arr.draw(2, ndx, i);

			i++;

			for (int k = j; k >= i; k--) {
				if (arr[k] > val) {
					ndx = k;
					val = arr[k];
				}
			}

			arr.swap(ndx, j);
			arr.draw(2, ndx, j);

			j--;
		}

		arr.draw(0);
	}
}