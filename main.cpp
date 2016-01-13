#include "Base/Game.hpp"

#include <SFML/Graphics.hpp>

int main() {
  Game game(800, 600, "Atom Heart Engine", sf::Style::Default);
  game.run();
}
