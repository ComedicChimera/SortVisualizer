#include "../sort.h"

#include <iostream>

namespace Sort {
	void strandSort(SortArray &arr) {
		int end = arr.size - 1;

		while (end > 0) {
			arr.swap(0, end);
			
			int endSize = 1;
			for (int i = 0; i < end; i++) {
				if (arr[i] > arr[end]) {
					int temp = arr[i];

					for (int j = i; j < end; j++) {
						arr[j] = arr[j + 1];

						arr.draw(2, j, j + 1);
					}

					arr[end] = temp;

					arr.draw(1, end);

					endSize += 1;
				}
			}

			if (end != arr.size - 1) 
				merge(arr, end - endSize + 1, arr.size, end + 1);

			end -= endSize;
		}

		if (arr[0] > arr[1])
			merge(arr, 0, arr.size, 1);

		arr.draw(0);
	}
}