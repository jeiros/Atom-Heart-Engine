#ifndef __ATOMHEART_BASERENDERSYSTEM__
#define __ATOMHEART_BASERENDERSYSTEM__

// LIB INCLUDES
#include <SFML/Graphics.hpp>

// ENGINE INCLUDES
#include "System.hpp"

class BaseRenderSystem : public System {
public:
  BaseRenderSystem(int scrwidth, int scrheight, std::string title);
  ~BaseRenderSystem();

  void clear();
  void display();

  sf::RenderWindow& GetMainWindow();

private:
  sf::RenderWindow mainWindow;
};

#endif
