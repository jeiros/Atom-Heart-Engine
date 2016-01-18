#ifndef __ATOMHEART_OBJECT_H__
#define __ATOMHEART_OBJECT_H__

// LIB INCLUDES
#include <stdint.h>

// ENGINE INCLUDES

/*! \typedef EntityID type */
typedef uint32_t EntityID;
const uint32_t ENTITY_INDEX_BITS = 22;
const uint32_t ENTITY_INDEX_MASK = (1 << ENTITY_INDEX_BITS) - 1;

const uint32_t ENTITY_GENERATION_BITS = 8;
const uint32_t ENTITY_GENERATION_MASK = (1 << ENTITY_GENERATION_BITS) - 1;

/*!
  \class Entity
  \brief Entity base class, don't extend this class
         except for adding components in its initialization.
         Never add more data to a class that extends from this one.
 */
class EntityManager;
class Entity {
  friend class EntityManager;

private:
  Entity() {};
public:
  ~Entity() {};

  /*!
    Get Entity ID.
    @return This Entity's ID
   */
  EntityID id() const {return eid;}
  /*!
    Get the index part of the Entity ID
    @return The index bits of this Entity's ID
   */
  uint32_t index() const {return eid & ENTITY_INDEX_MASK;}
  /*!
    Get the generation part of the Entity ID
    @return The generation bits of this Entity's ID
   */
  uint32_t generation() const {return (eid >> ENTITY_INDEX_BITS) & ENTITY_GENERATION_MASK;}
protected:
  EntityID eid;
};

#endif
