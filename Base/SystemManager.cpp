#include "SystemManager.hpp"

SystemManager::SystemManager() {
  systems = std::vector<System*>(sizeof(TypeId), nullptr);
}

SystemManager::~SystemManager() {}

void SystemManager::addSystem(System* sys, TypeId tid) {
  systems[tid] = sys;
}

const System& SystemManager::getSystem(TypeId tid) const {
  return *systems[tid];
}

bool SystemManager::hasSystem(TypeId tid) const {
  return systems[tid] != nullptr;
}
