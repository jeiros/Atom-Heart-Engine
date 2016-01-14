#ifndef __ATOMHEART_OBJECT_H__
#define __ATOMHEART_OBJECT_H__

// LIB INCLUDES
#include <SFML/Graphics.hpp>
#include <vector>
#include <type_traits>

// ENGINE INCLUDES
#include "Component.hpp"
#include "TypeId.hpp"

class ObjectManager;
class Scene;
class Object {
public:
  Object();
  ~Object();

  virtual void update(float deltaTime) = 0;

  void kill();

  template <typename T, typename... Args>
  T& addComponent(Args&&... args);

  template <typename T>
  void removeComponent();

  template <typename T>
  T& getComponent() const;

  template <typename T>
  bool hasComponent() const;

protected:
  void addComponent(Component* comp, TypeId tid);
  void removeComponent(TypeId tid);
  const Component& getComponent(TypeId tid) const;
  bool hasComponent(TypeId tid) const;

  std::vector<Component*> components;
};

template <typename T, typename... Args>
T& Object::addComponent(Args&&... args)
{
  static_assert(std::is_base_of<Component, T>(), "T is not a component, cannot add T to entity");
  auto component = new T{std::forward<Args>(args)...};
  addComponent(component, ClassTypeId<Component>::GetTypeId<T>());
  return *component;
}

template <typename T>
void Object::removeComponent() {
  static_assert(std::is_base_of<Component, T>(), "T is not a component, cannot remove T from entity");
  removeComponent(ClassTypeId<Component>::GetTypeId<T>());
}

template <typename T>
T& Object::getComponent() const {
  static_assert(std::is_base_of<Component, T>(), "T is not a component, cannot get T from entity");
  return getComponent(ClassTypeId<Component>::GetTypeId<T>());
}

template <typename T>
bool Object::hasComponent() const {
  static_assert(std::is_base_of<Component, T>(), "T is not a component, cannot determine if entity has T");
  return hasComponent(ClassTypeId<Component>::GetTypeId<T>());
}
#endif
