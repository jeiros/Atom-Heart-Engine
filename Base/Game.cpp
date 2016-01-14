// LIB INCLUDES
#include <string>
#include <iostream>

// ENGINE INCLUDES
#include "Game.hpp"
#include "Resources.hpp"
#include "SystemManager.hpp"

Game::Game(int scrwidth, int scrheight, std::string title, int style)
{
  SystemManager::InitializeBaseSystems();
  Resources::load();
}

Game::~Game(){}

/*
  Game main loop
*/
void Game::run() {
  sf::Clock c;
  srand(time(0));

  while (SystemManager::Get<BaseRenderSystem>().GetMainWindow().isOpen()) {
    float deltaTime = c.restart().asSeconds();

    processEvents();
    // TODO: Implement fixed timestep
    update(deltaTime);
    render();
  }
}

void Game::render() {
  SystemManager::Get<BaseRenderSystem>().clear();
  SystemManager::Get<BaseSceneSystem>().DrawScene();
  SystemManager::Get<BaseRenderSystem>().display();
}

void Game::update(float deltaTime) {
  SystemManager::Get<BaseSceneSystem>().UpdateScene(deltaTime);
}

void Game::processEvents() {
  sf::Event event;
  while(SystemManager::Get<BaseRenderSystem>().GetMainWindow().pollEvent(event)) {
    switch(event.type) {
    case sf::Event::Closed:
      SystemManager::Get<BaseRenderSystem>().GetMainWindow().close();
      break;
    case sf::Event::Resized:
      //TODO
      break;
    default:
      //inputManager.parseEvent(event);
      break;
    }
  }
}

void Game::addScene(Scene *scene) {
  SystemManager::Get<BaseSceneSystem>().AddScene(scene);
}

void Game::setTimeStep(float n_timestep) {
  timeStep = n_timestep;
}
