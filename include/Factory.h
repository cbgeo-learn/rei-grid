#ifndef FACT_H
#define FACT_H
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include "Hex.h"
#include <memory>

class polyFactory {
 public:
  static std::shared_ptr<Poly> create(std::string& shape, std::string& file) {
    if (shape == "quad") {
      return std::make_shared<Quadrilateral>(file);
    } else if (shape == "tri") {
      return std::make_shared<Triangle>(file);
    } else if (shape == "hex") {
      return std::make_shared<Hexahedron>(file);
    } else {
      std::cerr << "Invalid shape. Use quad, tri or hex." << std::endl;
      std::exit(EXIT_FAILURE);
    }
  }
};
#endif  // FACT_H
