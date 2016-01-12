#include "Scene.hpp"

Scene::Scene() {}
Scene::~Scene() {}

void Scene::draw() {
  om.draw();
  uim.draw();
}

void Scene::update(float deltaTime) {
  om.update(deltaTime);
  uim.update(deltaTime);
}
