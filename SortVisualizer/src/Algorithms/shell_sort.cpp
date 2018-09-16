#include "../sort.h"

namespace Sort {
	void shellSort(SortArray &arr) {
		int gaps[9] = { 1, 4, 10, 23, 57, 132, 301, 701 };

		for (int g = 8; g > -1; g--) {
			int gap = gaps[g];

			for (int i = gap; i < arr.size; i++) {
				int temp = arr[i];

				int j = i;

				while (j >= gap && arr[j - gap] > temp) {
					arr[j] = arr[j - gap];
					j -= gap;

					arr.draw(2, j, j - gap);
				}

				arr[j] = temp;

				arr.draw(1, j);
			}
		}
	}
}
