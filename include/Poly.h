#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>

class Polygon {
public:
  virtual ~Polygon(){};
  virtual float area(std::vector<Eigen::Vector2f> &coordlist) = 0;
};

#endif // POLY_H
