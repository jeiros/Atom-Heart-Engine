#ifndef __ATOMHEART_GAME_H__
#define __ATOMHEART_GAME_H__

#include "InputManager.hpp"
#include "SceneManager.hpp"

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(int scrwidth, int scrheight, std::string title, int style);
  ~Game();

  void run();

  InputManager*       getInputManager();
  sf::RenderWindow*   getWindow();
private:
  SceneManager sm;
  InputManager        inputManager;
  sf::RenderWindow    window;

  void render();
  void update(float deltaTime);
  void processEvents();
  void draw();
};

#endif
