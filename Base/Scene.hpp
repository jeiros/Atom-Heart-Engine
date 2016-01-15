#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"

class Game;
class Scene {
public:
  Scene();
  ~Scene();

  virtual void draw();
  virtual void update(float deltaTime);

  void setGame(Game *n_game);
protected:
  ObjectManager om;
  UIManager uim;

  Game *game;
};

#endif
