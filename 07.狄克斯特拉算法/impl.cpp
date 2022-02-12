#include <unordered_map>
#include <vector>
#include <string_view>
#include <optional>
#include <cinttypes>
#include <climits>

std::unordered_map<std::string_view, std::unordered_map<std::string_view, double>> graph{
  { "start", {
    { "a", 6 },
    { "b", 2 }
  }}, { "a", {
    { "fin", 1 }
  }}, { "b", {
    { "a", 3 },
    { "fin", 5 }
  }}, { "fin",
    {}
  }
};

std::unordered_map<std::string_view, double> costs{
  { "a", 6 },
  { "b", 2 },
  { "fin", INFINITY }
};

std::unordered_map<std::string_view, std::optional<std::string_view>> parents{
  { "a", "start" },
  { "b", "start" },
  { "fin", std::nullopt }
};

std::vector<std::string_view> processed{};

auto find_lowest_cost_node(std::unordered_map<std::string_view, double> const& costs) -> std::optional<std::string_view> {
  double lowest_cost{ INFINITY };
  std::optional<std::string_view> lowest_cost_node{ std::nullopt };
  for (auto const& cost : costs) {
    auto const value{ cost.second };
    if ((value < lowest_cost)
      && (std::find(processed.cbegin(), processed.cend(), cost.first) == processed.cend())) {
      
      lowest_cost = value;
      lowest_cost_node = cost.first;
    }
  }
  return lowest_cost_node;
}

auto main() -> int {
  auto node{ find_lowest_cost_node(costs) };
  while (node.has_value()) {
    auto const value{ node.value() };
    auto const cost{ costs[value] };
    auto const neighbors{ graph[value] };
    for (auto const& neighbor : neighbors) {
      auto const new_cost = cost + neighbor.second;
      if (new_cost < cost) {
        costs[value] = cost;
        parents[value] = node;
      }
    }
    processed.emplace_back(value);
    node = find_lowest_cost_node(costs);
  }
}
