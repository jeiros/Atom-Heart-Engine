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

  void PlaySound();
  void PlayMusic();
  void StopMusic();
  void PauseMusic();
  void SetLoop();
  void SetPitch();
  void SetVolume();
  void SetPosition();
  void SetGlobalSoundVolume();
  void SetGlobalMusicVolume();

private:
};

#endif
