#include <iostream>
#include <string_view>
#include <unordered_map>

std::unordered_map<std::string_view, bool> voted{};

auto check_voted(std::string_view name) -> void {
  if (voted.find(name) != voted.end()) {
    std::cout << "kick them out!\n";
  } else {
    voted[name] = true;
    std::cout << "let them vote!\n";
  }
}

auto main() -> int {
  std::string s;
  std::cin >> s;
  while (s != "$$EXIT$$") {
    check_voted(s);
    std::cin >> s;
  }
}