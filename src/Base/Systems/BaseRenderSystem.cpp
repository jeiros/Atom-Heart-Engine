#include "BaseRenderSystem.hpp"

#include <SFML/Graphics.hpp>

BaseRenderSystem::BaseRenderSystem(int scrwidth, int scrheight, std::string title)
  : mainWindow(sf::VideoMode(scrwidth, scrheight), title)
{
}

BaseRenderSystem::~BaseRenderSystem() {}

void BaseRenderSystem::clear() {
  mainWindow.clear();
}

void BaseRenderSystem::display() {
  mainWindow.display();
}

sf::RenderWindow& BaseRenderSystem::GetMainWindow() {
  return mainWindow;
}
