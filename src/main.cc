#include "Poly.h"
#include "Quad.h"
#include "Tri.h"
#include "cio.h"
#include <csv.h>
#include <fstream>
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

  Polygon *poly;
  if (shape == "quad") {
    coordlist.erase(coordlist.begin() + 4, coordlist.end());
    poly = new Quadrilateral(coordlist);
  } else if (shape == "tri") {
    coordlist.erase(coordlist.begin() + 3, coordlist.end());
    poly = new Triangle(coordlist);
  } else {
    std::cout << "Shape Not Allowed" << std::endl;
    std::abort();
  }
  std::cout << poly->area() << std::endl;
}
