#include "Base/Game.hpp"
#include "Base/Scene.hpp"

#include <SFML/Graphics.hpp>

int main() {
  Game game(800, 600, "Atom Heart Engine", sf::Style::Default);
  game.addScene(new Scene());
  game.run();
}
