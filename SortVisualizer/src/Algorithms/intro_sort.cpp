#include "../sort.h"

#include <iostream>

namespace Sort {
	void introSort(SortArray &arr, int l, int h, int maxDepth) {
		if (l < h) {
			if (h - l < 16) 
				insertionSort(arr, l, h);
			else {
				int pi = partition(arr, l, h - 1);

				if (maxDepth == 0) {
					arr.slice(l, h);
					heapSort(arr);
					arr.restore();
				}
				else {
					introSort(arr, l, pi, maxDepth - 1);
					introSort(arr, pi + 1, h, maxDepth - 1);
				}
			}
		}
	}

	void introSort(SortArray &arr) {
		int maxDepth = floor(log(arr.size)) * 2;
		introSort(arr, 0, arr.size, maxDepth);

		arr.draw(0);
	}
}