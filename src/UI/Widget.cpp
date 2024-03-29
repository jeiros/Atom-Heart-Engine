#include "Widget.hpp"

namespace UI {
  Widget::Widget(sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount)
    : Object(size, tex, spriteCount) {

  }

  Widget::~Widget() {
  }

  void Widget::setCallback(std::function<void()> delegate) {
    this->delegate = delegate;
  }

  void Widget::update(float deltaTime) {
    if (active) {
      delegate();
    }
  }

  void Widget::setActive(bool a) {
    active = a;
  }
}
