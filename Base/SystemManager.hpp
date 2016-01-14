#ifndef __ATOMHEART_SYSTEMMANAGER__
#define __ATOMHEART_SYSTEMMANAGER__

// LIB INCLUDES
#include <vector>

// ENGINE INCLUDES
#include "TypeId.hpp"

class System;
class SystemManager {
public:
  SystemManager();
  ~SystemManager();

  template <typename T, typename... Args>
  System& Register(Args&&... args);

  template <typename T>
  System& Get() const;

  template <typename T>
  bool Has() const;

private:
  void addSystem(System* sys, TypeId tid);
  const System& getSystem(TypeId tid) const;
  bool hasSystem(TypeId tid) const;

  std::vector<System*> systems;
};

template <typename T, typename... Args>
System& SystemManager::Register(Args&&... args) {
  static_assert(std::is_base_of<System, T>(), "T is not a System, cannot be registered with the SystemManager");
  auto system = new T{std::forward<Args>(args)...};
  addSystem(system, ClassTypeId<System>::GetTypeId<T>());
  return system;
}

template <typename T>
System& SystemManager::Get() const {
  static_assert(std::is_base_of<System, T>(), "T is not a System, cannot be fetched from the SystemManager");
  return getSystem(ClassTypeId<System>::GetTypeId<T>());
}

template <typename T>
bool SystemManager::Has() const {
  static_assert(std::is_base_of<System, T>(), "T is not a System, cannot be determined if the SystemManager has it");
  return hasSystem(ClassTypeId<System>::GetTypeId<T>());
}

#endif
