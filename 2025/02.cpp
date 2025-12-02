#include <iostream>
#include <sstream>
#include <string>

int64_t part1(std::string input) {
	int64_t result = 0;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, ',')) {
		int64_t start = std::stoul(line.substr(0, line.find('-')));
		int64_t end = std::stoul(line.substr(line.find('-') + 1));
		int count = 0;

		for (int64_t i = start; i <= end; i++) {
			std::string str = std::to_string(i);

			if (str.substr(0, str.size()/2) == str.substr(str.size()/2)) {
				// std::cout << i << std::endl;
				result += i;
				count++;
			}
		}

		// std::cout << start << '-' << end << " > invalid: " << count << std::endl;
	}

	return result;
}

int64_t part2(std::string input) {
	int64_t result = 0;

	std::stringstream ss(input);
	std::string line;

	while(std::getline(ss, line, ',')) {
		int64_t start = std::stoul(line.substr(0, line.find('-')));
		int64_t end = std::stoul(line.substr(line.find('-') + 1));
		int count = 0;

		for (int64_t i = start; i <= end; i++) {
			std::string str = std::to_string(i);

			for (int size = 1; size <= str.size()/2; size++) {
				bool invalid = true;

				if (str.size() % size == 0) {
					std::string original = str.substr(0, size);

					for (int index = 1; index < str.size()/size; index++) {
						if (original != str.substr(index * size, size)) {
							invalid = false;
						}

						if (!invalid) {
							break;
						}
					}
				} else {
					invalid = false;
				}

				if (invalid) {
					// std::cout << i << std::endl;
					result += i;
					count++;
					break;
				}
			}

		}

		// std::cout << start << '-' << end << " > invalid: " << count << std::endl;
	}

	return result;
}

int main () {
	std::string input;
	std::string line;

	while(std::cin >> line) {
		input = input + line;
	}

	int64_t part1Ans = part1(input);
	std::cout << "Part 1: " << part1Ans << std::endl;

	int64_t part2Ans = part2(input);
	std::cout << "Part 2: " << part2Ans << std::endl;

	return 0;
}

