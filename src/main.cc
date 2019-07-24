#include "Factory.h"
#include "Hex.h"
#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include <iostream>

int main(int argc, char** argv) {

  std::string file;
  std::string shape;
  int dim;

  if (argc == 3) {
    file = argv[1];
    shape = argv[2];
  } else {
    std::cout << "incorrect number of input arguments" << std::endl;
    std::abort();
  }
 
  std::shared_ptr<Poly> poly = polyFactory::create(shape,file);
  std::cout << poly->area() << std::endl;
  std::cout << poly->volume() << std::endl;
}
