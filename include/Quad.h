#ifndef QUAD_H
#define QUAD_H
#include "Poly.h"

class Quadrilateral : public Polygon {
public:
  Quadrilateral(const std::vector<Eigen::Vector2f> &coordlist)
      : Polygon(coordlist) {}
  float area() override;

protected:
  using Polygon::coordlist_;
};

#endif // QUAD_H
