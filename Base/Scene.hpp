#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"

class Game;
class Scene {
public:
  Scene();
  Scene(Game *game);
  ~Scene();

  void draw();
  void update(float deltaTime);

  sf::RenderWindow* getWindow();
  InputManager* getInputManager();
private:
  ObjectManager om;
  UIManager uim;

  InputManager *im;
  sf::RenderWindow *window;

  Game *game;
};

#endif
