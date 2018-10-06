#pragma once

#include "array_renderer.h"

class RingRenderer : public ArrayRenderer {
	int m_Radius;
	double m_CenterX, m_CenterY;

	double m_AngleIncrement;

public:
	RingRenderer(sf::RenderWindow &window, int size);

	void drawElement(int, int, const sf::Color&);
};