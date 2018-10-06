#include "circle_renderer.h"

CircleRenderer::CircleRenderer(sf::RenderWindow &window, int size) 
	: ArrayRenderer(window, size)
{
	auto dim = window.getSize();
	
	int centerPoint = dim.y / 2;
	m_CenterDist = centerPoint - 70;

	m_TriWidth = dim.x / size;

	m_CenterX = dim.x / 2;
}

void CircleRenderer::drawElement(int index, int value, const sf::Color &color) {
	double a1 = 360 * (index / (double)m_Size),
		a2 = 360 * ((index + 1.0) / m_Size);

	sf::ConvexShape triangle(3);

	triangle.setPoint(0, sf::Vector2f(m_CenterX, 70 + m_CenterDist));

	triangle.setPoint(1, sf::Vector2f(m_CenterX + m_CenterDist * sin(a1 * (m_PI / 180)), 70 + m_CenterDist * (1 - cos(a1 * (m_PI / 180)))));
	triangle.setPoint(2, sf::Vector2f(m_CenterX + m_CenterDist * sin(a2 * (m_PI / 180)), 70 + m_CenterDist * (1 - cos(a2 * (m_PI / 180)))));
	

	triangle.setFillColor(color);

	m_Window.draw(triangle);
}