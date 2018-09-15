#include "../sort.h"

namespace Sort {
	void rippleSort(SortArray &arr) {
		int offset = 0;

		while (offset < arr.size / 2) {
			for (int i = offset; i < arr.size - offset - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					arr.swap(i, i + 1);

					arr.draw(2, i, i + 1);
				}
			}

			for (int i = arr.size - offset - 1; i > offset; i--) {
				if (arr[i] < arr[i - 1]) {
					arr.swap(i, i - 1);

					arr.draw(2, i, i - 1);
				}
			}

			offset++;
		}

		arr.draw(0);
	}
}