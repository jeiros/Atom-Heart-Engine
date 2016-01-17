#ifndef __ATOMHEART_OBJECT_H__
#define __ATOMHEART_OBJECT_H__

// LIB INCLUDES
#include <stdint.h>

// ENGINE INCLUDES

typedef uint32_t EntityID;
const uint32_t ENTITY_INDEX_BITS = 22;
const uint32_t ENTITY_INDEX_MASK = (1 << ENTITY_INDEX_BITS) - 1;

const uint32_t ENTITY_GENERATION_BITS = 8;
const uint32_t ENTITY_GENERATION_MASK = (1 << ENTITY_GENERATION_BITS) - 1;

class EntityManager;
class Entity {
  friend class EntityManager;
public:
  Entity() {};
  ~Entity() {};

  EntityID id() const {return eid;}
  uint32_t index() const {return eid & ENTITY_INDEX_MASK;}
  uint32_t generation() const {return (eid >> ENTITY_INDEX_BITS) & ENTITY_GENERATION_MASK;}
protected:
  EntityID eid;
};

#endif
