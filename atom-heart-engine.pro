BASEPATH = src/Base
HEADERPATH = src/Base

CONFIG += debug
TEMPLATE = app
CONFIG += console
CONFIG -= qt

QT     -= gui core
LIBS   -= -lQtGui -lQtCore
LIBS   += -lsfml-graphics -lsfml-window -lsfml-system

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += $$BASEPATH/Game.hpp
HEADERS += $$BASEPATH/Entity.hpp
HEADERS += $$BASEPATH/EntityManager.hpp
HEADERS += $$BASEPATH/Scene.hpp
HEADERS += $$BASEPATH/SystemManager.hpp
HEADERS += $$BASEPATH/Systems/System.hpp
HEADERS += $$BASEPATH/Systems/BaseAudioSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseDataSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseInputSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseRenderSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseStateSystem.hpp
HEADERS += $$BASEPATH/Systems/BaseSceneSystem.hpp

SOURCES += $$BASEPATH/Game.cpp
SOURCES += $$BASEPATH/EntityManager.cpp
SOURCES += $$BASEPATH/Scene.cpp
SOURCES += $$BASEPATH/SystemManager.cpp
SOURCES += $$BASEPATH/Systems/System.cpp
SOURCES += $$BASEPATH/Systems/BaseAudioSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseDataSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseInputSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseRenderSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseStateSystem.cpp
SOURCES += $$BASEPATH/Systems/BaseSceneSystem.cpp
