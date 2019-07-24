#ifndef QUAD_H
#define QUAD_H
#include "Poly.h"

class Quadrilateral : public Poly {
 public:
  Quadrilateral(const std::string& file)
      : Poly(file) {}
  virtual ~Quadrilateral(){};
  float area() override;
  float volume() override;
};

#endif  // QUAD_H
