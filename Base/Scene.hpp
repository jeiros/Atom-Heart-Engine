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

  sf::RenderWindow* getWindow();
  InputManager* getInputManager();

  void setGame(Game *n_game);
protected:
  ObjectManager om;
  UIManager uim;

  InputManager *im;
  sf::RenderWindow *window;

  Game *game;
};

#endif
