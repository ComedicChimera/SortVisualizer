#include "../sort_array.h"

#include <cstdarg>
#include <vector>
#include <cstdlib>
#include <iostream>

void SortArray::draw(unsigned int count, ...) {
	std::vector<int> selected;
	bool hasSelected = true;

	if (count > 0) {
		va_list args;

		va_start(args, count);

		for (int i = 0; i < count; i++)
			selected.push_back(va_arg(args, int));

		va_end(args);
	}
	else
		hasSelected = false;

	m_Window.clear(sf::Color(90, 90, 90, 255));

	drawText();

	for (int i = 0; i < size; i++) {
		int value = m_Array[i];

		sf::RectangleShape bar(sf::Vector2f(m_BarWidth, m_BarHeight * (m_Array[i] + 1)));

		sf::Color color = m_Rainbow ? calculateColor(value) : sf::Color(255, 255, 255);

		if (hasSelected) {
			if (std::find(selected.begin(), selected.end(), i) != selected.end())
				color = m_Rainbow ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0);
		}

		bar.setFillColor(color);

		bar.setPosition(sf::Vector2f(i * m_BarWidth, m_Height - m_BarHeight * (m_Array[i] + 1)));

		m_Window.draw(bar);
	}

	m_Window.display();

	checkClosed();

	if (m_Sound) {
		for (int ndx : selected)
			m_Player.playValue(m_Array[ndx]);
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

			int value = m_Array[i];

			sf::RectangleShape bar(sf::Vector2f(m_BarWidth, m_BarHeight * (m_Array[i] + 1)));

			bar.setFillColor(sf::Color(r, g, b, 255));
			bar.setPosition(sf::Vector2f(i * m_BarWidth, m_Height - m_BarHeight * (m_Array[i] + 1)));

			m_Window.draw(bar);
		}

		if (m_Sound) m_Player.playValue(m_Array[mx]);

		m_Window.display();

		checkClosed();

		sleep(1);
	}

	m_Window.clear(sf::Color(90, 90, 90, 255));
	drawText();

	for (int i = 0; i < size; i++) {
		int value = m_Array[i];

		sf::RectangleShape bar(sf::Vector2f(m_BarWidth, m_BarHeight * (m_Array[i] + 1)));

		bar.setFillColor(sf::Color(0, 255, 0, 255));
		bar.setPosition(sf::Vector2f(i * m_BarWidth, m_Height - m_BarHeight * (m_Array[i] + 1)));

		m_Window.draw(bar);
	}

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
	int i = (255 * value) / size;

	int r = round(sin(0.024 * i + 0) * 127 + 128);
	int g = round(sin(0.024 * i + 4) * 127 + 128);
	int b = round(sin(0.024 * i + 2) * 127 + 128);

	return sf::Color(r, g, b);
}