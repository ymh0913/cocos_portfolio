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
  Sprite* _keyArtBackground;       // ���
  Sprite* _legendOfKeepersLogo;    // �ΰ�
};

#endif // __INTRO_BG_H__
