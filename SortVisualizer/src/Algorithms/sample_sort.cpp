#include "../sort.h"

#include <iostream>
#include <vector>

namespace Sort {
	// implementation standard sample sort (super scalar not used here)
	// quicksort used as secondary sort here
	void sampleSort(SortArray &arr, int lo, int hi, int p) {
		// p is our cutoff for sizes
		if ((hi - lo) < p) {
			arr.slice(lo, hi);
			quickSort(arr);
			arr.restore();

			return;
		}

		std::vector<int> splitters;

		for (int i = 0; i < p; i++) {
			splitters.push_back(arr[lo + i]);
		}

		// std sort on splitters vector
		std::sort(splitters.begin(), splitters.end());

		// index in splitters = index in buckets
		std::vector<int> *buckets = new std::vector<int>[p];

		// add splitters to beginning of buckets
		for (int i = 0; i < p; i++) {
			buckets[i].push_back(splitters[i]);
		}

		int si;
		for (int i = lo + p; i < hi; i++) {
			for (int j = 0; j < p; j++) {
				// smaller than splitters
				if (j == 0 && arr[i] < splitters[j]) {
					si = j;
					break;
				}
				else if (j == p - 1) {
					si = j;
				}
				else if (splitters[j] < arr[i] && arr[i] < splitters[j + 1]) {
					si = j;
					break;
				}
			}

			buckets[si].push_back(arr[i]);
		}

		int offset = lo;
		for (int i = 0; i < p; i++) {
			for (int &item : buckets[i]) {
				arr[offset] = item;
				arr.draw(1, offset);

				offset++;
			}
		}

		offset = lo;

		for (int i = 0; i < p; i++) {
			sampleSort(arr, offset, offset + buckets[i].size(), p);

			offset += buckets[i].size();
		}
	}

	void sampleSort(SortArray &arr) {
		// since this is not done in parallel, I can pick an arbitrary value
		int p = log10(arr.size) * 3;

		sampleSort(arr, 0, arr.size, p);

		arr.draw(0);
	}
}