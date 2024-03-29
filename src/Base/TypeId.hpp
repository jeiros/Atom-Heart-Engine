#ifndef __ATOMHEART_TYPEID__
#define __ATOMHEART_TYPEID__

#include <cstdint>

typedef int8_t TypeId;
/*!
  \class ClassTypeId
  \brief Helper class to generate unique IDs for Classes,
         used to index ComponentManagers and
         System (s)
 */
template <typename TBase>
class ClassTypeId {
public:
  /*!
    Get TypeId, the class generates a unique ID for every (TBase,T) pair.
    @return The ID of the pair
   */
  template <typename T>
  static TypeId GetTypeId()
  {
    static const TypeId id = m_nextTypeId++;
    return id;
  }
private:
  static TypeId m_nextTypeId;
};

template <typename TBase>
TypeId ClassTypeId<TBase>::m_nextTypeId = 0;

#endif
