#ifndef FACT_H
#define FACT_H
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"

class polyFactory {
public:
  virtual ~polyFactory() {}
  virtual Polygon *getShape() = 0;

  static polyFactory *createFactory(std::string &shape);
};

class quadFactory : public polyFactory {
public:
  virtual ~quadFactory() {}
  Polygon *getShape() { return new Quadrilateral; }
};

class triFactory : public polyFactory {
public:
  virtual ~triFactory() {}
  Polygon *getShape() { return new Triangle; }
};

polyFactory *polyFactory::createFactory(std::string &shape) {
  if (shape == "quad") {
    return new quadFactory;
  } else if (shape == "tri") {
    return new triFactory;
  } else {
    std::cerr << "Invalid shape. Use quad or tri." << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
#endif // FACT_H
