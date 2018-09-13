#pragma once

#include "sort_array.h"

#include <vector>

namespace Sort {
	int min(SortArray&, int);

	void bubbleSort(SortArray&);

	void selectionSort(SortArray&);

	void radixSort(SortArray&);

	void quickSort(SortArray&);

	void insertionSort(SortArray&);

	void mergeSort(SortArray&);

	void pancakeSort(SortArray&);

	void cycleSort(SortArray&);
}
