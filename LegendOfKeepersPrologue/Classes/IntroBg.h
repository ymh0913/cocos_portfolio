#ifndef __INTRO_BG_H__
#define __INTRO_BG_H__

#include "framework.h"

class IntroBg
{
 public:
  IntroBg();
  Sprite* getKeyArtBackground() { return _keyArtBackground; }
  Sprite* getLegendOfKeepersLogo() { return _legendOfKeepersLogo; }
  Sprite* getSaveBorderBackground() { return _saveBorderBackground; }
 private:
  Sprite* _keyArtBackground;       // 배경
  Sprite* _legendOfKeepersLogo;    // 로고
  Sprite* _saveBorderBackground;   // 저장경계 배경
};

#endif // __INTRO_BG_H__
