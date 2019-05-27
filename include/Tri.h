#ifndef TRI_H
#define TRI_H
#include "Poly.h"

class Triangle : public Poly {
public:
  Triangle(std::vector<Eigen::Vector2i> coordlist) : Poly(coordlist) {}
  int area();
};

#endif //TRI_H
