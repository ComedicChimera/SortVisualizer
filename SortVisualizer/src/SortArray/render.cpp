#include "../sort_array.h"

#include <cstdarg>
#include <vector>
#include <cstdlib>
#include <iostream>

void SortArray::draw(unsigned int count, ...) {
	std::vector<int> selected;

	if (count > 0) {
		va_list args;

		va_start(args, count);

		for (int i = 0; i < count; i++)
			selected.push_back(va_arg(args, int));

		va_end(args);
	}

	drawVector(selected);
}

void SortArray::drawVector(const std::vector<int> &selected) {
	m_Window.clear(sf::Color(90, 90, 90, 255));

	drawText();

	for (int i = 0; i < m_TrueSize; i++) {
		sf::Color color = m_Rainbow ? calculateColor(m_Array[i]) : sf::Color(255, 255, 255);

		if (selected.size() > 0) {
			if (std::find(selected.begin(), selected.end(), i) != selected.end())
				color = m_Rainbow ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0);
		}

		m_Renderer.drawElement(i, m_Array[i], color);
	}

	m_Window.display();

	checkClosed();

	if (m_Sound) {
		if (selected.size() == 1) {
			m_Player.playValue(m_Array[selected[0]]);
		}
		else if (selected.size() > 1) {
			int sum = 0;

			for (int ndx : selected) {
				sum += ndx;
			}

			m_Player.playValue(m_Array[sum / selected.size()]);
		}
	}

	sleep(m_Delay);
}

bool SortArray::validate() {
	for (int mx = 0; mx < size - 1; mx++) {
		m_Window.clear(sf::Color(90, 90, 90, 255));
		drawText();

		if (m_Array[mx] > m_Array[mx + 1])
			return false;

		for (int i = 0; i < size; i++) {
			int r = 255, g = 255, b = 255;

			if (i < mx) {
				r = 0;
				b = 0;
			}
			else if (i == mx) {
				g = 0;
				b = 0;
			}

			m_Renderer.drawElement(i, m_Array[i], sf::Color(r, g, b, 255));
		}

		if (m_Sound) m_Player.playValue(m_Array[mx]);

		m_Window.display();

		checkClosed();

		sleep(1);
	}

	m_Window.clear(sf::Color(90, 90, 90, 255));
	drawText();

	for (int i = 0; i < size; i++) 
		m_Renderer.drawElement(i, m_Array[i], sf::Color(0, 255, 0, 255));

	m_Window.display();

	return true;
}

void SortArray::drawText() {
	char data[100];
	sprintf_s(data, 100, "Algorithm: %s\nDelay: %d ms", m_Title.c_str(), m_Delay);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");

	sf::Text text(data, font, 20);
	text.setPosition(sf::Vector2f(7, 7));

	m_Window.draw(text);
}

sf::Color SortArray::calculateColor(int value) {
	int i = (255 * value) / m_TrueSize;

	int r = round(sin(0.024 * i + 0) * 127 + 128);
	int g = round(sin(0.024 * i + 4) * 127 + 128);
	int b = round(sin(0.024 * i + 2) * 127 + 128);

	return sf::Color(r, g, b);
}