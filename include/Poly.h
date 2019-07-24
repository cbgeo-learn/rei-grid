#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include <csv.h>

class Poly {
 public:
  Poly(const std::string& file) {

    Eigen::Vector2f coords;

    io::CSVReader<2> in(file);
    in.read_header(io::ignore_extra_column, "x", "y");
    float x, y;
    while (in.read_row(x, y)) {
      coords(0) = x;
      coords(1) = y;
      coordlist_.push_back(coords);
    }
  }

  virtual ~Poly(){};
  virtual float area() = 0;
  virtual float volume() = 0;

 protected:
  std::vector<Eigen::Vector2f> coordlist_;
};

#endif  // POLY_H
