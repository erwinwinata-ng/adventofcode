#include <iostream>
#include <sstream>
#include <string>

int64_t part1(std::string input) {
	int64_t result = 0;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, '\n')) {
		int max = 0;
		int maxNum = 0;
		for (int i = 0; i < line.size(); i++) {
			int current = std::stoi(line.substr(i,1));	
			int number = (maxNum * 10) + current;
			
			if (number > max) {
				max = number;
			}
			if (current > maxNum) {
				maxNum = current;
			}
		}

		// std::cout << line << " - " << max << std::endl;
		result += max;
	}

	return result;
}

int64_t part2(std::string input) {
	int arrSize = 12;
	int64_t result = 0;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, '\n')) {
		int numArray[arrSize];
		for (int i = 0; i < arrSize; i++) {
			numArray[i] = 0;
		}

		int64_t max = 0;
		for (int i = 0; i < line.size(); i++) {
			std::cout << "start\n";

			int current = std::stoi(line.substr(i,1));	


			int64_t number = 0;
			for (int j = 0; j < arrSize - 1; j++) {
				number = (number + numArray[j]) * 10;
			}
			number += current;

			std::cout << "current: " << current << ", number: " << number << ", max: " << max << "\n";
			
			if (number > max) {
				max = number;

			}

			bool isShifted = false;
			numArray[arrSize - 1] = current;
			for (int j = 0; j < arrSize; j++) {
				if (numArray[j] < numArray[j + 1]) {
					isShifted = true;
				}
				if (isShifted) {
					numArray[j] = numArray[j + 1];
				}
			}

			for (int j = 0; j < arrSize; j++) {
				std::cout << numArray[j];
			}
			
			std::cout << "end\n";
		}

		std::cout << line << " - " << max << std::endl;
		result += max;
	}

	return result;
}

int main () {
	std::string input;
	std::string line;

	while(std::cin >> line) {
		input = input + line + '\n';
	}

	int64_t part1Ans = part1(input);
	std::cout << "Part 1: " << part1Ans << std::endl;

	int64_t part2Ans = part2(input);
	std::cout << "Part 2: " << part2Ans << std::endl;

	return 0;
}

