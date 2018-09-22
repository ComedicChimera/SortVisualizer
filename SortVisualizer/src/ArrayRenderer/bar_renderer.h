#pragma once

#include "array_renderer.h"

class BarRenderer : public ArrayRenderer {
private:
	float m_BarWidth, m_BarHeight;
	int m_Height;

public:
	BarRenderer(sf::RenderWindow&, int);

	void drawElement(int, int, const sf::Color&) override;
};