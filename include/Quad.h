#ifndef QUAD_H
#define QUAD_H
#include "Poly.h"

class Quadrilateral : public Poly {
public:
  Quadrilateral(std::vector<Eigen::Vector2i> coordlist) : Poly(coordlist) {}
  int area() override;
};

#endif //QUAD_H
