#include "Scene.hpp"
#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"
#include "Game.hpp"

Scene::Scene()
  : om(nullptr)
{}

Scene::Scene(Game *game)
  : om(game) {
  this->game = game;
}

Scene::~Scene() {}

void Scene::draw() {
  om.draw();
  uim.draw();
}

void Scene::update(float deltaTime) {
  om.update(deltaTime);
  uim.update(deltaTime);
}

sf::RenderWindow* Scene::getWindow() {
  return game->getWindow();
}

InputManager* Scene::getInputManager() {
  return game->getInputManager();
}
