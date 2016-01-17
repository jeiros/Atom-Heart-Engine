#ifndef __ATOMHEART_TYPEID__
#define __ATOMHEART_TYPEID__

#include <cstdint>

typedef int8_t TypeId;

template <typename TBase>
class ClassTypeId {
public:
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
