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

	void stoogeSort(SortArray&);

	void gnomeSort(SortArray&);

	void rippleSort(SortArray&);

	void heapSort(SortArray&);

	void shellSort(SortArray&);

	void bitonicSort(SortArray&);

	void gravitySort(SortArray&);

	bool sort(sf::RenderWindow &window, const std::string&, int, int, bool);
}
