#include "../sort.h"

namespace Sort {
	void insertionSort(SortArray &arr) {
		auto insert = [&](int a, int b) {
			int value = arr[a];

			int previousValue = arr[b];
			for (int i = b + 1; i <= a; i++) {
				int newValue = arr[i];
				arr[i] = previousValue;
				previousValue = newValue;
			}

			arr[b] = value;

			arr.draw(2, a, b);
		};

		for (int i = 0; i < arr.size - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				if (i == 0) {
					arr.swap(0, 1);
					arr.draw(2, 0, 1);
					continue;
				}


				for (int j = i - 1; j >= 0; j--) {
					if (arr[i + 1] > arr[j]) {
						insert(i + 1, j + 1);
						break;
					} 
					else if (j == 0)
						insert(i + 1, 0);
				}
			}
		}

		arr.draw(0);
	}
}