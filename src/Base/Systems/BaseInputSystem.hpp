#ifndef __ATOMHEART_BASEINPUTSYSTEM__
#define __ATOMHEART_BASEINPUTSYSTEM__

// LIB INCLUDES
#include <SFML/Graphics.hpp>

// ENGINE INCLUDES
#include "System.hpp"

class BaseInputSystem : public System{
public:
  BaseInputSystem();
  ~BaseInputSystem();

  void ParseEvent(sf::Event e);
};

#endif
