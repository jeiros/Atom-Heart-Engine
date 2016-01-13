#include "Game.hpp"
#include "Resources.hpp"

#include <string>

Game::Game(int scrwidth, int scrheight, std::string title, int style) :
  window(sf::VideoMode(scrwidth, scrheight), title, style),
  inputManager(&window),
  sm(this)
{
  Resources::load();
}

Game::~Game(){}

/*
  Game main loop
*/
void Game::run() {
  sf::Clock c;
  srand(time(0));

  while (window.isOpen()) {
    float deltaTime = c.restart().asSeconds();

    processEvents();
    // TODO: Implement fixed timestep
    update(deltaTime);
    render();
  }
}

void Game::render() {
  window.clear();
  sm.drawScene();
  window.display();
}

void Game::update(float deltaTime) {
  sm.updateScene(deltaTime);
}

void Game::processEvents() {
  sf::Event event;
  while(window.pollEvent(event)) {
    switch(event.type) {
    case sf::Event::Closed:
      window.close();
      break;
    case sf::Event::Resized:
      //TODO
      break;
    default:
      inputManager.parseEvent(event);
    }
  }
}

void Game::addScene(Scene *scene) {
  scene->setGame(this);
  sm.addScene(scene);
}

InputManager* Game::getInputManager() {
  return &inputManager;
}

sf::RenderWindow* Game::getWindow() {
  return &window;
}

void Game::setTimeStep(float n_timestep) {
  timeStep = n_timestep;
}
