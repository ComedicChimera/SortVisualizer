#include "../sort.h"

namespace Sort {
	void inPlaceMerge(SortArray &arr, int start, int mid, int end) {
		int i = start, j = mid;

		while (i < mid && j < end) {
			if (arr[i] > arr[j])
			{
				int temp = arr[i];

				arr[i] = arr[j];
				arr.draw(2, i, j);
				
				for (int ndx = j; ndx > i + 1; ndx--) 
					arr[ndx] = arr[ndx - 1];		

				arr[i + 1] = temp;
				arr.draw(1, i + 1);

				j++;
				mid++;
			}

			i++;
		}
	}

	void inPlaceMergeSort(SortArray &arr, int start, int end) {
		if (start < end - 1) {
			int mid = (end - start) / 2 + start;

			inPlaceMergeSort(arr, start, mid);
			inPlaceMergeSort(arr, mid, end);

			inPlaceMerge(arr, start, mid, end);
		}
	}

	void inPlaceMergeSort(SortArray &arr) {
		inPlaceMergeSort(arr, 0, arr.size);

		arr.draw(0);
	}
}