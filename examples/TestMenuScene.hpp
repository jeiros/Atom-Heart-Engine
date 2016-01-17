#ifndef TESTMENUSCENE
#define TESTMENUSCENE

#include "Base/Scene.hpp"

class TestMenuScene : public Scene {
public:
  TestMenuScene();
  ~TestMenuScene();

  virtual void draw();
  virtual void update(float deltaTime);
};

#endif
