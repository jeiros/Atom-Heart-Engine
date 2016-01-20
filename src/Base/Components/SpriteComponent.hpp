#ifndef __ATOMHEART_SPRITECOMPONENT__
#define __ATOMHEART_SPRITECOMPONENT__

#include "BaseComponent.hpp"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteComponentManager : public BaseComponentManager {
public:
  void draw();

private:
  struct _sq_vertex_data {
    sf::Vertex top_left;
    sf::Vertex top_right;
    sf::Vertex bottom_left;
    sf::Vertex bottom_right;
  };

  struct _component_data {
    _sq_vertex_data vertex;
    const sf::Texture* texture;
    sf::IntRect textureRect;
  };
};

#endif
