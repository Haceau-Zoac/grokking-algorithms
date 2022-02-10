#include <iostream>

auto countdown(int i) -> void {
  std::cout << i << '\n';
  if (i > 1) {
    countdown(i - 1);
  }
}

auto main() -> int {
  countdown(3);
}