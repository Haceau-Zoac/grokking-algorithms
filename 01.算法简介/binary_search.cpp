#include <iostream>
#include <optional>
#include <vector>

template<typename T, typename It>
auto binary_search(It begin, It end, T item) -> It {
  int low{ 0 };
  int high{ end - begin - 1 };
  while (high >= low) {
    int diff{ high - low };
    int mid{ diff / 2 + diff % 2 };
    if (begin[mid] == item) {
      return begin + mid;
    }
    if (begin[mid] < item) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return end;
}

auto main() -> int {
  std::cout << "Running...\n\n";

  std::vector<int> my_list{ 1, 3, 5, 7, 9 };

  auto pos{ binary_search(my_list.cbegin(), my_list.cend(), 3) };
  std::cout << (pos == my_list.cend() ? -1 : *pos) << '\n';
  pos = binary_search(my_list.cbegin(), my_list.cend(), -1);
  std::cout << (pos == my_list.cend() ? -1 : *pos) << '\n';
}