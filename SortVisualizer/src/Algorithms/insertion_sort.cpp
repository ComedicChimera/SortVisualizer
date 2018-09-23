#include "../sort.h"

namespace Sort {
	void insertionSort(SortArray &arr) {
		for (int i = 1; i < arr.size; i++) {
			if (arr[i] < arr[i - 1]) {
				int temp = arr[i];

				int j = i - 1;
				while (j >= 0 && arr[j] > temp) {
					arr[j + 1] = arr[j];
					arr.draw(2, j + 1, j);

					j--;
				}

				arr[j + 1] = temp;
				arr.draw(1, j + 1);
			}
		}

		arr.draw(0);
	}
}