#pragma once

#include "map.h"
#include "point.h"

namespace nathiss::automatons::ant {

class Ant {
 public:
  enum Direction {
   Left,
   Up,
   Right,
   Down
  };

  explicit Ant(Point);

  void moveLeft();
  void moveRight();

  Point getPosition() const;

 private:
  void move(float speed = Map::cellSize);

  Point point;
  Direction current_direction;
};

}  // namespace nathiss::automatons::ant
