// ??? 为什么出错呢 ???
#include <unordered_set>
#include <unordered_map>
#include <string_view>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <optional>

auto main() -> int {
  std::unordered_set<std::string_view> const states{ 
    "mt", "wa", "or", "id", "nv", "ut", "ca", "az"
  };

  std::unordered_set<std::string_view> states_exist{};

  std::unordered_map<std::string_view, std::unordered_set<std::string_view>> const stations{
    { "kone", { "id", "nv", "ut" } },
    { "ktwo", { "wa", "id", "mt" } },
    { "kthree", { "or", "nv", "ca" } },
    { "kfour", { "nv", "ut" } },
    { "kfive", { "ca", "az" } }
  };

  std::unordered_set<std::string_view> final_stations{};

  while (states_exist.size() == states.size()) {
    std::string_view best_station;
    std::unordered_set<std::string_view> states_covered{};
    
    for (auto const& station : stations) {
      auto [station_name, states_for_station]{ station };

      std::unordered_set<std::string_view> covered;
      std::set_intersection(states.cbegin(), states.cend(),
        states_for_station.cbegin(), states_for_station.cend(),
        std::inserter(covered, covered.cend()));
      if (covered.size() > states_covered.size()) {
        best_station = station_name;
        states_covered = covered;
      }
    }

    final_stations.insert(best_station);
    for (auto const& state : states_covered) {
      states_exist.insert(state);
    }
  }

  for (auto const& station : final_stations) {
    std::cout << station << ' ';
  }
}