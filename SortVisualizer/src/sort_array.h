#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SortArray {
	int* m_Array;
	sf::RenderWindow &m_Window;

	float barWidth, barHeight;
	
	unsigned int delay;

	void shuffle();
	void sleep();

public:
	SortArray(sf::RenderWindow&, unsigned int, unsigned int);
	~SortArray();

	int &operator[](unsigned int);
	void swap(int, int);

	void draw(unsigned int count, ...);

	unsigned int size;
};