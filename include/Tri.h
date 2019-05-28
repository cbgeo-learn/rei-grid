#ifndef TRI_H
#define TRI_H
#include "Poly.h"

class Triangle : public Polygon {
public:
  Triangle(const std::vector<Eigen::Vector2f> &coordlist)
      : Polygon(coordlist) {}
  float area() override;

protected:
  using Polygon::coordlist_;
};

#endif // TRI_H
