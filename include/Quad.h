#ifndef QUAD_H
#define QUAD_H
#include "Poly.h"

class Quadrilateral : public Polygon {
 public:
  Quadrilateral(const std::vector<Eigen::Vector2f>& coordlist)
      : Polygon(coordlist) {}
  virtual ~Quadrilateral(){};
  float area() override;
};

#endif  // QUAD_H
