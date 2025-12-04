#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int64_t part1(std::vector<std::vector<char>> map) {
	int64_t result = 0;
	std::vector<std::vector<char>> newMap = map;
	
	for (int r = 0; r < map.size(); r++) {
		for (int c = 0; c < map[r].size(); c++) {
			if (map[r][c] == '.') continue;
			
			int count = 0;
			
			std::vector<int> rowToCheck;
			if (r-1 >= 0) rowToCheck.push_back(r-1);
			rowToCheck.push_back(r);
			if (r+1 < map.size()) rowToCheck.push_back(r+1);
			
			std::vector<int> colToCheck;
			if (c-1 >= 0) colToCheck.push_back(c-1);
			colToCheck.push_back(c);
			if (c+1 < map[r].size()) colToCheck.push_back(c+1);
			
			for (int row : rowToCheck) {
				for (int col : colToCheck) {
					if (row == r && col == c) continue;
					if (map[row][col] == '@') {
						count++;
					}
				}
			}
			
			if (count < 4) { 
				result++;
				newMap[r][c] = 'X';
			}
		}
	}
	
	// for(std::vector<char> row : newMap) {
		// for(char obj : row) {
			// std::cout << obj;
		// }
		// std::cout << "\n";
	// }

	return result;
}

int64_t part2(std::vector<std::vector<char>> map) {
	int64_t result = 0;
	std::vector<std::vector<char>> newMap = map;
	
	for (int r = 0; r < map.size(); r++) {
		for (int c = 0; c < map[r].size(); c++) {
			if (map[r][c] == 'X') newMap[r][c] = '.';
			if (map[r][c] == 'X' || map[r][c] == '.') continue;
			
			int count = 0;
			
			std::vector<int> rowToCheck;
			if (r-1 >= 0) rowToCheck.push_back(r-1);
			rowToCheck.push_back(r);
			if (r+1 < map.size()) rowToCheck.push_back(r+1);
			
			std::vector<int> colToCheck;
			if (c-1 >= 0) colToCheck.push_back(c-1);
			colToCheck.push_back(c);
			if (c+1 < map[r].size()) colToCheck.push_back(c+1);
			
			for (int row : rowToCheck) {
				for (int col : colToCheck) {
					if (row == r && col == c) continue;
					if (map[row][col] == '@') {
						count++;
					}
				}
			}
			
			if (count < 4) { 
				result++;
				newMap[r][c] = 'X';
			}
		}
	}
	
	// for(std::vector<char> row : newMap) {
		// for(char obj : row) {
			// std::cout << obj;
		// }
		// std::cout << "\n";
	// }
	// std::cout << "-------------------------\n";

	if (result > 0) {
		result += part2(newMap);
	}

	return result;
}

int main () {
	std::string line;
	
	std::vector<std::vector<char>> map;

	int rFill = 0;
	while(std::cin >> line) {
		std::vector<char> row;
		for(int c = 0; c < line.size(); c++) {
			row.push_back(line.substr(c, 1)[0]);
		}
		map.push_back(row);
		rFill++;
	}
	
	// for(std::vector<char> row : map) {
		// for(char obj : row) {
			// std::cout << obj;
		// }
		// std::cout << "\n";
	// }
	
	std::cout << "\n=========================\n";
	int64_t part1Ans = part1(map);
	std::cout << "Part 1: " << part1Ans;

	std::cout << "\n=========================\n";
	int64_t part2Ans = part2(map);
	std::cout << "Part 2: " << part2Ans;
	
	std::cout << "\n=========================\n";
	return 0;
}

