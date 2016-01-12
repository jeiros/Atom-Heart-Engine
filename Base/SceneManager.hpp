#ifndef __ATOMHEART_SCENEMANAGER__
#define __ATOMHEART_SCENEMANAGER__

#include "Scene.hpp"

#include <vector>

class SceneManager {
public:
  SceneManager();
  ~SceneManager();

  int getCurrentScene();
  void switchTo(int scene_n);
  void drawScene();
  void updateScene(float deltaTime);

private:
  int current_scene = 0;
  std::vector<Scene> scenes;
};

#endif
