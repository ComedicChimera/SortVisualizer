#include "../sort.h"

#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

namespace Sort {
	void timeSort(SortArray &arr) {
		std::mutex m;
		std::vector<std::thread> threads;

		std::vector<int> newArray;

		for (int i = 0; i < arr.size; i++) {
			threads.push_back(std::thread([&](int value) {
				std::this_thread::sleep_for(std::chrono::milliseconds(value * 4));

				m.lock();

				newArray.push_back(value);

				m.unlock();
			}, arr[i]));
		}

		arr.draw(0);

		for (int i = 0; i < threads.size(); i++) {
			if (threads[i].joinable()) {
				threads[i].join();
				arr[i] = newArray[i];
				arr.draw(1, i);
			}
		}

		insertionSort(arr);
	}
}