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
  Sprite* _btnState[5];     // �⺻ ��ư
  Sprite* _btnOver[5];      // ��ư�� ������ ��
  Sprite* _iconDiscord;  // ���ڵ� ������
  Sprite* _iconReddit;   // ���� ������
  Sprite* _iconTwitter;   // ���� ������
};

#endif // __INTRO_UI_H__
