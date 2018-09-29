#include "../sort.h"

namespace Sort {
	void heapify(SortArray &arr, int heapSize, int i) {
		int l = 2 * i + 1;
		int r = l + 1;

		int largest = i;

		if (l < heapSize && arr[i] < arr[l])
			largest = l;

		if (r < heapSize && arr[largest] < arr[r])
			largest = r;

		if (i != largest) {
			arr.swap(i, largest);

			arr.draw(2, i, largest);

			heapify(arr, heapSize, largest);
		}
	}

	void heapSort(SortArray &arr) {
		int heapSize = arr.size;

		for (int i = heapSize; i > -1; i--) 
			heapify(arr, heapSize, i);

		for (int i = heapSize - 1; i > -1; i--) {
			arr.swap(i, 0);

			arr.draw(2, i, 0);

			heapify(arr, i, 0);
		}

		arr.draw(0);
	}

}