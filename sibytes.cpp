#include <iostream>

#include "sibytes.hpp"

int main (int argc, char**) {
	if (argc > 1) return 1;

	auto line = std::string();

	while (std::getline(std::cin, line)) {
		const auto number = std::stoul(line);
		std::cout << sibytes(number) << std::endl;
	}

	return 0;
}
