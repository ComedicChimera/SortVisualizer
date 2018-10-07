#include "../sort.h"

namespace Sort {
	void dutchPartition(SortArray &arr, int lo, int hi, int &i, int &j) {
		if (hi - lo <= 1) {
			if (arr[lo] > arr[hi]) {
				arr.swap(lo, hi);
				arr.draw(2, lo, hi);
			}
			
			i = lo;
			j = hi;
		}
		else {
			int mid = lo;
			int pivot = arr[hi];

			while (mid <= hi) {
				if (arr[mid] < pivot) {
					arr.swap(lo, mid);
					arr.draw(2, lo++, mid++);
				}
				else if (arr[mid] == pivot)
					mid++;
				else if (arr[mid] > pivot) {
					arr.swap(mid, hi);
					arr.draw(2, mid, hi--);
				}
			}

			i = lo - 1;
			j = mid;
		}
	}

	void dutchFlagSort(SortArray &arr, int lo, int hi) {
		if (lo < hi) {
			int i, j;

			dutchPartition(arr, lo, hi, i, j);

			dutchFlagSort(arr, lo, i);
			dutchFlagSort(arr, j, hi);
		}
	}

	void dutchFlagSort(SortArray &arr) {
		dutchFlagSort(arr, 0, arr.size - 1);

		arr.draw(0);
	}
}