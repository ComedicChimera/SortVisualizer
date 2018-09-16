#include "../sort.h"

#include <iostream>

namespace Sort {
	unsigned int gravitySum(int* arr, unsigned int len) {
		unsigned int sum = 0;

		for (int i = 0; i < len; i++) {
			if (arr[i] == 1)
				sum++;
		}

		return sum;
	}

	void gravitySort(SortArray &arr) {
		int **gravityArr = new int*[arr.size];

		for (int i = 0; i < arr.size; i++) {
			gravityArr[i] = new int[arr.size];

			for (int j = 0; j < arr.size; j++) {
				gravityArr[i][j] = j < arr[i] ? 1 : 0;
			}
		}

		for (int x = 0; x < arr.size; x++) {
			int y = 0;

			while (y < arr.size - 1) {
				if (gravityArr[y][x] == 1 && gravityArr[y + 1][x] == 0) {
					gravityArr[y][x] = 0;
					gravityArr[y + 1][x] = 1;

					arr[y] = gravitySum(gravityArr[y], arr.size);
					arr[y + 1] = gravitySum(gravityArr[y + 1], arr.size);

					y = 0;
				}
				else
					y++;
			}

			arr.draw(0);
		}

		delete[] gravityArr;
	}
}