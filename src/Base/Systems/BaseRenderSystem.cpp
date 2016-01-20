#include "BaseRenderSystem.hpp"

#include <SFML/Graphics.hpp>

BaseRenderSystem::BaseRenderSystem()
{
}

BaseRenderSystem::~BaseRenderSystem() {}

void BaseRenderSystem::clear() {
  _renderWindow->clear();
}

void BaseRenderSystem::display() {
  _renderWindow->display();
}

void BaseRenderSystem::SetRenderWindow(sf::RenderWindow* w) {
  _renderWindow = w;

  _scrn_height = w->getSize().x;
  _scrn_width = w->getSize().y;
}
