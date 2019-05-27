#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>


class Poly {
protected:
  std::vector<Eigen::Vector2i> coordlist_;
  int n_ = coordlist_.size();

public:
  Poly(std::vector<Eigen::Vector2i> coordlist) : coordlist_{coordlist} {}
  virtual int area() = 0;
};

#endif  //POLY_H
