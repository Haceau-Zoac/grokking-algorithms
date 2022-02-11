#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template<typename It>
auto quicksort(It const& begin, It const& end) -> It {
  auto size{ std::distance(begin, end) };
  if (size >= 2) { 
    auto p{ std::prev(end) };
    std::swap(*begin, *p);
    auto mid{ std::partition(begin, end, [p](auto item){ return item <= *p; }) };
    std::swap(*mid, *p);
    quicksort(begin, mid);
    quicksort(std::next(mid), end);
  }
  return begin;
}

auto operator<<(std::ostream& os, std::vector<int> vec) -> std::ostream& {
  os << "[";
  for (auto item : vec) {
    os << item << ", ";
  }
  os << "\b\b]";
  return os;
}

auto main() -> int {
  std::cout << "Running...\n";

  std::vector<int> vec{ 1, 9, 5, 7, 3 };
  quicksort(vec.begin(), vec.end());

  std::cout << vec;
}