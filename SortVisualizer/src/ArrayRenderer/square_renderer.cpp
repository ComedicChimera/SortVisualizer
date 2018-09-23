#include "square_renderer.h"

#include <cmath>
#include <iostream>

SquareRenderer::SquareRenderer(sf::RenderWindow &window, int size) 
	: ArrayRenderer(window, size)
{
	auto dimensions = window.getSize();
	m_Height = dimensions.y;
	m_Width = dimensions.x;

	m_Side = (int)floor(m_Height / 2);

	m_Rows = size;
	m_Columns = size;

	for (int i = 1; i < size / 2; i++) {
		if (size % i == 0 && size / i + i < m_Rows + m_Columns) {
			m_Rows = i;
			m_Columns = size / i;
		}
	}

	m_ElemWidth = m_Side / (double)m_Rows;
	m_ElemHeight = m_Side / (double)m_Columns;
}

void SquareRenderer::drawElement(int index, int value, const sf::Color &color) {
	sf::RectangleShape rect(sf::Vector2f(m_ElemWidth, m_ElemHeight));

	auto dimensions = m_Window.getSize();

	rect.setPosition(sf::Vector2f((m_Width / 2 - m_Side / 2) + index % m_Rows * m_ElemWidth, (m_Height - m_Side / 2) - (index / m_Rows) * m_ElemHeight));

	rect.setFillColor(color);

	m_Window.draw(rect);
}