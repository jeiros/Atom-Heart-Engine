BASEPATH = Base
HEADERPATH = Base

CONFIG += debug
TEMPLATE = app
CONFIG = console

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += $$BASEPATH/Game.hpp
HEADERS += $$BASEPATH/InputManager.hpp
HEADERS += $$BASEPATH/Object.hpp
HEADERS += $$BASEPATH/ObjectManager.hpp
HEADERS += $$BASEPATH/Scene.hpp
HEADERS += $$BASEPATH/SystemManager.hpp
HEADERS += $$BASEPATH/Systems/System.hpp
HEADERS += $$BASEPATH/Systems/BaseAudioSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseDataSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseInputSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseRenderSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseStateSystem.hpp

SOURCES += $$BASEPATH/Game.cpp
SOURCES += $$BASEPATH/InputManager.cpp
SOURCES += $$BASEPATH/Object.cpp
SOURCES += $$BASEPATH/ObjectManager.cpp
SOURCES += $$BASEPATH/Scene.cpp
SOURCES += $$BASEPATH/SystemManager.cpp
SOURCES += $$BASEPATH/Systems/System.cpp
SOURCES += $$BASEPATH/Systems/BaseAudioSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseDataSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseInputSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseRenderSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseStateSystem.cpp
