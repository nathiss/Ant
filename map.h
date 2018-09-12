#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "point.h"

namespace nathiss::automatons::ant {

class Map : public sf::Drawable {
 public:
  static constexpr float cellSize = 2.f;

  void flip(Point);

  void draw(sf::RenderTarget&, sf::RenderStates) const override;

  sf::Color getColor(Point) const;

 private:
  sf::Color negate(sf::Color) const;

  std::vector<sf::RectangleShape> dots;
};

}  // namespace nathiss::automatons::ant
