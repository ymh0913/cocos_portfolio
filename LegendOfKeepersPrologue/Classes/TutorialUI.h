#ifndef __TUTORIAL_UI_H__
#define __TUTORIAL_UI_H__

#include "framework.h"

class TutorialUI
{
 public:
  TutorialUI();
  Sprite* getBtnOptions(byte i);
 private:
  Sprite* _btnOptions[3];
};

#endif // __TUTORIAL_UI_H__
