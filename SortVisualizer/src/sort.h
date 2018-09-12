#pragma once

#include "sort_array.h"

#include <vector>

namespace Sort {
	int min(SortArray &arr, int start = 0) {
		int min = arr.size + 1;
		int ndx = 0;

		for (int i = start; i < arr.size; i++) {
			if (arr[i] < min) {
				min = arr[i];
				ndx = i;
			}

			arr.draw(1, i);
		}

		return ndx;
	}

	void bubbleSort(SortArray &arr) {
		for (int max = arr.size - 2; max > 1; max--) {
			for (int i = 0; i < max; i++) {
				if (arr[i] > arr[i + 1]) {
					arr.swap(i, i + 1);

					arr.draw(2, i, i + 1);
				}
			}
		}

		arr.draw(0);
	}

	void selectionSort(SortArray &arr) {
		for (int i = 0; i < arr.size; i++) {
			int ndx = min(arr, i);

			arr.swap(i, ndx);
			arr.draw(2, i, ndx);
		}

		arr.draw(0);
	}

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

	void _quickSort(SortArray&, int, int);

	void quickSort(SortArray &arr) {
		_quickSort(arr, 0, arr.size - 1);

		arr.draw(0);
	}

	void _quickSort(SortArray &arr, int low, int high) {
		auto partition = [&]() -> int {
			int i = low, pivot = arr[high];

			for (int j = low; j < high; j++) {
				if (arr[j] <= pivot) {

					arr.swap(i, j);
					i++;

					arr.draw(i, j);
				}
			}

			arr.swap(i, high);

			arr.draw(i, high);

			return i;
		};

		if (low < high) {
			int pi = partition();

			_quickSort(arr, low, pi - 1);
			_quickSort(arr, pi + 1, high);
		}
	}
}
