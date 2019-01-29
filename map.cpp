#include "map.h"

#include <utility>

namespace nathiss::automatons::ant {

void Map::flip(Point point) noexcept {
  for (auto& dot : this->dots) {
    if (dot.getPosition() == point) {
      dot.setFillColor(this->negate(dot.getFillColor()));
      return;
    }
  }
  sf::RectangleShape rect;
  rect.setSize(sf::Vector2f(cellSize, cellSize));
  rect.setFillColor(sf::Color::Black);
  rect.setPosition(point);
  this->dots.push_back(rect);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates) const {
  for (const auto& dot : this->dots) {
    target.draw(dot);
  }
}

sf::Color Map::getColor(Point point) const noexcept {
  for (const auto& dot : this->dots) {
    if (dot.getPosition() == point)
      return dot.getFillColor();
  }
  return sf::Color::White;
}

sf::Color Map::negate(sf::Color color) const noexcept {
  if (color == sf::Color::White)
    return sf::Color::Black;
  if (color == sf::Color::Black)
    return sf::Color::White;
  return {};  // should never be executed
}

}  // namespace nathiss::automatons::ant
