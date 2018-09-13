#include "../sort.h"

namespace Sort {
	void radixSort(SortArray &arr) {
		int maxVal = arr.size - 1;
		int it = 0;

		while (pow(10, it) < maxVal) {
			std::vector<int> buckets[10];

			for (int i = 0; i < arr.size; i++)
				buckets[arr[i] / (int)floor(pow(10, it)) % 10].push_back(arr[i]);


			int pos = 0;

			for (int i = 0; i < 10; i++) {
				for (auto item : buckets[i]) {
					arr[pos] = item;
					pos++;

					arr.draw(1, pos);
				}
			}

			arr.draw(0);

			it++;
		}
	}
}