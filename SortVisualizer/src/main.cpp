#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"
#include "sort.h"
#include "sort_array.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", sf::Style::Default);

	window.clear();

	SortArray arr(window, 256, 1);

	Sort::insertionSort(arr);

	if (!arr.validate()) {
		std::cout << "Failed to sort array." << std::endl;
	}

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}
