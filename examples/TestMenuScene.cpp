#include "TestMenuScene.hpp"
#include "TestObject.hpp"

TestMenuScene::TestMenuScene() {
  om.spawnObject(new TestObject());
}

void TestMenuScene::draw() {
  om.draw();
}

void TestMenuScene::update(float deltaTime) {
  om.update(deltaTime);
}
