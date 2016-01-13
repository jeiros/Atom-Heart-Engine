#ifndef __ATOMHEART_OBJECTMANAGER__
#define __ATOMHEART_OBJECTMANAGER__

#include "Object.hpp"

#include <list>
#include <memory>

class Object;
class ObjectManager {
public:
  ObjectManager(Game *game);
  ~ObjectManager();

  void update(float deltaTime);
  void draw();

  Object* spawnObject();

protected:
  // Necessitem que els punters als objectes es mantinguin valids
  // per aixo utilitzem una llista en comptes de un vector.
  // TODO: Implementar pooled list per reduir memory overhead
  std::list<Object*> object_list;

  Scene *scene;
  Game *game;
};

#endif
