#include "Tri.h"

float Triangle::area() {
  std::cout << "calculating the area of the triangle" << std::endl;

  float a = 0;
  coordlist2_.erase(coordlist2_.begin() + 3, coordlist2_.end());
  for (auto it = coordlist2_.begin(); it != coordlist2_.end(); ++it) {
    if (*it == coordlist2_.back()) {
      it[1] = coordlist2_.front();
    }
    a += it[0](0) * it[1](1) - it[1](0) * it[0](1);
  }
  a = a * 0.5;
  return a;
}

float Triangle::volume() {
  std::cout<< "volume is not defined for this shape."<<std::endl;
  return 0.;
}

