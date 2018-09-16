#include "sort.h"

#include <algorithm>

namespace Sort {
	bool sort(sf::RenderWindow &window, const std::string &alg, int count, int delay) {
		const std::string algorithms[] = {
			"Bubble",
			"Heap",
			"Cycle",
			"Ripple",
			"Insertion",
			"Selection",
			"Quick",
			"Merge",
			"Radix",
			"Pancake",
			"Gnome",
			"Stooge",
			"Shell",
			"Bitonic"
		};

		auto item = std::find(std::begin(algorithms), std::end(algorithms), alg);

		if (item != std::end(algorithms)) {
			std::string name = *item;

			SortArray arr(window, count, delay, name + " Sort");

			switch (std::distance(algorithms, item)) {
			case 0:
				bubbleSort(arr);
				break;
			case 1:
				heapSort(arr);
				break;
			case 2:
				cycleSort(arr);
				break;
			case 3:
				rippleSort(arr);
				break;
			case 4:
				insertionSort(arr);
				break;
			case 5:
				selectionSort(arr);
				break;
			case 6:
				quickSort(arr);
				break;
			case 7:
				mergeSort(arr);
				break;
			case 8:
				radixSort(arr);
				break;
			case 9:
				pancakeSort(arr);
				break;
			case 10:
				gnomeSort(arr);
				break;
			case 11:
				stoogeSort(arr);
				break;
			case 12:
				shellSort(arr);
				break;
			case 13:
				bitonicSort(arr);
				break;
			}

			if (!arr.validate())
				return false;

			return true;
		}
		
		return false;
	}
}