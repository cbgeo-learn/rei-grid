#ifndef CIO_H
#define CIO_H
#include <csv.h>

namespace cio {

std::vector<Eigen::Vector2f> read_coordinates(std::string file) {

  std::vector<Eigen::Vector2f> coordlist;
  Eigen::Vector2f coords;

  io::CSVReader<2> in(file);
  in.read_header(io::ignore_extra_column, "x", "y");
  float x, y;
  while (in.read_row(x, y)) {
    coords(0) = x;
    coords(1) = y;
    coordlist.push_back(coords);
  }

  return coordlist;
}

} // namespace cio
#endif // CIO_H