#ifndef __ATOMHEART_GAME_H__
#define __ATOMHEART_GAME_H__

// LIB INCLUDES
#include <string>

// ENGINE INCLUDES 

class Scene;
class Game
{
 public:
  Game(int scrwidth, int scrheight, std::string title, int style);
  ~Game();

  void run();

  void setTimeStep(float n_timestep);
  void addScene(std::string name, Scene *scene);
private:
  float timeStep;

  void render();
  void update(float deltaTime);
  void processEvents();
  void draw();
};

#endif
