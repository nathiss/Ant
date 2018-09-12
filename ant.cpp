#include "ant.h"

namespace nathiss::automatons::ant {

Ant::Ant(Point p) : point(p), current_direction(Up) {}

void Ant::moveLeft() {
  if (this->current_direction == Left) {
    this->current_direction = Down;
  }
  else if (this->current_direction == Up) {
    this->current_direction = Left;
  }
  else if (this->current_direction == Right) {
    this->current_direction = Up;
  }
  else if (this->current_direction == Down) {
    this->current_direction = Right;
  }
  this->move();
}

void Ant::moveRight() {
  if (this->current_direction == Left) {
    this->current_direction = Up;
  }
  else if (this->current_direction == Up) {
    this->current_direction = Right;
  }
  else if (this->current_direction == Right) {
    this->current_direction = Down;
  }
  else if (this->current_direction == Down) {
    this->current_direction = Left;
  }
  this->move();
}

void Ant::move(float speed) {
  switch (this->current_direction) {
    case Left:
      this->point.x -= speed;
      break;
    case Up:
      this->point.y -= speed;
      break;
    case Right:
      this->point.x += speed;
      break;
    case Down:
      this->point.y += speed;
      break;
  }
}

Point Ant::getPosition() const {
  return this->point;
}

}  // namespace nathiss::automatons::ant
