#include <iostream>
#include <stdexcept>

int main() try {

}
catch (std::exception &e) {
	std::cout << e.what() << std::endl;
}