#include "Resources.hpp"
 
// sf::Texture Resources::texture1;
sf::Texture Resources::test_texture;

void Resources::load() {
  //texture1.loadFromFile("blah.png");
  test_texture.loadFromFile("test.png");
}
