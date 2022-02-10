#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <iostream>

template<typename T, typename It>
auto find_smallest(It const begin, It const end) -> int {
  return std::accumulate(begin + 1, end, 0, [&, ix=1](int src, T des) {
    return des < begin[src] ? ix : src;
  });
}

template<typename T, typename It, typename List = std::vector<T>>
auto selection_sort(It const begin, It const end) -> List {
  List list;
  list.assign(begin, end);
  for (std::size_t ix{ 0 }; ix < list.size(); ++ix) {
    std::swap(list[ix], list[find_smallest<T>(list.cbegin() + ix, list.cend())]);
  }
  return list;
}

template<typename List>
auto operator<<(std::ostream& os, List& list) -> std::ostream& {
  os << '[';
  for (auto const& item : list) {
    os << item << ',' << ' ';
  }
  os << '\b' << '\b' << ']';
  return os;
}

auto main() -> int {
  std::vector<int> list{ 5, 3, 6, 2, 10 };
  auto result{ selection_sort<int>(list.cbegin(), list.cend()) };
  std::cout << result;
}