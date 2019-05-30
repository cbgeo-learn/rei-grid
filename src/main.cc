#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include "Factory.h"
#include "cio.h"
#include <iostream>

int main(int argc, char **argv) {

  std::vector<Eigen::Vector2f> coordlist;
  std::string file;
  std::string shape;

  if (argc == 3) {
    file = argv[1];
    shape = argv[2];
  } else {
    std::cout << "incorrect number of input arguments" << std::endl;
    std::abort();
  }

  coordlist = cio::read_coordinates(file);

  std::shared_ptr<polyFactory> poly_factory = polyFactory::createFactory(shape);
  std::shared_ptr<Polygon> poly = poly_factory->getShape();
  std::cout << poly->area(coordlist) << std::endl;
}
