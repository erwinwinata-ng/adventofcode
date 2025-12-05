#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int64_t part1(std::vector<std::vector<int64_t>> ranges, std::vector<int64_t> input) {
	int64_t result = 0;
	
	for (int64_t num : input) {
		bool isFresh = false;
		
		for(std::vector<int64_t> range : ranges) {
			// std::cout << num << " - " << range[0] << "-" << range[1] << " - " << (range[0] <= num && num <= range[1]) << "\n";
			if (range[0] <= num && num <= range[1]) {
				isFresh = true;
			}
		}
		
		if (isFresh) {
			result++;
		}
		
		// std::cout << num << " - " << isFresh << "\n";
	}
	
	return result;
}

int64_t part2(std::vector<std::vector<int64_t>> ranges, std::vector<int64_t> input) {
	std::sort(ranges.begin(), ranges.end());
	
	std::vector<std::vector<int64_t>> mergedRanges;
	for(std::vector<int64_t> range : ranges) {
		bool isMerged = false;
		for(int i = 0; i < mergedRanges.size(); i++) {
			if (range[0] > mergedRanges[i][1] || range[1] < mergedRanges[i][0]) {
				continue; 
			}
			
			// all overrlap
			if (
				range[0] >= mergedRanges[i][0] && range[1] <= mergedRanges[i][1]
			) {
				// std::cout << "all overlap\n";
				isMerged = true;
			}

			// inside overrlap
			if (
				range[0] <= mergedRanges[i][0] && range[1] >= mergedRanges[i][1]
			) {
				// std::cout << "inside overlap\n";
				mergedRanges[i][0] = range[0];
				mergedRanges[i][1] = range[1];
				isMerged = true;
			}

			// left side overlap
			if (
				range[0] >= mergedRanges[i][0] && range[0] <= mergedRanges[i][1] &&
				range[1] >= mergedRanges[i][1]
			) {
				// std::cout << "left overlap\n";
				mergedRanges[i][1] = range[1];
				isMerged = true;
			}
			
			// right side overlap
			if (
				range[0] <= mergedRanges[i][0] && 
				range[1] >= mergedRanges[i][0] && range[1] <= mergedRanges[i][1]
			) {
				// std::cout << "right overlap\n";
				mergedRanges[i][0] = range[0];
				isMerged = true;
			}
		}
		
		if (!isMerged) {
			mergedRanges.push_back(range);
		}
		
		// for(std::vector<int64_t> mergedRange : mergedRanges) {
			// std::cout << mergedRange[0] << "-" << mergedRange[1] << "\n";
		// }
		// std::cout << "-------------------------\n";
		// std::cout << range[0] << "-" << range[1] << "\n";
		// std::cout << "-------------------------\n";
	}

	int64_t result = 0;
	for(std::vector<int64_t> range : mergedRanges) {
		result += range[1] - range[0] + 1;
	}

	return result;
}

int main () {
	std::string line;
	 
	std::vector<std::vector<int64_t>> ranges;
	std::vector<int64_t> input;
	bool isInput = false;
	
	while(std::cin >> line) {
		if (line == "input") { 
			isInput = true;
			
			continue;
		}
		
		if (isInput) {
			input.push_back(std::stoll(line));
		} else {
			std::vector<int64_t> num;
			std::string numString;
			std::stringstream stream(line);
			
			while (std::getline(stream, numString, '-')) {
				num.push_back(std::stoll(numString));
			}
			
			ranges.push_back(num);
		}
	}
	
	// for(std::vector<int64_t> range : ranges) {
		// std::cout << range[0] << "-" << range[1] << "\n";
	// }
	// std::cout << "=========================\n";
	// for(int64_t num: input) {
		// std::cout << num << "\n";
	// }
	
	std::cout << "\n=========================\n";
	int64_t part1Ans = part1(ranges, input);
	std::cout << "Part 1: " << part1Ans;

	std::cout << "\n=========================\n";
	int64_t part2Ans = part2(ranges, input);
	std::cout << "Part 2: " << part2Ans;
	
	std::cout << "\n=========================\n";
	return 0;
}

