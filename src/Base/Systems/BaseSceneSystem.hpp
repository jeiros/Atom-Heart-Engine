#ifndef __ATOMHEART_BASESCENESYSTEM__
#define __ATOMHEART_BASESCENESYSTEM__

// LIB INCLUDES
#include <unordered_map>

// ENGINE INCLUDES
#include "System.hpp"
#include "../Scene.hpp"

class BaseSceneSystem : public System {
public:
  BaseSceneSystem();
  ~BaseSceneSystem();

  void DrawScene();
  void UpdateScene(float deltaTime);
  void SwitchTo(std::string name);
  void AddScene(std::string name, Scene *scene);

private:
  Scene* current_scene;
  std::unordered_map<std::string, Scene*> scenes;
};

#endif
