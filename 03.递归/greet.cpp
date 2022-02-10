#include <iostream>
#include <string_view>

auto bye() {
  std::cout << "ok bye! \n";
}

auto greet2(std::string_view name) {
  std::cout << "how are you, " << name << "? \n";
}

auto greet(std::string_view name) {
  std::cout << "hello, " << name << "! \n";
  greet2(name);
  std::cout << "getting ready to say bye...\n";
  bye();
}

auto main() -> int {
  greet("maggie");
}