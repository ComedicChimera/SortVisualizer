#include "../sort.h"

namespace Sort {
	int getPowerOf2(int n) {
		int k = 1;

		while (k > 0 && k < n) {
			k <<= 1;
		}

		return (unsigned int)k >> 1;
	}

	void bitonicMerge(SortArray &arr, int l, int n, bool dir) {
		if (n > 1) {
			int m = getPowerOf2(n);

			for (int i = l; i < l + n - m; i++) {
				if (dir == (arr[i] > arr[i + m])) {
					arr.swap(i, i + m);

					arr.draw(2, i, i + m);
				}
			}

			bitonicMerge(arr, l, m, dir);
			bitonicMerge(arr, l + m, n - m, dir);
		}
	}

	void bitonicSort(SortArray &arr, int l, int n, bool dir) {
		if (n > 1) {
			int m = n / 2;
			bitonicSort(arr, l, m, !dir);
			bitonicSort(arr, l + m, n - m, dir);
			bitonicMerge(arr, l, n, dir);
		}
	}

	void bitonicSort(SortArray &arr) {
		bitonicSort(arr, 0, arr.size, true);

		arr.draw(0);
	}
}