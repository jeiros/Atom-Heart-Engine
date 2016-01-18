#ifndef TESTMENUSCENE
#define TESTMENUSCENE

#include "../src/Base/Scene.hpp"

class TestMenuScene : public Scene {
public:
  TestMenuScene();
  ~TestMenuScene();

  virtual void draw();
  virtual void update();
};

#endif
