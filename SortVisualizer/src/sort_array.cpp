#include "sort_array.h"

#include <stdexcept>
#include <random>
#include <chrono>
#include <thread>
#include <cstdarg>
#include <vector>

#include "constants.h"

SortArray::SortArray(sf::RenderWindow &window, unsigned int size, unsigned int _delay) 
	: m_Window(window)
	, size(size)
{
	m_Array = new int[size];

	for (int i = 0; i < size; i++)
		m_Array[i] = i;

	shuffle();

	auto windowSize = window.getSize();

	barWidth = windowSize.x / (float)size;
	barHeight = windowSize.y / (float)size;
	delay = _delay;
}

SortArray::~SortArray() {
	// delete[] m_Array;
}

int& SortArray::operator[](unsigned int index) {
	if (index < size) {
		return m_Array[index];
	}

	throw new std::out_of_range("Index out of range of sorted array.");
}

void SortArray::swap(int a, int b) {
	if (a < size && b < size) {
		if (a != b) {

			int c = m_Array[a];
			m_Array[a] = m_Array[b];
			m_Array[b] = c;

		}
		return;
	}
		

	throw new std::out_of_range("Index out of range of sorted array.");
}

void SortArray::draw(unsigned int count, ...) {
	std::vector<int> selected;
	bool hasSelected = true;

	if (count > 0) {
		va_list args;

		va_start(args, count);

		for (int i = 0; i < count; i++)
			selected.push_back(va_arg(args, int));

		va_end(args);
	}
	else
		hasSelected = false;
	
	m_Window.clear(sf::Color(90, 90, 90, 255));

	for (int i = 0; i < size; i++) {
		int value = m_Array[i];

		sf::RectangleShape bar(sf::Vector2f(barWidth, barHeight * (m_Array[i] + 1)));

		int gb = 255;

		if (hasSelected) {
			if (std::find(selected.begin(), selected.end(), i) != selected.end())
				gb = 0;
		}

		bar.setFillColor(sf::Color(255, gb, gb, 255));

		bar.setPosition(sf::Vector2f(i * barWidth, HEIGHT - barHeight * (m_Array[i] + 1)));

		m_Window.draw(bar);
	}

	m_Window.display();
	sleep();

}

void SortArray::shuffle() {
	std::srand(std::time(NULL));

	for (int i = size - 1; i > 1; i--) {
		int rand = std::rand() % i;

		swap(i, rand);
	}
}

void SortArray::sleep() {
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}