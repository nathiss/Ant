#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "ant.h"
#include "map.h"

namespace nathiss::automatons::ant {

class App {
 public:
  App(int argc, char **argv);

  int run();

 private:
  void update();
  void draw();

  int argc;
  char **argv;

  bool pause;

  std::unique_ptr<sf::RenderWindow> window;

  std::unique_ptr<Ant> ant;
  std::unique_ptr<Map> map;
};

}  // namespace nathiss::automatons::ant
