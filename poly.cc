#include <iostream>
#include <vector>
#include<Eigen/Dense>

class Poly {
private:
  std::vector<Eigen::Vector2i> coordlist_;

public:
  Poly(std::vector<Eigen::Vector2i> a) : coordlist_{a} {}
  int area() {
    int a = 0;
    for (int i = 0; i < coordlist_.size(); ++i) {
      int ipp = (i < coordlist_.size() - 1) ? (i + 1) : 0;
      a += coordlist_[i](0) * coordlist_[ipp](1) -
           coordlist_[ipp](0) * coordlist_[i](1);
    }
    a = a * 0.5;
    return a;
  }
};

int main(int argc, char **argv) {
  std::vector<Eigen::Vector2i> coordlist;
  Eigen::Vector2i coords;
  if (argc % 2 == 0) {
    std::cout << "Incorrect Number of Arguments!" << std::endl;
    std::abort();
  } else {
    int n = (argc - 1) / 2;
    for (int i = 0; i < n; ++i) {
      coords(0)= atoi(argv[2 * i + 1]);
      coords(1)=atoi(argv[2*i+2]);
      coordlist.push_back(coords);
    }
  }

  Poly poly(coordlist);
  std::cout << poly.area() << std::endl;

  }
