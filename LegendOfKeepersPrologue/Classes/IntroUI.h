#ifndef __INTRO_UI_H__
#define __INTRO_UI_H__

#include "framework.h"

class IntroUI
{
 public:
  enum eIntroUIBtnOver
  {
    kIntroUIBtnOver_Play,
    kIntroUIBtnOver_Settings,
    kIntroUIBtnOver_Modding,
    kIntroUIBtnOver_Credits,
    kIntroUIBtnOver_Quit
  };
  enum eIntroIcon
  {
    kIntroIcon_Off,
    kIntroIcon_On
  };
 public:
  IntroUI();
  Sprite* getBtnState(byte i);
  Sprite* getBtnOver(byte i);
  Sprite* getIconDiscord(byte i = 0);
  Sprite* getIconReddit(byte i = 0);
  Sprite* getIconTwitter(byte i = 0);
 private:
  Sprite* _btnState[5];     // 기본 버튼
  Sprite* _btnOver[5];      // 버튼이 덮혔을 때
  Sprite* _iconDiscord;  // 디스코드 아이콘
  Sprite* _iconReddit;   // 레딧 아이콘
  Sprite* _iconTwitter;   // 레딧 아이콘
};

#endif // __INTRO_UI_H__
