#include "Base/Game.hpp"
#include "TestMenuScene.hpp"

#include <SFML/Graphics.hpp>

int main() {
  Game game(800, 600, "Atom Heart Engine", sf::Style::Default);
  game.addScene(new TestMenuScene());
  game.run();
}
