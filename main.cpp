#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>

struct thing1 {
  std::string name;
  uint32_t id;

  thing1(std::string name_ = "<Thing the 1st/>",
         uint32_t id_ = 1)
    : name(name_), id(id_) {}
  virtual ~thing1() = default;
};

class thing2 {
public:
  std::string name;
  uint32_t id;

  thing2(std::string name_ = "<Thing the 2nd/>",
         uint32_t id_ = 2)
    : name(name_), id(id_) {}
  virtual ~thing2() = default;
};

int main() {

  thing1 t1a;
  thing1 t1b ("<Thing the 1st/>", 2);

  thing2 t2a;
  thing2 t2b("<Thing the 2nd/>", 3);

  std::vector<std::tuple<thing1, thing2>> all_things;
  all_things.push_back(std::make_tuple(t1a, t2a));
  all_things.push_back(std::make_tuple(t1b, t2b));

  for (auto vt : all_things) {
    std::cout << std::get<0>(vt).name << ' '
              << std::get<0>(vt).id << ' '
              << std::get<1>(vt).name << ' '
              << std::get<1>(vt).id << '\n';
  }
  std::cout << std::endl;

  std::for_each(all_things.rbegin(), all_things.rend(),
                [](auto & at) {
    auto [ te1, te2 ] = at;
    std::cout << te1.name << ' '
              << te1.id << ' '
              << te2.name << ' '
              << te2.id << '\n';
  });
  std::cout << std::endl;

  std::vector<std::pair<thing1, thing2>> vpting;
  vpting.push_back(std::make_pair(t1a, t2a));
  vpting.push_back(std::make_pair(t1b, t2b));

  for (auto pt : vpting) {
    std::cout << pt.first.name << ' '
              << pt.first.id << ' '
              << pt.second.name << ' '
              << pt.second.id << '\n';
  }
  std::cout << std::endl;

  std::for_each(vpting.rbegin(), vpting.rend(),
                [](auto & at) {
    auto [ t1, t2 ] = at;
    std::cout << t1.name << ' '
              << t1.id << ' '
              << t2.name << ' '
              << t2.id << '\n';
  });
  std::cout << std::endl;

  return 0;
}