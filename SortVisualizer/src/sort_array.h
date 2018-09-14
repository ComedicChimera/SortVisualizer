#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SortArray {
	int* m_Array;
	sf::RenderWindow &m_Window;

	float barWidth, barHeight;
	
	unsigned int delay;

	void sleep();

public:
	SortArray(sf::RenderWindow&, unsigned int, unsigned int);
	~SortArray();

	int &operator[](unsigned int);
	void swap(int, int);
	void shuffle();

	void draw(unsigned int count, ...);
	bool validate();

	unsigned int size;
};