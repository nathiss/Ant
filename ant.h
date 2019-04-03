#pragma once

#include "map.h"

namespace nathiss::automatons::ant {

class Ant {
 public:
  enum Direction {
   Left,
   Up,
   Right,
   Down
  };

  explicit Ant(Point) noexcept;

  void moveLeft() noexcept;
  void moveRight() noexcept;

  inline Point getPosition() const noexcept {
    return this->point;
  }

 private:
  void move(float speed = Map::cellSize) noexcept;

  Point point;
  Direction current_direction;
};

}  // namespace nathiss::automatons::ant
