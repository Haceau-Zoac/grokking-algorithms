#include <iostream>
#include <vector>

template<typename It>
auto len(It begin, It end) {
  if (begin == end) {
    return 0;
  }
  return 1 + len(begin+1, end);
}

auto main() -> int {
  std::vector vec{ 1, 2, 3, 4 };
  std::cout << len(vec.cbegin(), vec.cend());
}