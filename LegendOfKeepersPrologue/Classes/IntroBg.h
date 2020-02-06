#ifndef __INTRO_BG_H__
#define __INTRO_BG_H__

#include "framework.h"

class IntroBg
{
 public:
  IntroBg();
  Sprite* getKeyArtBackground() { return _keyArtBackground; }
  Sprite* getLegendOfKeepersLogo() { return _Legend_Of_Keepers_Logo; }
 private:
  Sprite* _keyArtBackground;          // 배경
  Sprite* _Legend_Of_Keepers_Logo;    // 로고
};

#endif // __INTRO_BG_H__
