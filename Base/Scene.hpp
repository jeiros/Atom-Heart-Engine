#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"

class Scene {
public:
  Scene();
  ~Scene();

  void draw();
  void update(float deltaTime);
private:
  ObjectManager om;
  UIManager uim;

  InputManager *im;
  sf::RenderWindow *window;

  Game *game;
};

#endif
