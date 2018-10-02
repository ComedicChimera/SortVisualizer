#include "../sort.h"

#include <cmath>
#include <iostream>

namespace Sort {
	void radixLSDSort(SortArray &arr, int base) {
		int maxVal = arr.size - 1;
		int it = 0;

		while (pow(base, it) < maxVal) {
			std::vector<int> *buckets = new std::vector<int>[base];

			for (int i = 0; i < arr.size; i++)
				buckets[arr[i] / (int)floor(pow(base, it)) % base].push_back(arr[i]);

			int maxBucketSize = 0;

			for (int i = 0; i < base; i++) {
				if (buckets[i].size() > maxBucketSize)
					maxBucketSize = buckets[i].size();
			}

			int offset = 0, ndx = 0, sOffset = 0;
			std::vector<int> marked;

			while (offset < maxBucketSize) {
				for (int j = 0; j < base; j++) {
					if (offset >= buckets[j].size())
						continue;

					ndx = sOffset + offset;

					arr[ndx] = buckets[j][offset];

					marked.push_back(ndx);

					sOffset += buckets[j].size();
				}

				arr.drawVector(marked);
				marked.clear();

				sOffset = 0;
				offset++;
			}

			it++;
		}

		arr.draw(0);
	}

	void radixMSDSort(SortArray &arr, int power, int lo, int hi) {
		if (power < 0 || lo >= hi)
			return;

		std::vector<int> buckets[10];

		for (int i = lo; i < hi; i++) {
			buckets[arr[i] / (int)floor(pow(10, power)) % 10].push_back(arr[i]);
		}

		int index = lo;
		for (auto& bucket : buckets) {
			for (int item : bucket) {
				arr[index] = item;
				arr.draw(1, index);

				index++;
			}

			radixMSDSort(arr, power - 1, index - bucket.size(), index);
		}
	}

	void radixMSDSort(SortArray &arr) {
		int max = 0;

		for (int i = 0; i < arr.size; i++) {
			if (arr[i] > max)
				max = arr[i];
		}

		int maxDigitCount = max > 9 ? (int)log10((double)max): 1;
		radixMSDSort(arr, maxDigitCount, 0, arr.size);

		arr.draw(0);
	}
}