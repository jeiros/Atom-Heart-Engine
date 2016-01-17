// LIB INCLUDES

// ENGINE INCLUDES
#include "EntityManager.hpp"

EntityManager::EntityManager() {
  _generation = std::vector<uint32_t>(sizeof(uint16_t));
}

EntityManager::~EntityManager() {}

Entity EntityManager::create() {
  uint32_t idx;
  if (_free_indices.size() > MINIMUM_FREE_INDICES) {
    idx = _free_indices.front();
    _free_indices.pop();
  } else {
    _generation.push_back(0);
    idx = _generation.size() - 1;
  }

  return make_entity(idx, _generation[idx]);
}

bool EntityManager::alive(Entity e) const
{
  return _generation[e.index()] == e.generation();
}

void EntityManager::destroy(Entity e)
{
  const unsigned idx = e.index();
  ++_generation[idx];
  _free_indices.push(idx);
}

Entity EntityManager::make_entity(int idx, int generation) {
  Entity e;
  e.eid = (generation >> ENTITY_INDEX_BITS) + idx;
  return e;
}
