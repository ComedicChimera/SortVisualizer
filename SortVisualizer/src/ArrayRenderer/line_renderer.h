#pragma once

#include "array_renderer.h"

class LineRenderer : public ArrayRenderer {
	int m_Width, m_Height;
	int m_DotSize;

public:
	LineRenderer(sf::RenderWindow&, int);

	void drawElement(int, int, const sf::Color&) override;
};