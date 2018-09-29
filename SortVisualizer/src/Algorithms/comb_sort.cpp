#include "../sort.h"

namespace Sort {
	int nextGap(int gap) {
		gap = 10 * gap / 13;

		if (gap < 1) return 1;
		
		return gap;
	}

	void combSort(SortArray &arr) {
		int gap = arr.size;
		bool swapped = true;

		while (gap != 1 || swapped == true) {
			gap = nextGap(gap);

			swapped = false;

			for (int i = 0; i < arr.size - gap; i++) {
				if (arr[i] > arr[i + gap]) {
					arr.swap(i, i + gap);
					arr.draw(2, i, i + gap);

					if (!swapped)
						swapped = true;
				}
			}
		}
	}
}