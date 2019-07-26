#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include <csv.h>

class Poly {
 public:
  Poly(const std::string& file, int dim) {

    if (dim == 2) {
      Eigen::Vector2f coords;
      io::CSVReader<2> in(file);
      in.read_header(io::ignore_extra_column, "x", "y");
      float x, y;
      while (in.read_row(x, y)) {
        coords(0) = x;
        coords(1) = y;
        coordlist2_.push_back(coords);
      }
    }
    if (dim == 3) {
      Eigen::Vector3f coords;
      io::CSVReader<3> in(file);
      in.read_header(io::ignore_extra_column, "x", "y", "z");
      float x, y, z;
      while (in.read_row(x, y, z)) {
        coords(0) = x;
        coords(1) = y;
        coords(2) = z;
        coordlist3_.push_back(coords);
      }
    }
  }
  virtual ~Poly(){};
  virtual float area() = 0;
  virtual float volume() = 0;

 protected:
  std::vector<Eigen::Vector2f> coordlist2_;
  std::vector<Eigen::Vector3f> coordlist3_;
};

#endif  // POLY_H
