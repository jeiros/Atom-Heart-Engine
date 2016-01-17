#include "Scene.hpp"
#include "../UI/UIManager.hpp"
#include "Game.hpp"

#include <iostream>

Scene::Scene() :
  em()
{}

Scene::~Scene() {}

void Scene::Draw() {
  //em.draw();
  uim.draw();
}

void Scene::Update(float deltaTime) {
  //em.update(deltaTime);
  uim.update(deltaTime);
}
