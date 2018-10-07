#pragma once

#include "sort_array.h"

#include <vector>
#include <string>

namespace Sort {
	int min(SortArray&, int);

	void bubbleSort(SortArray&);

	void selectionSort(SortArray&);

	void radixLSDSort(SortArray&, int);

	void radixMSDSort(SortArray&);

	void quickSort(SortArray&);

	void insertionSort(SortArray&);

	void mergeSort(SortArray&);

	void pancakeSort(SortArray&);

	void cycleSort(SortArray&);

	void stoogeSort(SortArray&);

	void gnomeSort(SortArray&);

	void rippleSort(SortArray&);

	void heapSort(SortArray&);

	void shellSort(SortArray&);

	void bitonicSort(SortArray&);

	void gravitySort(SortArray&);

	void timeSort(SortArray&);

	void oddEvenSort(SortArray&);

	void timSort(SortArray&);

	void introSort(SortArray&);

	void strandSort(SortArray&);

	void combSort(SortArray&);

	void treeSort(SortArray&);

	void cartesianTreeSort(SortArray&);

	bool sort(const std::string&, SortArray&);

	// util
	void merge(SortArray&, int, int, int);
	int partition(SortArray&, int, int);
	void insertionSort(SortArray&, int, int);
}
