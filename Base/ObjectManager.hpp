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

  void spawnObject(Object *obj);

  void setGame(Game *game);
protected:
  // Necessitem que els punters als objectes es mantinguin valids
  // per aixo utilitzem una llista en comptes de un vector.
  // TODO: Implementar pooled list per reduir memory overhead
  std::list<std::shared_ptr<Object>> object_list;

  Scene *scene;
  Game *game;
};

#endif
