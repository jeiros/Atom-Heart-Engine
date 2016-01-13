#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Game.hpp"

SceneManager::SceneManager(Game *game) {
  this->game = game;

  scenes = std::vector<Scene>(6);

  current_scene = 0;
  scenes[0] = Scene(game);
}

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

sf::RenderWindow* SceneManager::getWindow() {
  return game->getWindow();
}

InputManager* SceneManager::getInputManager() {
  return game->getInputManager();
}
