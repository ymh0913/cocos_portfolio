#ifndef __INTRO_UI_H__
#define __INTRO_UI_H__

#include "framework.h"

class IntroUI
{
 public:
  IntroUI();
  Sprite* getBtnState(byte i) {
    if (i == 0) {
      return _btnState[0];
    } else if (i == 1) {
      return _btnState[1];
    } else if (i == 2) {
      return _btnState[2];
    } else if (i == 3) {
      return _btnState[3];
    } else {
      return _btnState[4];
    }
  }
 private:
  Sprite* _btnState[5];  // ¹öÆ°
};

#endif // __INTRO_UI_H__
