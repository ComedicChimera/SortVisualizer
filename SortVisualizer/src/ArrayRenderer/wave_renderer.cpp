#include "wave_renderer.h"

WaveRenderer::WaveRenderer(sf::RenderWindow &window, int size) 
	: ArrayRenderer(window, size)
{
	auto dim = window.getSize();

	m_Width = dim.x;
	m_Height = dim.y;

	m_HalfHeight = (m_Height - 70) / 2;

	m_DotSize = m_Width / size;

	if (m_DotSize < 2)
		m_DotSize = 2;
}

void WaveRenderer::drawElement(int index, int value, const sf::Color &color) {
	int height = m_HalfHeight + floor(sin(m_TAU * (value / (m_Size + 1.0))) * (m_HalfHeight - 10));

	sf::RectangleShape dot(sf::Vector2f(m_DotSize, m_DotSize));

	dot.setPosition(sf::Vector2f((m_Width - m_DotSize) * (index / (double)m_Size) + m_DotSize / 2.0, m_Height - height));
	dot.setFillColor(color);

	m_Window.draw(dot);
}