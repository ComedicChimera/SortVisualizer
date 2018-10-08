#include "../sort.h"

#include <iostream>

namespace Sort {
	void flashSort(SortArray &arr) {
		// min variable not needed since in this example it is always 0
		int max = arr.size - 1, m = arr.size / 20;

		int *l = new int[m];
		memset(l, 0, m * sizeof(int));

		int j = 0, k;

		double c1 = (m - 1.0) / max;

		for (int i = 0; i < arr.size; i++) {
			k = floor(c1 * arr[i]);

			l[k]++;

			arr.draw(1, i);
		}

		for (int i = 1; i < m; i++) {
			l[i] += l[i - 1];
		}

		int hold = max, nMove = 0;

		// swap max val
		for (int i = 0; i < arr.size; i++) {
			if (arr[i] == max) {
				arr.swap(i, 0);
				arr.draw(2, i, 0);

				break;
			}
		}

		int flash;
		k = m - 1;

		while (nMove < arr.size - 1) {
			while (j > l[k] - 1) {
				j++;
				k = floor(c1 * arr[j]);
			}

			flash = arr[j];

			while (!(j == l[k])) {
				k = floor(c1 * flash);

				hold = arr[l[k] - 1];
				arr[l[k] - 1] = flash;

				arr.draw(2, l[k] - 1, arr[j]);

				flash = hold;

				l[k]--;
				nMove++;
			}
		}

		insertionSort(arr);

		arr.draw(0);
	}
}