#include "../sort.h"

namespace Sort {
	void cycleSort(SortArray &arr) {
		auto lesserCount = [&](int start, int item) -> int {
			int lCount = 0;
			bool countedCycleStart = false;
			
			for (int i = 0; i < arr.size; i++) {
				if (arr[i] < item) {
					if (arr[i] == start) {
						if (countedCycleStart)
							continue;
						else
							countedCycleStart = true;
					}
					lCount++;
				}
			}
				
			return lCount;
		};

		for (int cycleStart = 0; cycleStart < arr.size; cycleStart++) {
			int item = arr[cycleStart];
			int cycleNdx = lesserCount(arr[cycleStart], item);

			if (arr[cycleNdx] == item)
				continue;

			int newItem;
			while (arr[cycleNdx] != item) {
				newItem = arr[cycleNdx];
				arr[cycleNdx] = item;

				cycleNdx = lesserCount(arr[cycleStart], newItem);
				item = newItem;

				arr.draw(1, arr[cycleNdx]);
			}
		}

		arr.draw(0);
	}
}