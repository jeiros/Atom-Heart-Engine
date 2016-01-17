#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"

class Game;
class Scene {
public:
  Scene();
  ~Scene();

  virtual void Draw();
  virtual void Update(float deltaTime);

protected:
  ObjectManager om;
  UIManager uim;
};

#endif
