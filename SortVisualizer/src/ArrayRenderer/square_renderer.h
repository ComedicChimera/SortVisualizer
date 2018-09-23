#pragma once

#include "array_renderer.h"

class SquareRenderer : public ArrayRenderer {
	int m_Side;
	int m_Height, m_Width;

	double m_ElemWidth, m_ElemHeight;
	int m_Rows, m_Columns;

public:
	SquareRenderer(sf::RenderWindow&, int);

	void drawElement(int, int, const sf::Color&);
};