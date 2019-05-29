#ifndef QUAD_H
#define QUAD_H
#include "Poly.h"

class Quadrilateral : public Polygon {
public:
  virtual ~Quadrilateral(){};
  float area(std::vector<Eigen::Vector2f> &coordlist) override;
};

#endif // QUAD_H
