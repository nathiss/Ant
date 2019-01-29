#include "game.h"

namespace nathiss::automatons::ant {

App::App(int ac, char **av) noexcept
    : argc(ac), argv(av), pause(false) {
  this->window = std::make_unique<sf::RenderWindow>(
    sf::VideoMode(640, 320),
    "Langton's Ant",
    sf::Style::Titlebar | sf::Style::Close
  );
  this->window->setVerticalSyncEnabled(true);

  this->ant = std::make_unique<Ant>(Point(320.f, 160.f));
  this->map = std::make_unique<Map>();
}

int App::run() noexcept {
  static sf::Event event;

  while(this->window->isOpen()) {
    while(this->window->pollEvent(event)) {
      switch(event.type) {
        case sf::Event::Closed:
          this->window->close();
          break;
        case sf::Event::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) {
            this->window->close();
          }
          if (event.key.code == sf::Keyboard::Space) {
            this->pause = !this->pause;
          }
          break;
        default:
          break;
      }  // switch
    }  // while(event)

    this->update();
    this->draw();
    this->window->display();
  }  // while(open)

  return 0;
}

void App::update() noexcept {
  if (this->pause) {
    return;
  }

  auto position = this->ant->getPosition();

  auto color = this->map->getColor(position);
  if (color == sf::Color::White) {
    this->ant->moveRight();
  }
  else if (color == sf::Color::Black) {
    this->ant->moveLeft();
  }
  this->map->flip(position);
}

void App::draw() noexcept {
  this->window->clear(sf::Color::White);
  this->window->draw(*this->map);
}

}  // namespace nathiss::automatons::ant
