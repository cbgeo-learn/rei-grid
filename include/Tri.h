#ifndef TRI_H
#define TRI_H
#include "Poly.h"

class Triangle : public Poly {
 public:
  Triangle(const std::string& file)
      : Poly(file) {}
  virtual ~Triangle(){};
  float area() override;
  float volume() override;
};

#endif  // TRI_H
