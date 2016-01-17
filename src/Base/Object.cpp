#include "Object.hpp"

Object::Object() {
  components = std::vector<Component*>(sizeof(TypeId), nullptr);
}

void Object::kill() {
  // TODO
}

void Object::addComponent(Component* comp, TypeId tid) {
  components[tid] = comp;
}

void Object::removeComponent(TypeId tid) {
  delete components[tid];
  components[tid] = nullptr;
}

const Component& Object::getComponent(TypeId tid) const {
  return *components[tid];
}

bool Object::hasComponent(TypeId tid) const {
  return components[tid] != nullptr;
}
