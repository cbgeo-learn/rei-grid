#ifndef FACT_H
#define FACT_H
#include "Hex.h"
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include <memory>

class polyFactory {
 public:
  static std::shared_ptr<Poly> create(std::string& shape, std::string& file) {
    if (shape == "quad") {
      return std::make_shared<Quadrilateral>(file, 2);
    } else if (shape == "tri") {
      return std::make_shared<Triangle>(file, 2);
    } else if (shape == "hex") {
      return std::make_shared<Hexahedron>(file, 3);
    } else {
      std::cerr << "Invalid shape. Use quad, tri or hex." << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }
};
#endif  // FACT_H
