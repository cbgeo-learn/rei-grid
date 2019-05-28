#include "Tri.h"

float Triangle::area() {
  std::cout << "calculating the area of the triangle" << std::endl;

  float a = 0;
  for (auto it = coordlist_.begin(); it != coordlist_.end(); ++it) {
    if (*it == coordlist_.back()) {
      it[1] = coordlist_.front();
    }
    a += it[0](0) * it[1](1) - it[1](0) * it[0](1);
  }
  a = a * 0.5;
  return a;
}
