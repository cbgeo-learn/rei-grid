#include <array>
#include <iostream>
#include <vector>

class Poly {
private:
  std::vector<std::array<int, 2>> coordlist_;

public:
  Poly(std::vector<std::array<int, 2>> a) : coordlist_{a} {}
  int area() {
    int a = 0;
    for (int i = 0; i < coordlist_.size(); ++i) {
      int ipp = (i < coordlist_.size() - 1) ? (i + 1) : 0;
      a += coordlist_[i].at(0) * coordlist_[ipp].at(1) -
           coordlist_[ipp].at(0) * coordlist_[i].at(1);
    }
    a = a * 0.5;
    return a;
  }
};

int main(int argc, char **argv) {
  std::vector<std::array<int, 2>> coordlist;

  if (argc % 2 == 0) {
    std::cout << "Incorrect Number of Arguments!" << std::endl;
    std::abort();
  } else {
    int n = (argc - 1) / 2;
    for (int i = 0; i < n; ++i) {
      std::array<int, 2> coords = {atoi(argv[2 * i + 1]),
                                   atoi(argv[2 * i + 2])};
      coordlist.push_back(coords);
    }
  }

  Poly poly(coordlist);
  std::cout << poly.area() << std::endl;
}
