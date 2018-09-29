#include "../sort.h"

#include <iostream>

namespace Sort {
	constexpr int RUN = 32;

	void insertionSort(SortArray &arr, int l, int h) {
		for (int i = l + 1; i < h; i++) {
			if (arr[i] < arr[i - 1]) {
				int temp = arr[i];

				int j = i - 1;
				while (j >= l && arr[j] > temp) {
					arr[j + 1] = arr[j];
					arr.draw(2, j + 1, j);

					j--;
				}

				arr[j + 1] = temp;
				arr.draw(1, j + 1);
			}
		}
	}

	void timSort(SortArray &arr) {
		for (int i = 0; i < arr.size; i += RUN) {
			insertionSort(arr, i, arr.size < i + RUN ? arr.size : i + RUN);
		}

		for (int s = RUN; s < arr.size; s *= 2) {
			for (int l = 0; l < arr.size; l += s * 2) {
				int m = l + s;
				int h = l + 2 * s < arr.size ? l + 2 * s : arr.size;

				merge(arr, l, h, m);
			}
		}

		arr.draw(0);
	}
}