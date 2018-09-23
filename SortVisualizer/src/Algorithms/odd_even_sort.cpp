#include "../sort.h"

namespace Sort {
	void oddEvenSort(SortArray &arr) {
		bool sorted = false;

		while (!sorted) {
			sorted = true;
			
			for (int i = 1; i < arr.size - 1; i += 2) {
				if (arr[i] > arr[i + 1]) {
					arr.swap(i, i + 1);
					arr.draw(2, i, i + 1);
					sorted = false;
				}
			}

			for (int i = 0; i < arr.size - 1; i += 2) {
				if (arr[i] > arr[i + 1]) {
					arr.swap(i, i + 1);
					arr.draw(2, i, i + 1);
					sorted = false;
				}
			}
		}

		arr.draw(0);
	}
}