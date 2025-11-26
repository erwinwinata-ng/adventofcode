#include <iostream>
#include <regex>
#include <sstream>

int mul(int x, int y) {
  return x * y;
}

int main() {
  std::string input = "";

  std::regex pattern("mul\\((\\d+),(\\d+)\\)");
  auto matched_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
  auto matched_end = std::sregex_iterator();
  int count = 0;
  int result = 0;

  for (std::sregex_iterator i = matched_begin; i != matched_end; i++) {
    std::smatch matched = *i;
    std::string text = matched.str();

    std::smatch numbers;
    if (std::regex_search(text, numbers, pattern)) {
      int x = std::stoi(numbers[1].str());
      int y = std::stoi(numbers[2].str());

      result += mul(x, y);
    } else {
      std::cout << "Pattern not found" << std::endl;
    }

    std::cout << "Matched " << ++count << " -> "<< matched.str() << std::endl;
  } 

  if (count == 0) {
    std::cout << "No Matched" << std::endl;
  } else {
    std::cout << "Total: " << result << std::endl;
  }

  return 0;
}
