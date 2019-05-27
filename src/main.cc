#include <iostream>
#include <fstream>
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"

int main(int argc, char **argv) {
  std::vector<Eigen::Vector2i> coordlist;
  Eigen::Vector2i coords;

  std::ifstream coord("coordinates.txt");
  std::vector<int> v;
  int j;
  while (coord >> j) {
    v.push_back(j);
  }
  int n = v.size() / 2;

  if (v.size() % 2 != 0) {
    std::cout << "Incorrect Number of Arguments!" << std::endl;
    std::abort();
  } else {
    for (int i = 0; i < n; ++i) {
      coords(0) = v[2 * i];
      coords(1) = v[2 * i + 1];
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
