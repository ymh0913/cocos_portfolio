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
  Sprite* _keyArtBackground;       // ���
  Sprite* _legendOfKeepersLogo;    // �ΰ�
  Sprite* _saveBorderBackground;   // ������ ���
};

#endif // __INTRO_BG_H__
