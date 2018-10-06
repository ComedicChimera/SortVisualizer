#pragma once

#include "array_renderer.h"

class WaveRenderer : public ArrayRenderer {
	int m_Width, m_Height, m_DotSize;

	int m_HalfHeight;

	const double m_TAU = 6.28318;

public:
	WaveRenderer(sf::RenderWindow&, int);

	void drawElement(int, int, const sf::Color&) override;
};