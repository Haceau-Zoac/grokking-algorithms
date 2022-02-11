#include <iostream>
#include <vector>

auto sum(std::vector<int> vec) {
  int total{ 0 };
  for (auto const item : vec) {
    total += item;
  }
  return total;
}

int main() {
  std::cout << sum({ 1, 2, 3, 4 });
}