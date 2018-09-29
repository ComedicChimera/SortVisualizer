#include "line_renderer.h"

LineRenderer::LineRenderer(sf::RenderWindow &window, int size)
	: ArrayRenderer(window, size)
{
	auto dim = m_Window.getSize();

	m_Height = dim.y - 70;
	m_Width = dim.x;

	m_DotSize = m_Height / m_Size;

	if (m_DotSize < 2)
		m_DotSize = 2;
}

void LineRenderer::drawElement(int index, int value, const sf::Color &color) {
	int x = m_Width * (value / (double)m_Size),
		y = m_Height * (index / (double)m_Size);

	sf::RectangleShape rect(sf::Vector2f(m_DotSize, m_DotSize));

	rect.setPosition(x + m_DotSize / 2.0, m_Height - y + 70 - m_DotSize * 1.5);
	rect.setFillColor(color);

	m_Window.draw(rect);
}