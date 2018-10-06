#pragma once

#include "array_renderer.h"

class CircleRenderer : public ArrayRenderer {
	int m_CenterDist, m_TriWidth, m_CenterX;

	const double m_PI = 3.141592;

public:
	CircleRenderer(sf::RenderWindow&, int);

	void drawElement(int, int, const sf::Color&) override;
};