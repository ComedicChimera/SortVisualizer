#include "../sort.h"

#include <cmath>

namespace Sort {
	int getDigit(int num, int power, int base) {
		return num / (int)floor(pow(base, power)) % base;
	}

	void radixLSDSort(SortArray &arr, int base) {
		int maxVal = arr.size - 1;
		int it = 0;

		while (pow(base, it) < maxVal) {
			std::vector<int> *buckets = new std::vector<int>[base];

			for (int i = 0; i < arr.size; i++)
				buckets[getDigit(arr[i], it, base)].push_back(arr[i]);

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
			buckets[getDigit(arr[i], power, 10)].push_back(arr[i]);
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

	void inPlaceRadixLSDSort(SortArray &arr) {
		int pos = 0, mx = arr.size - 1;
		
		std::vector<int> buckets(9);

		int digit;
		for (int it = 0; pow(10, it) < mx; it++) {
			for (int i = 0; i < buckets.size(); i++)
				buckets[i] = arr.size - 1;

			for (int i = 0; i < arr.size; i++) {
				digit = getDigit(arr[pos], it, 10);

				if (digit == 0) {
					pos++;
					arr.draw(1, pos);
				}
				else {
					arr.drawVector(buckets);

					int end = buckets[digit - 1];

					if (end - pos > 0) {
						for (int j = pos; j < end; j++) 
							arr.swap(j, j + 1);
					}
					else {
						for (int j = pos; j > end; j--)
							arr.swap(j, j - 1);
					}

					for (int j = digit - 1; j > 0; j--)
						buckets[j - 1]--;
				}
			}

			pos = 0;
		}

		arr.draw(0);
	}
}