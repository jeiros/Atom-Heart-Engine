#include "SystemManager.hpp"

std::vector<System*> SystemManager::systems = std::vector<System*>(sizeof(TypeId), nullptr);

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

System& SystemManager::getSystem(TypeId tid) {
  return *systems[tid];
}

bool SystemManager::hasSystem(TypeId tid) {
  return systems[tid] != nullptr;
}
