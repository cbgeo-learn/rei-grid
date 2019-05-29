#include "Quad.h"

float Quadrilateral::area(std::vector<Eigen::Vector2f> &coordlist) {
  std::cout << "calculating the area of the quadrilateral" << std::endl;
  float a = 0;
  coordlist.erase(coordlist.begin() + 4, coordlist.end());
  for (auto it = coordlist.begin(); it != coordlist.end(); ++it) {
    if (*it == coordlist.back()) {
      it[1] = coordlist.front();
    }
    a += it[0](0) * it[1](1) - it[1](0) * it[0](1);
  }
  a = a * 0.5;
  return a;
}
