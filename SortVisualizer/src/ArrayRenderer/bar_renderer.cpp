#include "bar_renderer.h"

BarRenderer::BarRenderer(sf::RenderWindow &window, int size)
	: ArrayRenderer(window, size)
{
	auto dimensions = window.getSize();

	m_BarHeight = (dimensions.y - 70) / (double)size;
	m_BarWidth = dimensions.x / (double)size;

	m_Height = dimensions.y;
}

void BarRenderer::drawElement(int index, int value, const sf::Color &color) {
	sf::RectangleShape bar(sf::Vector2f(m_BarWidth, m_BarHeight * (value + 1)));

	bar.setFillColor(color);

	bar.setPosition(sf::Vector2f(index * m_BarWidth, m_Height - m_BarHeight * (value + 1)));

	m_Window.draw(bar);
}