#pragma once

template <typename Value = int>
Value valid(std::string phrase = "") {
	Value input;

	std::cout << phrase << "> ";
	std::cin >> input;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(9999999999, '\n');
		std::cout << "That input doesn't work! Try again \n";
		std::cout << phrase << "> ";
		std::cin >> input;
	}
	std::cin.ignore(9999999999, '\n');

	return input;
}
