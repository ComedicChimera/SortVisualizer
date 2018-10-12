#include "../sort_array.h"

#include <random>
#include <chrono>
#include <thread>

SortArray::SortArray(sf::RenderWindow &window, unsigned int size, unsigned int delay, const std::string &title, bool rainbow, bool sound, ArrayRenderer &renderer)
	: m_Window(window)
	, m_Title(title)
	, m_Delay(delay)
	, m_Rainbow(rainbow)
	, m_Player(size)
	, m_Sound(sound)
	, m_Renderer(renderer)
	, m_TrueSize(size)

	, size(size)
{
	m_Array = new int[size];

	for (int i = 0; i < size; i++)
		m_Array[i] = i;

	auto windowSize = window.getSize();

	m_Height = windowSize.y;
}

void SortArray::shuffle(bool showShuffle) {
	std::srand(std::time(NULL));

	if (showShuffle) {
		int delay = m_Delay;
		m_Delay = 3;

		auto algName = m_Title;
		m_Title = "Shuffling...";

		draw(0);
		sleep(500);

		for (int i = size - 1; i > 1; i--) {
			int rand = std::rand() % i;

			swap(i, rand);

			draw(2, i, rand);
		}

		draw(0);
		sleep(500);
		
		m_Title = algName;
		m_Delay = delay;
	}
	else {
		for (int i = size - 1; i > 1; i--) {
			int rand = std::rand() % i;

			swap(i, rand);
		}
	}
}

void SortArray::sleep(int delay) {
	if (delay > 0)
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