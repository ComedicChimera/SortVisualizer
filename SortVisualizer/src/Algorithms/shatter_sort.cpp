#include "../sort.h"

namespace Sort {
	void shatterPartition(SortArray &arr, int shatters, int base) {
		std::vector<std::vector<int>> buckets(shatters);

		for (int i = 0; i < arr.size; i++) {
			buckets[arr[i] / base].push_back(arr[i]);
		}

		int pos = 0;

		for (auto &bucket : buckets) {
			for (int item : bucket) {
				arr[pos] = item;
				arr.draw(1, pos);

				pos++;
			}
		}
	}

	void shatterSort(SortArray &arr) {
		const int base = 10;

		int shatters = arr.size / base + 1;

		shatterPartition(arr, shatters, base);

		std::vector<int> temp(base);
		int arrPos;

		for (int sh = 0; sh < shatters; sh++) {
			for (int i = 0; i < base; i++) {
				if (sh * base + i >= arr.size)
					temp[i] = -1;
				else
					temp[i] = arr[sh * base + i];
			}

			for (int elem : temp) {
				arrPos = sh * base + elem % base;

				if (elem == -1 || arrPos >= arr.size)
					break;

				arr[arrPos] = elem;
				arr.draw(1, arrPos);
			}
		}

		arr.draw(0);
	}
}