#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>

class Polygon {
 public:
  Polygon(const std::vector<Eigen::Vector2f>& coordlist)
      : coordlist_{coordlist} {}
  virtual ~Polygon(){};
  virtual float area() = 0;

 protected:
  std::vector<Eigen::Vector2f> coordlist_;
};

#endif  // POLY_H
