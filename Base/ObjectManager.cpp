#include "ObjectManager.hpp"
#include "Game.hpp"

#include <iostream>

ObjectManager::ObjectManager(Game *game)
{
  this->game = game;
}
ObjectManager::~ObjectManager() {}

void ObjectManager::update(float deltaTime) {
  for(std::list<std::shared_ptr<Object>>::iterator it = object_list.begin();
      it != object_list.end(); it++) {
    (*it)->update(deltaTime);
  }
}

void ObjectManager::draw() {
  for(std::list<std::shared_ptr<Object>>::iterator it = object_list.begin();
      it != object_list.end(); it++) {
    (*it)->draw();
  }
}

void ObjectManager::setGame(Game *n_game) {
  game = n_game;
}

void ObjectManager::spawnObject(Object *obj) {
  //std::cout << game << std::endl;
  obj->setObjectManager(this);
  object_list.push_back(std::shared_ptr<Object>(obj));
}

Game* ObjectManager::getGame() {
  return game;
}
