#include "ring_renderer.h"

#include <cmath>

RingRenderer::RingRenderer(sf::RenderWindow &window, int size) 
	: ArrayRenderer(window, size)
{
	auto dimensions = window.getSize();

	m_CenterX = dimensions.x / 2.0;
	m_CenterY = (dimensions.y + 70) / 2.0;

	m_Radius = m_CenterY - 90;

	m_AngleIncrement = ((360.0 * 3.14159265) / (m_Size * 180));
}

void RingRenderer::drawElement(int index, int value, const sf::Color &color) {
	static bool print = true;

	double h = abs(m_Size - (value - index)) / (m_Size + 1.0) * m_Radius;

	double angle = m_AngleIncrement * index;

	double s1 = sin(angle) * h, s2 = cos(angle) * h;

	sf::RectangleShape rect(sf::Vector2f(3, 3));
	rect.setPosition(sf::Vector2f(m_CenterX + s2 - 2.5, m_CenterY - s1 - 2.5));

	rect.setFillColor(color);

	m_Window.draw(rect);

	if (index == m_Size - 1)
		print = false;
}
