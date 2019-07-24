#ifndef FACT_H
#define FACT_H
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include "Hex.h"
#include <memory>

class polyFactory {
 public:
  virtual ~polyFactory() {}
  virtual std::shared_ptr<Poly> getShape(
      const std::string& file) = 0;

  static std::shared_ptr<polyFactory> createFactory(std::string& shape);
};

class quadFactory : public polyFactory {
 public:
  virtual ~quadFactory() {}
  std::shared_ptr<Poly> getShape(
      const std::string& file) {
    return std::make_shared<Quadrilateral>(file);
  }
};

class triFactory : public polyFactory {
 public:
  virtual ~triFactory() {}
  std::shared_ptr<Poly> getShape(
      const std::string& file) {
    return std::make_shared<Triangle>(file);
  }
};

class hexFactory : public polyFactory {
 public:
  virtual ~hexFactory() {}
  std::shared_ptr<Poly> getShape(
      const std::string& file) {
    return std::make_shared<Hexahedron>(file);
  }
};

std::shared_ptr<polyFactory> polyFactory::createFactory(std::string& shape) {
  if (shape == "quad") {
    return std::make_shared<quadFactory>();
  } else if (shape == "tri") {
    return std::make_shared<triFactory>();
  } else if (shape == "hex") {
    return std::make_shared<hexFactory>();
  } else {
    std::cerr << "Invalid shape. Use quad, tri or hex." << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
#endif  // FACT_H
