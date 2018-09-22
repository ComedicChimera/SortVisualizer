#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <cctype>

#include "sort.h"
#include "sort_array.h"
#include "ArrayRenderer/bar_renderer.h"

unsigned int WIDTH = 1280, HEIGHT = 720;
bool FULLSCREEN = false, RAINBOW = false, SOUND = true;
int COUNT = 256, DELAY = 1;

void startApp(const std::string &algorithm) {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Default);

	window.clear();

	BarRenderer renderer(window, COUNT);
	SortArray arr(window, COUNT, DELAY, algorithm + " Sort", RAINBOW, SOUND, renderer);

	if (!Sort::sort(algorithm, arr))
		throw new std::logic_error("The specified algorithm doesn't exist.");

	if (!RAINBOW && !arr.validate())
		std::cout << "Failed to sort array. Please open an issue on github to let me know what happened." << std::endl;

	while (window.isOpen()) {
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

int safeConvert(const char* argName, const std::string &value) {
	for (const char &chr : value) {
		if (!std::isdigit(static_cast<unsigned char>(chr))) {
			char buffer[100];
			snprintf(buffer, 100, "Value for the argument '%s' must be an integer not '%s'.", argName, value.c_str());
			
			throw new std::logic_error(buffer);
		}
	}

	return atoi(value.c_str());
}

std::string parseArgs(int argc, char* argv[]) {
	std::string algorithm("Bubble");

	bool setArg = true;
	int nextArg = 0;
	for (int i = 1; i < argc; i++) {
		if (setArg) {
			switch (nextArg) {
			case 0:
				algorithm = argv[i];
				break;
			case 1:
				COUNT = safeConvert("-c", argv[i]);
				break;
			case 2:
				DELAY = safeConvert("-d", argv[i]);
				break;
			case 3:
				WIDTH = safeConvert("-w", argv[i]);
				break;
			case 4:
				HEIGHT = safeConvert("-h", argv[i]);
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
			else {
				char buffer[100];
				snprintf(buffer, 100, "No argument by name '%s'.", argv[i]);

				throw new std::logic_error(buffer);
			}

			setArg = true;
		}
	}

	return algorithm;
}

int main(int argc, char* argv[]) try {
	startApp(parseArgs(argc, argv));
}
catch (std::exception *e) {
	std::cout << e->what() << std::endl;
}


