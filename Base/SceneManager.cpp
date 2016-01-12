#include "SceneManager.hpp"

SceneManager::SceneManager() {}
SceneManager::~SceneManager() {}

int SceneManager::getCurrentScene() {
  return current_scene;
}

void SceneManager::switchTo(int scene_n) {
  current_scene = scene_n;
}

void SceneManager::drawScene() {
  scenes[current_scene].draw();
}

void SceneManager::updateScene(float deltaTime) {
  scenes[current_scene].update(deltaTime);
}
