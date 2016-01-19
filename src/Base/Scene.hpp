#ifndef __ATOMHEART_SCENE__
#define __ATOMHEART_SCENE__

// LIB INCLUDES

// ENGINE INCLUDES
#include "EntityManager.hpp"

/*!
  \class Scene
  \brief Each Scene represents a different world, with different Entity (ies)
 */
class Scene {
public:
  /*!
    Constructor
  */
  Scene();

  /*!
    Destructor.
    Must override
  */
  virtual ~Scene();

  /*!
    Update scene data.
    @param deltaTime Amount of time since last execution
   */
  virtual void update(float deltaTime);

protected:
  EntityManager em;
};

#endif
