#ifndef __ATOMHEART_UIMANAGER__
#define __ATOMHEART_UIMANAGER__

class Game;
class UIManager {
public:
  UIManager();
  ~UIManager();

  void draw();
  void update(float deltaTime);

  void setGame(Game *game);
};

#endif

