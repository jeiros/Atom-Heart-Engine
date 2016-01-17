#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

// LIB INCLUDES

// ENGINE INCLUDES
#include "../UI/UIManager.hpp"
#include "EntityManager.hpp"

class Game;
class Scene {
public:
  Scene();
  ~Scene();

  virtual void Draw();
  virtual void Update(float deltaTime);

protected:
  EntityManager em;
  UIManager uim;
};

#endif