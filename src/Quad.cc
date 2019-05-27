#include "Quad.h"

int Quadrilateral::area() {
  std::cout << "calculating the area of the quadrilateral" << std::endl;
  int a = 0;
  for (int i = 0; i < n_; ++i) {
    int ipp = (i < n_ - 1) ? (i + 1) : 0;
    a += coordlist_[i](0) * coordlist_[ipp](1) -
         coordlist_[ipp](0) * coordlist_[i](1);
  }
  a = a * 0.5;
  return a;
}
