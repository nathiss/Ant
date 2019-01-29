#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "ant.h"
#include "map.h"

namespace nathiss::automatons::ant {

class App {
 public:
  App(int argc, char **argv) noexcept;

  int run() noexcept;

 private:
  void update() noexcept;
  void draw() noexcept;

  int argc;
  char **argv;

  bool pause;

  std::unique_ptr<sf::RenderWindow> window;

  std::unique_ptr<Ant> ant;
  std::unique_ptr<Map> map;
};

}  // namespace nathiss::automatons::ant
