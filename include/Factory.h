#ifndef FACT_H
#define FACT_H
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include <memory>

class polyFactory {
 public:
  virtual ~polyFactory() {}
  virtual std::shared_ptr<Polygon> getShape(
      const std::vector<Eigen::Vector2f>& coordlist) = 0;

  static std::shared_ptr<polyFactory> createFactory(std::string& shape);
};

class quadFactory : public polyFactory {
 public:
  virtual ~quadFactory() {}
  std::shared_ptr<Polygon> getShape(
      const std::vector<Eigen::Vector2f>& coordlist) {
    return std::make_shared<Quadrilateral>(coordlist);
  }
};

class triFactory : public polyFactory {
 public:
  virtual ~triFactory() {}
  std::shared_ptr<Polygon> getShape(
      const std::vector<Eigen::Vector2f>& coordlist) {
    return std::make_shared<Triangle>(coordlist);
  }
};

std::shared_ptr<polyFactory> polyFactory::createFactory(std::string& shape) {
  if (shape == "quad") {
    return std::make_shared<quadFactory>();
  } else if (shape == "tri") {
    return std::make_shared<triFactory>();
  } else {
    std::cerr << "Invalid shape. Use quad or tri." << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
#endif  // FACT_H
