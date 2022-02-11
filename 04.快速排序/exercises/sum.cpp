#include <iostream>
#include <vector>

template<typename It>
auto sum(It begin, It end) {
  if (begin == end) {
    return 0;
  }
  return *begin + sum(begin + 1, end);
}

auto main() -> int {
  std::vector vec{ 1, 2, 3, 4 };
  std::cout << sum(vec.cbegin(), vec.cend());
}