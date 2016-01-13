#include "Scene.hpp"
#include "ObjectManager.hpp"
#include "../UI/UIManager.hpp"
#include "Game.hpp"

#include <iostream>

Scene::Scene() :
  om(nullptr)
{}

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

void Scene::setGame(Game *n_game) {
  game = n_game;
  om.setGame(n_game);
  //uim.setGame(n_game);
}
