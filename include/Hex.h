#ifndef HEX_H
#define HEX_H
#include "Poly.h"

class Hexahedron : public Poly {
 public:
  Hexahedron(const std::string& file, int dim)
      : Poly(file, dim) {}
  virtual ~Hexahedron(){};
  float area() override;
  float volume() override;
};

#endif  // HEX_H
