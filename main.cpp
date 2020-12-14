#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

struct thing1 {
  std::string name;
  uint32_t id;
};

class thing2 {
public:
  std::string name;
  uint32_t id;
};

int main() {

  std::tuple<thing1, thing2> things;
  std::vector<std::tuple<thing1, thing2>> all_things;
  thing1 t1 { "thing1", 1, };
  thing2 t2 { "thing2", 2, };
  auto thingy = std::make_tuple(t1, t2);
  all_things.push_back(thingy);
  for (auto vt : all_things) {
    std::cout << std::get<0>(vt).name << ' '
              << std::get<0>(vt).id << ' '
              << std::get<1>(vt).name << ' '
              << std::get<1>(vt).id << '\n';
  }

  std::pair<thing1, thing2> pting;
  std::vector<std::pair<thing1, thing2>> vpting;
  pting = std::make_pair(t1, t2);
  vpting.push_back(pting);
  for (auto pt : vpting) {
    std::cout << pt.first.name << ' '
              << pt.first.id << ' '
              << pt.second.name << ' '
              << pt.second.id << '\n';
  }

  return 0;
}