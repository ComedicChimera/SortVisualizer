#include "../sort.h"

namespace Sort {
	void shellSort(SortArray &arr) {
		int gaps[9] = { 1, 4, 10, 23, 57, 132, 301, 701 };
		std::vector<int> marks;

		for (int g = 8; g > -1; g--) {
			int gap = gaps[g];

			if (gap >= arr.size)
				continue;

			for (int i = gap; i < arr.size; i++) {
				int temp = arr[i];

				int j = i;

				while (j >= gap && arr[j - gap] > temp) {
					arr[j] = arr[j - gap];
					j -= gap;

					marks.push_back(j);
				}

				arr[j] = temp;

				marks.push_back(j);

				arr.drawVector(marks);
				marks.clear();
			}
		}

		arr.draw(0);
	}
}
