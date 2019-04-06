#include "../sort.h"

namespace Sort {
	void merge(SortArray &arr, int low, int high, int middle) {
		std::vector<int> sorted;

		int i = low, j = middle;
		
		while (i < middle && j < high) {
			if (arr[i] <= arr[j]) {
				sorted.push_back(arr[i]);
				i++;
			}
			else {
				sorted.push_back(arr[j]);
				j++;
			}
		}

		while (i < middle) {
			sorted.push_back(arr[i]);
			i++;
		}

		while (j < high) {
			sorted.push_back(arr[j]);
			j++;
		}

		for (int k = 0; k < sorted.size(); k++) {
			arr[k + low] = sorted[k];
			arr.draw(1, k + low);
		}
	}

	void mergeSort(SortArray &arr, int low, int high) {
		if (low < high - 1) {
			int middle = low + (high - low) / 2;

			mergeSort(arr, low, middle);
			mergeSort(arr, middle, high);

			merge(arr, low, high, middle);
		}
	}

	void mergeSort(SortArray &arr) {
		mergeSort(arr, 0, arr.size);

		arr.draw(0);
	}

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