#pragma once

#include <SFML/graphics.hpp>

class ArrayRenderer {
protected:
	sf::RenderWindow &m_Window;
	int m_Size;

public:
	ArrayRenderer(sf::RenderWindow &window, int size) 
		: m_Window(window)
		, m_Size(size)
	{}

	virtual void drawElement(int, int, const sf::Color&) = 0;
};