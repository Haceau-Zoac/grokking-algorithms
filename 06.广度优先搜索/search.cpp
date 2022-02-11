#include <algorithm>
#include <unordered_map>
#include <string_view>
#include <vector>
#include <deque>
#include <iostream>

std::unordered_map<std::string_view, std::vector<std::string_view>> graph{
  {"you", {"alice", "bob", "claire"}},
  {"bob", {"anuj", "peggy"}},
  {"alice", {"peggy"}},
  {"claire", {"thom", "jonny"}},
  {"anuj", {}},
  {"peggy", {}},
  {"thom", {}},
  {"jonny", {}}
};

auto person_is_seller(std::string_view name) -> bool {
  return name.back() == 'm';
}

auto search() -> bool {
  std::deque<std::string_view> search_queue{};
  search_queue.assign(graph["you"].begin(), graph["you"].end());
  std::vector<std::string_view> searched{};

  while (!search_queue.empty()) {
    auto person{ search_queue.front() };
    search_queue.pop_front();
    if (std::find(searched.cbegin(), searched.cend(), person)
      != searched.end()) {
      if (person_is_seller(person)) {
        std::cout << person << " is a mango seller!\n";
        return true;
      }
      search_queue.insert(search_queue.cend(),
        graph[person].cbegin(), graph[person].cend());
    }
  }

  return false;
}

auto main() -> int {
  search();
}