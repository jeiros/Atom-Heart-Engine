#ifndef __ATOMHEART_SYSTEMMANAGER__
#define __ATOMHEART_SYSTEMMANAGER__

// LIB INCLUDES
#include <vector>

// ENGINE INCLUDES
#include "TypeId.hpp"
#include "Systems/BaseAudioSystem.hpp"
#include "Systems/BaseSceneSystem.hpp"
#include "Systems/BaseRenderSystem.hpp"
#include "Systems/BaseInputSystem.hpp"
#include "Systems/BaseDataSystem.hpp"
#include "Systems/BaseStateSystem.hpp"

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

  template <typename T>
  TypeId getTypeIdByBaseSystem();

  std::vector<System*> systems;
};

template <typename T, typename... Args>
System& SystemManager::Register(Args&&... args) {
  static_assert(std::is_base_of<System, T>(), "T is not a System, cannot be registered with the SystemManager");
  auto system = new T{std::forward<Args>(args)...};
  TypeId tid;
  tid = getTypeIdByBaseSystem<T>();
  addSystem(system, tid);
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

template <typename T>
TypeId SystemManager::getTypeIdByBaseSystem() {
  TypeId tid;
  if(std::is_base_of<BaseAudioSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseAudioSystem>();
  }
  else if(std::is_base_of<BaseSceneSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseSceneSystem>();
  }
  else if(std::is_base_of<BaseRenderSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseRenderSystem>();
  }
  else if(std::is_base_of<BaseInputSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseInputSystem>();
  }
  else if(std::is_base_of<BaseDataSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseDataSystem>();
  }
  else if(std::is_base_of<BaseStateSystem, T>()) {
    tid = ClassTypeId<System>::GetTypeId<BaseStateSystem>();
  }
  else {
    tid = ClassTypeId<System>::GetTypeId<T>();
  }

  return tid;
}

#endif
