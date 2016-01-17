#ifndef __ATOMHEART_POINTMASSCOMPONENT__
#define __ATOMHEART_POINTMASSCOMPONENT__

// LIB INCLUDES
#include <SFML/Graphics.hpp>

// ENGINE INCLUDES
#include "../Entity.hpp"

class PointMassComponentManager {
  struct ComponentData {
    Entity entity;
    float mass;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
  };

  PointMassComponentManager();
  ~PointMassComponentManager();

  void update(float deltaTime);
  void destroy(EntityID idx);
private:
  std::vector<ComponentData> _component_data;
  std::vector<uint32_t> _index_map;
};

#endif
