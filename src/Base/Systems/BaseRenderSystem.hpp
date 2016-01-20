#ifndef __ATOMHEART_BASERENDERSYSTEM__
#define __ATOMHEART_BASERENDERSYSTEM__

// LIB INCLUDES
#include <SFML/Graphics.hpp>

// ENGINE INCLUDES
#include "System.hpp"

class BaseRenderSystem : public System {
public:
  BaseRenderSystem();
  ~BaseRenderSystem();

  void clear();
  void display();

  void SetRenderWindow(sf::RenderWindow* w);

private:
  sf::RenderWindow* _renderWindow;

  int _scrn_height;
  int _scrn_width;
};

#endif
