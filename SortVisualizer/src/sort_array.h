#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Player/player.h"

class SortArray {
	int* m_Array;
	sf::RenderWindow &m_Window;

	float m_BarWidth, m_BarHeight;
	
	unsigned int m_Delay, m_Height;

	const std::string m_Title;

	bool m_Rainbow, m_Sound;

	Player m_Player;

	void sleep(int delay);
	void drawText();
	void checkClosed();

	sf::Color calculateColor(int);

public:
	SortArray(sf::RenderWindow&, unsigned int, unsigned int, const std::string&, bool, bool);

	int &operator[](unsigned int);
	void swap(int, int);
	void shuffle();

	void draw(unsigned int count, ...);
	bool validate();

	unsigned int size;
};