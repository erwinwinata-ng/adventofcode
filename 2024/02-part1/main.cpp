#include <iostream>
#include <sstream>
#include <vector>

int main() {
  std::vector<std::vector<int>> reports;
  std::string line;
  int line_count = 1;
  int safe_diff = 3;

  std::cout << "Input numbers separated by space each line, then Ctrl+D to continue." << std::endl;

  while(std::getline(std::cin, line)) {
    std::vector<int> report;
    int number;

    std::stringstream ss(line);
    while (ss >> number) {
      report.push_back(number);
    }

    reports.push_back(report);
  }

  int safe_count = 0;
  for (std::vector report : reports) {
    bool is_asc;
    if (report[0] < report[1]) {
      is_asc = true;
    } else {
      is_asc = false;
    }

    bool is_safe = true;
    for (int i = 0; i < report.size() - 1; i++) {
      if (is_asc) {
        if (report[i] >= report[i + 1] || report[i + 1] - report[i] > safe_diff) {
          is_safe = false;
        }
      } else {
        if (report[i] <= report[i + 1] || report[i] - report[i + 1] > safe_diff) {
          is_safe = false;
        }
      }

      if (!is_safe) {
        break;
      }
    }

    if (is_safe) {
      safe_count++;
    }
  }

  std::cout << "Total Safe Report: " << safe_count << std::endl;

  return 0;
}
