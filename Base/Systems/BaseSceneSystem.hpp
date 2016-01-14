#ifndef __ATOMHEART_BASESCENESYSTEM__
#define __ATOMHEART_BASESCENESYSTEM__

// LIB INCLUDES

// ENGINE INCLUDES
#include "System.hpp"
#include "../Scene.hpp"

class BaseSceneSystem : public System {
public:
  BaseSceneSystem();
  ~BaseSceneSystem();

  void DrawScene();
  void UpdateScene(float deltaTime);
  void AddScene(Scene *scene);
};

#endif
