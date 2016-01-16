#include "BaseSceneSystem.hpp"

BaseSceneSystem::BaseSceneSystem() {}

BaseSceneSystem::~BaseSceneSystem() {}

void BaseSceneSystem::DrawScene() {
  current_scene->Draw();
}

void BaseSceneSystem::UpdateScene(float deltaTime) {
  current_scene->Update(deltaTime);
}

void BaseSceneSystem::AddScene(std::string name, Scene *scene) {
  scenes[name] = scene;
}

void BaseSceneSystem::SwitchTo(std::string name) {
  current_scene = scenes[name];
}
