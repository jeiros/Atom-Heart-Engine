#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

// LIB INCLUDES

// ENGINE INCLUDES
#include "EntityManager.hpp"

class Game;
class Scene {
public:
  Scene();
  virtual ~Scene();

  virtual void Draw();
  virtual void Update(float deltaTime);

protected:
  EntityManager em;
};

#endif
