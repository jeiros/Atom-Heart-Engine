#ifndef __ATOMHEART_BASEAUDIOSYSTEM__
#define __ATOMHEART_BASEAUDIOSYSTEM__

// LIB INCLUDES
#include <SFML/Audio.hpp>

// ENGINE INCLUDES
#include "System.hpp"

class BaseAudioSystem : public System  {
public:
  BaseAudioSystem();
  ~BaseAudioSystem();

  virtual void PlaySound();
  virtual void PlayMusic();
  virtual void StopMusic();
  virtual void PauseMusic();
  virtual void SetLoop();
  virtual void SetPitch();
  virtual void SetVolume();
  virtual void SetPosition();
  virtual void SetGlobalSoundVolume();
  virtual void SetGlobalMusicVolume();

private:
};

#endif
