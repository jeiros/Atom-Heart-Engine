#include "ObjectManager.hpp"
#include "Game.hpp"

ObjectManager::ObjectManager(Game *game)
{
  this->game = game;

  //object_list = std::list<Object*>();
}
ObjectManager::~ObjectManager() {}

void ObjectManager::update(float deltaTime) {

}

void ObjectManager::draw() {
  sf::CircleShape shape(100.f);
  game->getWindow()->draw(shape);
}
