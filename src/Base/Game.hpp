#ifndef __ATOMHEART_GAME_H__
#define __ATOMHEART_GAME_H__

// LIB INCLUDES
#include <string>
#include <SFML/Graphics.hpp>

// ENGINE INCLUDES
#include "Systems/BaseInputSystem.hpp"
#include "Systems/BaseRenderSystem.hpp"

class Scene;
/*!
  \class Game
  \brief Base game class, initializes Systems and runs game loop
 */
class Game
{
 public:
  /*!
    Constructor
    @param scrwidth Window screen width
    @param scrheight Window screen height
    @param title Window title
    @param style Window style
   */
  Game(int scrwidth, int scrheight, std::string title, int style);
  ~Game();

  /*!
    Run game loop
   */
  void run();

  /*!
    Set a fixed timestep for the game loop
    @param n_timestep Amount in milliseconds
   */
  void setTimeStep(float n_timestep);

  // Potser es treuen, no documentarles de moment
  void addScene(std::string name, Scene *scene);
  void setInitialScene(std::string name);
private:
  float timeStep;
  sf::RenderWindow& _window;
  BaseInputSystem& _inputSystem;
  BaseRenderSystem& _renderSystem;

  void render();
  void update(float deltaTime);
  void processEvents();
  void draw();
};

#endif
