#include "../sort_array.h"

#include <random>
#include <chrono>
#include <thread>

SortArray::SortArray(sf::RenderWindow &window, unsigned int size, unsigned int delay, const std::string &title, bool rainbow, bool sound)
	: m_Window(window)
	, m_Title(title)
	, m_Delay(delay)
	, m_Rainbow(rainbow)
	, m_Player(size)
	, m_Sound(sound)

	, size(size)
{
	m_Array = new int[size];

	for (int i = 0; i < size; i++)
		m_Array[i] = i;

	shuffle();

	auto windowSize = window.getSize();

	m_BarWidth = windowSize.x / (float)size;
	m_BarHeight = (windowSize.y - 60) / (float)size;

	m_Height = windowSize.y;
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

void SortArray::checkClosed() {
	sf::Event event;
	if (m_Window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_Window.close();
			exit(0);
		}
	}
}