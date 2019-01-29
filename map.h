#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

namespace nathiss::automatons::ant {

using Point = sf::Vector2f;

class Map : public sf::Drawable {
 public:
  static constexpr float cellSize = 2.f;

  void flip(Point) noexcept;

  void draw(sf::RenderTarget&, sf::RenderStates) const override;

  sf::Color getColor(Point) const noexcept;

 private:
  sf::Color negate(sf::Color) const noexcept;

  std::vector<sf::RectangleShape> dots;
};

}  // namespace nathiss::automatons::ant
