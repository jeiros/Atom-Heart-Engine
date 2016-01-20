#ifndef __ATOMHEART_BASECOMPONENT__
#define __ATOMHEART_BASECOMPONENT__

// LIB INCLUDES

// ENGINE INCLUDES
#include "../Entity.hpp"

class BaseComponentManager {
  BaseComponentManager();
  ~BaseComponentManager();

  virtual void update(float deltaTime);
};

#endif
