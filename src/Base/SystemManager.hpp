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
/*!
  \class SystemManager
  \brief Manages Game System (s) in a modular way
 */
class SystemManager {
public:
  /*!
    Initialize base default systems to have a working environment
   */
  static void InitializeBaseSystems();

  /*!
    Register System with the SystemManager, if it derives from one
    of the base systems it will replace it. It is a templated
    variadic function. All arguments will get passed onto the system.
    Will throw compile time error if T is not deriving from System.
    @param args Arguments for the System T
    @return Reference to the System T
   */
  template <typename T, typename... Args>
  static T& Register(Args&&... args);

  /*!
    Get System. Will throw compile time error if T is not deriving
    from System.
    @return Reference to the System T
   */
  template <typename T>
  static T& Get();

  /*!
    Check if the SystemManager has the System T. Will throw compile
    time error if T is not deriving from System
    @return If the SystemManager has the System T
   */
  template <typename T>
  static bool Has();

private:
  static void addSystem(System* sys, TypeId tid);
  static System& getSystem(TypeId tid);
  static bool hasSystem(TypeId tid);

  template <typename T>
  static TypeId getTypeIdByBaseSystem();

  static std::vector<System*> systems;
};

template <typename T, typename... Args>
T& SystemManager::Register(Args&&... args) {
  static_assert(std::is_base_of<System, T>(),
                "T is not a System, cannot be registered with the SystemManager");
  auto system = new T{std::forward<Args>(args)...};
  TypeId tid;
  tid = getTypeIdByBaseSystem<T>();
  addSystem(system, tid);
  return *system;
}

template <typename T>
T& SystemManager::Get(){
  static_assert(std::is_base_of<System, T>(),
                "T is not a System, cannot be fetched from the SystemManager");
  return (T&)getSystem(getTypeIdByBaseSystem<T>());
}

template <typename T>
bool SystemManager::Has(){
  static_assert(std::is_base_of<System, T>(),
                "T is not a System, cannot be determined if the SystemManager has it");
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
