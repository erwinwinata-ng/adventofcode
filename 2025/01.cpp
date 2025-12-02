#include <iostream>
#include <sstream>
#include <string>

int part1(std::string input) {
	int result = 0;
	int currentPosition = 50;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, '\n')) {
		std::string direction = line.substr(0,1);
		int count = std::stoi(line.substr(1));

		if (direction == "L") {
			currentPosition -= count;
		} else if (direction == "R") {
			currentPosition += count;
		}


		while (currentPosition < 0) {
			currentPosition += 100;
		}
		while (currentPosition >= 100) {
			currentPosition -= 100;
		}
		if (currentPosition == 0) {
			result++;
		}

		// std::cout << direction << " - " << count << " - " << currentPosition << std::endl;
	}

	return result;
}

int part2(std::string input) {
	int result = 0;
	int currentPosition = 50;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, '\n')) {
		std::string direction = line.substr(0,1);
		int count = std::stoi(line.substr(1));

		int prevPosition = currentPosition;

		if (direction == "L") {
			currentPosition -= count;
		} else if (direction == "R") {
			currentPosition += count;
		}

		while (currentPosition < 0) {
			currentPosition += 100;
			if (currentPosition + count != 100) {
				result++;
			}
		}
		while (currentPosition >= 100) {
			currentPosition -= 100;
			if (currentPosition != 0) {
				result++;
			}
		}
		if (currentPosition == 0) {
			result++;
		}

		std::cout << direction << " - " << count << " - " << currentPosition << " - " << result << std::endl;
	}

	return result;
}

int main () {
	std::string input;
	std::string line;

	while(std::cin >> line) {
		input = input + line + "\n";
	}

	int part1Ans = part1(input);
	std::cout << "Part 1: " << part1Ans << std::endl;

	int part2Ans = part2(input);
	std::cout << "Part 2: " << part2Ans << std::endl;

	return 0;
}

