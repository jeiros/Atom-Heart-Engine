#include "TestMenuScene.hpp"
#include "TestObject.hpp"

TestMenuScene::TestMenuScene() {
  om.spawnObject(new TestObject());
}

void TestMenuScene::draw() {
}

void TestMenuScene::update(float deltaTime) {
}
