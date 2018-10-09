#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include <cctype>

#include "sort.h"
#include "sort_array.h"

// renderers
#include "ArrayRenderer/circle_renderer.h"
#include "ArrayRenderer/ring_renderer.h"
#include "ArrayRenderer/bar_renderer.h"
#include "ArrayRenderer/square_renderer.h"
#include "ArrayRenderer/line_renderer.h"
#include "ArrayRenderer/wave_renderer.h"

unsigned int WIDTH = 1280, HEIGHT = 720;
bool FULLSCREEN = false, RAINBOW = false, SOUND = true, SHOW_SHUFFLE = false, WAIT = true;
int COUNT = 256, DELAY = 1;
unsigned int RENDERER = 0;

void runSort(SortArray &arr, const std::string &algorithm) {
	if (!Sort::sort(algorithm, arr))
		throw new std::logic_error("The specified algorithm doesn't exist.");

	if (!RAINBOW && !arr.validate())
		std::cout << "Failed to sort array. Please open an issue on github to let me know what happened." << std::endl;
}

std::string getAlgorithmName(std::string algID) {
	if (algID == "Radix4") {
		return "Radix LSD Sort (Base 4)";
	}
	else if (algID == "Radix2") {
		return "Radix LSD Sort (Base 2)";
	}
	else if (algID == "RadixMSD") {
		return "Radix MSD Sort";
	}
	else if (algID == "Radix") {
		return "Radix LSD Sort (Base 10)";
	}
	else if (algID == "Time") {
		return "Time Sort (Mul 4) + Insertion Sort";
	}
	else if (algID == "OddEven") {
		return "Odd Even Sort";
	}
	else if (algID == "Cartesian") {
		return "Cartesian Tree Sort";
	}
	else if (algID == "Dutch") {
		return "Dutch Flag Sort";
	}
	else if (algID == "DoubleSelect") {
		return "Double Selection Sort";
	}
	else
		return algID + " Sort";
}

void startApp(const std::string &algorithm) {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Visualizer", FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Default);

	window.clear();

	std::string algName = getAlgorithmName(algorithm);

	switch (RENDERER) {
	case 0: 
	{
		BarRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	case 1:
	{
		CircleRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	case 2:
	{
		SquareRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	case 3:
	{
		LineRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	case 4:
	{
		WaveRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	case 5:
	{
		RingRenderer renderer(window, COUNT);
		SortArray arr(window, COUNT, DELAY, algName, RAINBOW, SOUND, renderer);

		arr.shuffle(SHOW_SHUFFLE);

		runSort(arr, algorithm);
	}
		break;
	}

	if (WAIT) {
		while (window.isOpen()) {
			sf::Event event;
			if (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
		}
	}
	else {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		window.close();
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
			case 5:
				if (!strcmp(argv[i], "circle")) {
					RENDERER = 1;

					if (!RAINBOW)
						RAINBOW = true;
				}
				else if (!strcmp(argv[i], "square")) {
					RENDERER = 2;

					if (!RAINBOW)
						RAINBOW = true;
				}
				else if (!strcmp(argv[i], "line"))
					RENDERER = 3;
				else if (!strcmp(argv[i], "wave"))
					RENDERER = 4;
				else if (!strcmp(argv[i], "ring"))
					RENDERER = 5;
				else if (strcmp(argv[i], "bar") != 0)
					throw new std::logic_error("There is no renderer by the specified name.");
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
			else if (!strcmp(argv[i], "-v"))
				nextArg = 5;
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
			else if (!strcmp(argv[i], "-ss")) {
				SHOW_SHUFFLE = true;
				continue;
			}
			else if (!strcmp(argv[i], "-nw")) {
				WAIT = false;
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
	std::cin.get();
}


