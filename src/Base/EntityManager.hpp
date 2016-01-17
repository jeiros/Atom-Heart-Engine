#ifndef __ATOMHEART_OBJECTMANAGER__
#define __ATOMHEART_OBJECTMANAGER__

// LIB INCLUDES
#include <vector>
#include <queue>

// ENGINE INCLUDES
#include "Entity.hpp"

const uint16_t MINIMUM_FREE_INDICES = 1024;

class EntityManager {
public:
  EntityManager();
  ~EntityManager();

  Entity create();
  bool alive(Entity e) const;
  void destroy(Entity e);
private:
  std::vector<uint32_t> _generation;
  std::queue<uint32_t> _free_indices;

  Entity make_entity(int idx, int generation);
};

#endif
