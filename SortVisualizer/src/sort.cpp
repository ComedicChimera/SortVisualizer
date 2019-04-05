#include "sort.h"

#include <algorithm>

namespace Sort {
	bool sort(const std::string &alg, SortArray &arr) {
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
			"Bitonic",
			"Gravity",
			"Radix4",
			"Radix2",
			"RadixMSD",
			"Time",
			"OddEven",
			"Tim",
			"Intro",
			"Strand",
			"Comb",
			"Tree",
			"Cartesian",
			"Dutch",
			"DoubleSelect",
			"Flash",
			"Smooth",
			"Shatter",
			"InPlaceMerge",
			"Wiki",
			"Sample",
			"InPlaceRadix"
		};

		auto item = std::find(std::begin(algorithms), std::end(algorithms), alg);

		if (item != std::end(algorithms)) {
			std::string name = *item;

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
				radixLSDSort(arr, 10);
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
			case 14:
				gravitySort(arr);
				break;
			case 15:
				radixLSDSort(arr, 4);
				break;
			case 16:
				radixLSDSort(arr, 2);
				break;
			case 17:
				radixMSDSort(arr);
				break;
			case 18:
				timeSort(arr);
				break;
			case 19:
				oddEvenSort(arr);
				break;
			case 20:
				timSort(arr);
				break;
			case 21:
				introSort(arr);
				break;
			case 22:
				strandSort(arr);
				break;
			case 23:
				combSort(arr);
				break;
			case 24:
				treeSort(arr);
				break;
			case 25:
				cartesianTreeSort(arr);
				break;
			case 26:
				dutchFlagSort(arr);
				break;
			case 27:
				doubleSelectionSort(arr);
				break;
			case 28:
				flashSort(arr);
				break;
			case 29:
				smoothSort(arr);
				break;
			case 30:
				shatterSort(arr);
				break;
			case 31:
				inPlaceMergeSort(arr);
				break;
			case 32:
				wikiSort(arr);
				break;
			case 33:
				sampleSort(arr);
				break;
			case 34:
				inPlaceRadixLSDSort(arr);
				break;
			}

			return true;
		}

		return false;
	}
}