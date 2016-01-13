#include "ObjectManager.hpp"
#include "Game.hpp"

#include <stdio.h>

ObjectManager::ObjectManager(Game *game)
{
  this->game = game;
}
ObjectManager::~ObjectManager() {}

void ObjectManager::update(float deltaTime) {

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
  obj->setGame(game);
  object_list.push_back(std::shared_ptr<Object>(obj));
}
