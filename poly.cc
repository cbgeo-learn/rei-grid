#include <Eigen/Dense>
#include <iostream>
#include <vector>

class Poly {
protected:
  std::vector<Eigen::Vector2i> coordlist_;
  int n_ = coordlist_.size();

public:
  Poly(std::vector<Eigen::Vector2i> a) : coordlist_{a} {}
  virtual int area() = 0;
};

class Quadrilateral : public Poly {
public:
  Quadrilateral(std::vector<Eigen::Vector2i> a) : Poly(a) {}
  int area() {
    int a = 0;
    for (int i = 0; i < n_; ++i) {
      int ipp = (i < n_ - 1) ? (i + 1) : 0;
      a += coordlist_[i](0) * coordlist_[ipp](1) -
           coordlist_[ipp](0) * coordlist_[i](1);
    }
    a = a * 0.5;
    return a;
  }
};

class Triangle : public Poly {
public:
  Triangle(std::vector<Eigen::Vector2i> a) : Poly(a) {}
  int area() {
    int a = 0;
    for (int i = 0; i < n_; ++i) {
      int ipp = (i < n_ - 1) ? (i + 1) : 0;
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
  int n = (argc - 1) / 2;
  if (argc % 2 == 0) {
    std::cout << "Incorrect Number of Arguments!" << std::endl;
    std::abort();
  } else {
    for (int i = 0; i < n; ++i) {
      coords(0) = atoi(argv[2 * i + 1]);
      coords(1) = atoi(argv[2 * i + 2]);
      coordlist.push_back(coords);
    }
  }
  
  if (n == 4) {
    Quadrilateral shape(coordlist);
    std::cout << shape.area() << std::endl;
  } else if (n == 3) {
    Triangle shape(coordlist);
    std::cout << shape.area() << std::endl;
  } else {
    std::cout << "Shape Not Allowed" << std::endl;
    std::abort();
  }
}
