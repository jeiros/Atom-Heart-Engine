// LIB INCLUDES
#include <utility>

// ENGINE INCLUDES
#include "PointMassComponent.hpp"

PointMassComponentManager::PointMassComponentManager() {
  _component_data = std::vector<ComponentData>();
  _index_map = std::vector<uint32_t>();
}

PointMassComponentManager::~PointMassComponentManager() {}

void PointMassComponentManager::update(float deltaTime) {
  for (unsigned i = 0; i < _component_data.size(); ++i) {
    _component_data[i].velocity += _component_data[i].acceleration * deltaTime;
    _component_data[i].position += _component_data[i].velocity * deltaTime;
  }
}

void PointMassComponentManager::destroy(EntityID id) {
  Entity id_e = _component_data[_index_map[id]].entity;
  Entity last_e = _component_data[_component_data.size()-1].entity;

  std::swap(_component_data[_index_map[id]], _component_data[_component_data.size() - 1]);
  _component_data.erase(_component_data.end());

  _index_map[last_e.id()] = _index_map[id];
}
