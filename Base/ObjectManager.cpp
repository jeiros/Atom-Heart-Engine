#include "ObjectManager.hpp"
#include "Game.hpp"

ObjectManager::ObjectManager(Game *game)
{
  this->game = game;
}
ObjectManager::~ObjectManager() {}

void ObjectManager::update(float deltaTime) {

}

void ObjectManager::draw() {
  sf::CircleShape shape(100.f);
  game->getWindow()->draw(shape);
}

void ObjectManager::setGame(Game *n_game) {
  game = n_game;
}
