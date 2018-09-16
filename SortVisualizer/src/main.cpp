#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "constants.h"
#include "sort.h"
#include "sort_array.h"

void sort(std::string &algorithm, int count, int delay) {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", sf::Style::Default);

	window.clear();

	if (!Sort::sort(window, algorithm, count, delay))
		std::cout << "Failed to sort collection." << std::endl;

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

bool setDirectory() {
	char dirBuff[100];

	GetCurrentDirectory(100, dirBuff);

	std::string directory(dirBuff);
	directory += "\\..\\..\\SortVisualizer";

	if (SetCurrentDirectory(directory.c_str()) == 0) {
		std::cout << GetLastError() << std::endl;
		return false;
	}

	char checkBuff[100];
	GetCurrentDirectory(100, checkBuff);

	std::cout << checkBuff << std::endl;
		
	return true;
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
			}

			setArg = false;
		}
		else {
			if (!strcmp(argv[i], "-c"))
				nextArg = 1;
			else if (!strcmp(argv[i], "-d"))
				nextArg = 2;
			else if (!strcmp(argv[i], "-ucwd")) {
				if (!setDirectory()) {
					std::cin.get();
					return 1;
				}

				continue;
			}

			setArg = true;
		}
	}

	sort(algorithm, count, delay);
}


