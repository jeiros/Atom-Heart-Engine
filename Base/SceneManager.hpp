#ifndef __ATOMHEART_SCENEMANAGER__
#define __ATOMHEART_SCENEMANAGER__

#include "Scene.hpp"

#include <vector>

class Game;
class InputManager;
class SceneManager {
public:
  SceneManager(Game *game);
  ~SceneManager();

  int getCurrentScene();
  void switchTo(int scene_n);
  void drawScene();
  void updateScene(float deltaTime);

  void addScene(Scene *scene);

private:
  int current_scene = 0;
  std::vector<std::shared_ptr<Scene>> scenes;

  Game *game;
};

#endif
