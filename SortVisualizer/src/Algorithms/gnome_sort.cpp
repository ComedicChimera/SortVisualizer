#include "../sort.h"

namespace Sort {
	void gnomeSort(SortArray &arr) {
		int position = 0;

		while (position < arr.size) {
			if (position > 0 && arr[position - 1] > arr[position]) {
				arr.swap(position - 1, position);
				arr.draw(1, position - 1, position);

				position--;
			}
			else
				position++;
		}

		arr.draw(0);
	}
}