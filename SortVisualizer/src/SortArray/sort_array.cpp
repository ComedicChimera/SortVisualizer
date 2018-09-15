#include "../sort_array.h"

#include <random>
#include <chrono>
#include <thread>

SortArray::SortArray(sf::RenderWindow &window, unsigned int size, unsigned int delay, const std::string &title)
	: m_Window(window)
	, m_Title(title)
	, m_Delay(delay)
	, size(size)
{
	m_Array = new int[size];

	for (int i = 0; i < size; i++)
		m_Array[i] = i;

	shuffle();

	auto windowSize = window.getSize();

	m_BarWidth = windowSize.x / (float)size;
	m_BarHeight = (windowSize.y - 60) / (float)size;
}

void SortArray::shuffle() {
	std::srand(std::time(NULL));

	for (int i = size - 1; i > 1; i--) {
		int rand = std::rand() % i;

		swap(i, rand);
	}
}

void SortArray::sleep(int delay) {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}