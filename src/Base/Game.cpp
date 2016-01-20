// LIB INCLUDES
#include <string>
#include <iostream>

// ENGINE INCLUDES
#include "Game.hpp"
#include "SystemManager.hpp"

Game::Game(int scrwidth, int scrheight, std::string title, int style) :
  _window(SystemManager::Get<BaseRenderSystem>().GetMainWindow()),
  _inputSystem(SystemManager::Get<BaseInputSystem>()),
  _renderSystem(SystemManager::Get<BaseRenderSystem>())
{
  SystemManager::InitializeBaseSystems();
}

Game::~Game(){}

/*
  Game main loop
*/
void Game::run() {
  sf::Clock c;
  srand(time(0));

  while (_window.isOpen()) {
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
  SystemManager::Get<BaseStateSystem>().UpdateState(deltaTime);
}

void Game::processEvents() {
  sf::Event event;

  while(_window.pollEvent(event)) {
    switch(event.type) {
    case sf::Event::Closed:
      _window.close();
      break;
    case sf::Event::Resized:
      //TODO
      break;
    default:
      //inputManager.ParseEvent(event);
      break;
    }
  }
}

void Game::addScene(std::string name, Scene *scene) {
  SystemManager::Get<BaseSceneSystem>().AddScene(name, scene);
}

void Game::setTimeStep(float n_timestep) {
  timeStep = n_timestep;
}
