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
  Sprite* getTutorialBorderBackground() { return _tutorialBorderBackground; }
 private:
  Sprite* _keyArtBackground;          // ���
  Sprite* _legendOfKeepersLogo;       // �ΰ�
  Sprite* _saveBorderBackground;      // ������ ���
  Sprite* _tutorialBorderBackground;  // Ʃ�丮�� ���
};

#endif // __INTRO_BG_H__
