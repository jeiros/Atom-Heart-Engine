#include "InputManager.hpp"

InputManager::InputManager(sf::RenderWindow* window) :
  window(window)
{
  initializeInputMapping();
}

InputManager::~InputManager() {
}

void InputManager::initializeInputMapping() {
  addKeyboardMapping(sf::Keyboard::K);
}

void InputManager::addKeyboardMapping(sf::Keyboard::Key input_k) {
  keyboard_map[input_k] = false;
}

void InputManager::addMouseMapping(sf::Mouse::Button input_b) {
  mouse_map[input_b] = false;
}

sf::Vector2i InputManager::getMousePosition() {
  return mousePos;
}

void InputManager::parseEvents(sf::Event event) {
  switch (event.type) {
  case sf::Event::KeyPressed:
    if (keyboard_map.count(event.key.code) > 0) {
      keyboard_map[event.key.code] = true;
    }
    break;
  case sf::Event::KeyReleased:
    if (keyboard_map.count(event.key.code) > 0) {
      keyboard_map[event.key.code] = false;
    }
    break;
  case sf::Event::MouseButtonPressed:
    if (mouse_map.count(event.mouseButton.button) > 0) {
      mouse_map[event.mouseButton.button] = true;
    }
    break;
  case sf::Event::MouseButtonReleased:
    if (mouse_map.count(event.mouseButton.button) > 0) {
      mouse_map[event.mouseButton.button] = false;
    }
    break;
  case sf::Event::MouseMoved:
    mousePos.x = event.mouseMove.x;
    mousePos.y = event.mouseMove.y;
    break;
  default:
    break;
  }
}

bool InputManager::getKeyState(sf::Keyboard::Key input_k) {
  return keyboard_map[input_k];
}

bool InputManager::getMouseState(sf::Mouse::Button input_b) {
  return mouse_map[input_b];
}
