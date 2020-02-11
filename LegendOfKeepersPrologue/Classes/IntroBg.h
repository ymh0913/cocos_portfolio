#ifndef __INTRO_BG_H__
#define __INTRO_BG_H__

#include "framework.h"

class IntroBg
{
 public:
  IntroBg();
  Sprite* getKeyArtBackground() { return _keyArtBackground; }
  Sprite* getLegendOfKeepersLogo() { return _legendOfKeepersLogo; }
 private:
  Sprite* _keyArtBackground;       // 배경
  Sprite* _legendOfKeepersLogo;    // 로고
};

#endif // __INTRO_BG_H__
