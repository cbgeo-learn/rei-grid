#include "Hex.h"

float Hexahedron::area() {
  std::cout << "area is not defined for this shape." << std::endl;
  return 0.;
}

float Hexahedron::volume() {
  float x = coordlist3_[0][0];
  //different ways of accessing the elements: [] or .at() for std::vector [] or () or .x()/.y() for eigen::vector
  float y = coordlist3_.at(0)(1);
  float z = coordlist3_[0].z();
  std::cout
      << "I don't know how to calculate the volume, but I can tell you the "
         "coordinates of the first point are: "
      << x << ", " << y << ", " << z << std::endl;
  return 0.;
}
