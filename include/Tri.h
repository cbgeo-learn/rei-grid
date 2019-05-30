#ifndef TRI_H
#define TRI_H
#include "Poly.h"

class Triangle : public Polygon {
public:
  Triangle(const std::vector<Eigen::Vector2f> &coordlist)
      : Polygon(coordlist) {}
  virtual ~Triangle(){};
  float area() override;
};

#endif // TRI_H
