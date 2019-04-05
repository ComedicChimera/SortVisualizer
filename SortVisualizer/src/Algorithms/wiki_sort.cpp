#include "../sort.h"

#include <iostream>

namespace Sort {
	void reverse(SortArray &arr, int start, int end) {
		int oppNdx;
		for (int i = start; i < (end - start) / 2 + start; i++) {
			oppNdx = end - i - 1;

			arr.swap(i, oppNdx);
			arr.draw(2, i, oppNdx);
				
		}
	}

	void rotate(SortArray &arr, int start, int end, int amount) {
		reverse(arr, start, end);
		reverse(arr, start, start + amount);
		reverse(arr, start + amount, end);
	}

	int floorPowerOf2(int size) {
		int k = 1;

		while (k > 0 && k < size) {
			k <<= 1;
		}

		return (unsigned int)k >> 1;
	}

	void blockSwap(SortArray &arr, int a, int b, int count) {
		for (int i = 0; i < count; i++) {
			arr.swap(i + a, i + b);

			arr.draw(i + a, i + b);
		}
	}

	int linearSearch(SortArray &arr, int start, int end, int value) {
		for (int i = start; i < end; i++) {
			if (arr[i] == value)
				return i;
		}

		return -1;
	}

	int binaryFirst(SortArray &arr, int start, int end, int value) {
		int mid, trueEnd = end;

		while (start < end) {
			mid = (end - start) / 2 + start;

			if (arr[mid] < value)
				start = mid + 1;
			else
				end = mid;
		}

		if (start == trueEnd && arr[start] < value)
			start += 1;

		return start;
	}

	int binaryLast(SortArray &arr, int start, int end, int value) {
		int mid, trueEnd = end;

		while (start < end) {
			mid = (end - start) / 2 + start;

			if (arr[mid] <= value)
				start = mid + 1;
			else
				end = mid;
		}

		if (start == trueEnd && arr[start] <= value)
			start += 1;

		return start;
	}

	int minOf2(int a, int b) {
		return a < b ? a : b;
	}

	void wikiSort(SortArray &arr) {
		int bound;
		for (int m = 0; m < arr.size; m += 16) {
			bound = minOf2(m + 16, arr.size);

			insertionSort(arr, m, bound);
		}

		int pow2 = floorPowerOf2(arr.size);

		if (pow2 > 16) {
			int start, end, mid;

			for (int len = 32; len < pow2; len *= 2) {
				for (int section = 0; section < arr.size; section += len) {
					// main sorting stuff goes here


				}
			}
		}
	}
}