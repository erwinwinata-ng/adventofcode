#include <iostream>
#include <sstream>
#include <vector>

int safe_diff = 3;
  
bool is_report_safe(std::vector<int> report, bool is_asc) {
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

    return is_safe;
}

int main() {
  std::vector<std::vector<int>> reports;
  std::string line;
  int line_count = 1;

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
    bool is_asc = report[0] - report[report.size() - 1] < 0;
    bool is_safe = is_report_safe(report, is_asc);

    if (!is_safe) {
      for (int i = 0; i < report.size(); i++) {
        std::vector<int> r = report;
        r.erase(r.begin() + i);

        is_safe = is_report_safe(r, is_asc);

        if (is_safe) {
          break;
        }
      }
    }

    if (is_safe) {
      safe_count++;
    }
  }

  std::cout << "Total Safe Report: " << safe_count << std::endl;

  return 0;
}
