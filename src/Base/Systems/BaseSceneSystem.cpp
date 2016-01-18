// LIB INCLUDES
#include <algorithm>

// ENGINE INCLUDES
#include "BaseSceneSystem.hpp"

BaseSceneSystem::BaseSceneSystem() {}

BaseSceneSystem::~BaseSceneSystem() {
  std::for_each(scenes.begin(), scenes.end(),
                [](std::pair<const std::string, Scene*> p){ delete p.second; });
}

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
