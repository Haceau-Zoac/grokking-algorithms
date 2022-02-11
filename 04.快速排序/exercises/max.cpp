#include <numeric>
#include <functional>
#include <iostream>
#include <vector>

template<typename It>
auto mmax(It begin, It end) {
  if (end - begin == 2) {
    return begin[0] > begin[1] ? begin[0] : begin[1];
  }
  auto sub_max{ mmax(begin + 1, end) };
  return *begin > sub_max ? *begin : sub_max;
}

auto main() -> int {
  std::vector vec{ 1, 2, 3, 4 };
  std::cout << mmax(vec.cbegin(), vec.cend());
}