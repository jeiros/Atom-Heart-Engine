#include "SystemManager.hpp"

SystemManager::SystemManager() {
  systems = std::vector<System*>(sizeof(TypeId), nullptr);

  InitializeBaseSystems();
}

SystemManager::~SystemManager() {}

void SystemManager::InitializeBaseSystems() {
  Register<BaseAudioSystem>();
  Register<BaseSceneSystem>();
  Register<BaseRenderSystem>();
  Register<BaseInputSystem>();
  Register<BaseDataSystem>();
  Register<BaseStateSystem>();
}

void SystemManager::addSystem(System* sys, TypeId tid) {
  systems[tid] = sys;
}

const System& SystemManager::getSystem(TypeId tid) const {
  return *systems[tid];
}

bool SystemManager::hasSystem(TypeId tid) const {
  return systems[tid] != nullptr;
}
