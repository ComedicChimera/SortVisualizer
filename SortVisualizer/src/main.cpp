#include <SFML/Graphics.hpp>

#include "constants.h"
#include "sort.h"
#include "sort_array.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", sf::Style::Default);

	window.clear();

	SortArray arr(window, 500, 1);

	Sort::quickSort(arr);

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}