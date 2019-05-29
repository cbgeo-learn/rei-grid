#ifndef TRI_H
#define TRI_H
#include "Poly.h"

class Triangle : public Polygon {
public:
  virtual ~Triangle(){};
  float area(std::vector<Eigen::Vector2f> &coordlist) override;
};

#endif // TRI_H
