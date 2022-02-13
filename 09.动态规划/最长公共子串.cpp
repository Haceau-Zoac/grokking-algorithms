#include <string_view>
#include <vector>
#include <iostream>

std::string_view const words[]{ "fish", "vista", "rmdir", "rcdir", "rcdie", "crmir", "emdir", "commit", "push", "fuck", "pull", "remote", "add" };

auto main(int argc, char* argv[]) -> int {
  if (argc < 2) {
    return -1;
  }

  std::string_view const input{ argv[1] };
  std::string_view near_word{ "" };
  int near_word_len{ 0 };
  for (auto const& word : words) {
    std::vector<std::vector<int>> length(word.size());
    for (std::size_t col{ 0 }; col < word.size(); ++col) {
      for (std::size_t row{ 0 }; row < input.size(); ++row) {
        if (word[col] == input[row]) {
          length[col].emplace_back(((col > 0 && row > 0) ? length[col-1][row-1] : 0) + 1);
        } else {
          length[col].emplace_back(0);
        }
        if (length[col][row] > near_word_len) {
          near_word_len = length[col][row];
          near_word = word;
        }
      }
    }
  }

  std::cout << "Did you mean \"" << near_word << "\" ?\n";
}