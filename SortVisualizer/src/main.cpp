#include <SFML/Graphics.hpp>
#include <iostream>

#include "sort.h"
#include "sort_array.h"

unsigned int WIDTH = 1280, HEIGHT = 720;
bool FULLSCREEN = false, RAINBOW = false, SOUND = true;

void sort(std::string &algorithm, int count, int delay) {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Default);

	window.clear();

	if (!Sort::sort(window, algorithm, count, delay, RAINBOW, SOUND))
		std::cout << "Failed to sort collection." << std::endl;

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

int main(int argc, char* argv[]) {
	std::string algorithm("Bubble");

	int count = 256;
	int delay = 1;

	bool setArg = true;
	int nextArg = 0;
	for (int i = 1; i < argc; i++) {
		if (setArg) {
			switch (nextArg) {
			case 0:
				algorithm = argv[i];
				break;
			case 1:
				count = atoi(argv[i]);
				break;
			case 2:
				delay = atoi(argv[i]);
				break;
			case 3:
				WIDTH = atoi(argv[i]);
				break;
			case 4:
				HEIGHT = atoi(argv[i]);
				break;				
			}

			setArg = false;
		}
		else {
			if (!strcmp(argv[i], "-c"))
				nextArg = 1;
			else if (!strcmp(argv[i], "-d"))
				nextArg = 2;
			else if (!strcmp(argv[i], "-w"))
				nextArg = 3;
			else if (!strcmp(argv[i], "-h"))
				nextArg = 4;
			else if (!strcmp(argv[i], "-f")) {
				FULLSCREEN = true;
				continue;
			}
			else if (!strcmp(argv[i], "-rainbow")) {
				RAINBOW = true;
				continue;
			}
			else if (!strcmp(argv[i], "-ns")) {
				SOUND = false;
				continue;
			}

			setArg = true;
		}
	}

	sort(algorithm, count, delay);
}


