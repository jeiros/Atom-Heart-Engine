#ifndef __ATOMHEART_OBJECTMANAGER__
#define __ATOMHEART_OBJECTMANAGER__

// LIB INCLUDES
#include <vector>
#include <queue>

// ENGINE INCLUDES
#include "Entity.hpp"

const uint16_t MINIMUM_FREE_INDICES = 1024;

/*!
  \class EntityManager
  \brief Creates and destroys Entity (ies) in a Scene
 */
class EntityManager {
public:
  /*!
    Constructor
   */
  EntityManager();
  /*!
    Destructor
   */
  ~EntityManager();

  /*!
    Create new Entity
    @return Created Entity
   */
  Entity create();

  /*!
    Check if an Entity alive
    @param e Entity to check
    @return If the Entity is alive in the Scene
   */
  bool alive(Entity e) const;

  /*!
    Destroy Entity from the Scene
    @param e Entity to destroy
   */
  void destroy(Entity e);
private:
  std::vector<uint32_t> _generation;
  std::queue<uint32_t> _free_indices;

  Entity make_entity(int idx, int generation);
};

#endif
