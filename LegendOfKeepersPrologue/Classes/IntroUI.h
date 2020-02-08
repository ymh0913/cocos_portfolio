#ifndef __INTRO_UI_H__
#define __INTRO_UI_H__

#include "framework.h"

class IntroUI
{
 public:
  enum eSelectBtn
  {
    kSelectBtn_False,
    kSelectBtn_Play,
    kSelectBtn_Settings,
    kSelectBtn_Modding,
    kSelectBtn_Credits,
    kSelectBtn_Quit
  };
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
  enum eSaveBorderNewsave
  {
    kSaveBorderNewsave_Top,
    kSaveBorderNewsave_Middle,
    kSaveBorderNewsave_Bottom
  };
 public:
  IntroUI();
  Sprite* getBtnState(byte i);
  Sprite* getBtnOver(byte i);
  Sprite* getIconDiscord(byte i);
  Sprite* getIconReddit(byte i);
  Sprite* getIconTwitter(byte i);
  Sprite* getSaveBorderBackground();
  Sprite* getSaveBorderNewsaveState(byte i);
  Sprite* getSaveBorderNewsaveHOver(byte i);
  Sprite* getSaveBorderNewsavePressed(byte i);
  Sprite* getBtndeleteState();
 private:
  Sprite* _btnState[5];                 // �⺻ ��ư
  Sprite* _btnOver[5];                  // ��ư�� ������ ��
  Sprite* _iconDiscord[2];              // ���ڵ� ������
  Sprite* _iconReddit[2];               // ���� ������
  Sprite* _iconTwitter[2];              // ���� ������
  Sprite* _saveBorderBackground;        // ���� ����â ���
  Sprite* _saveBorderNewsaveState[3];   // ����â
  Sprite* _saveBorderNewsaveHOver[3];   // ����â
  Sprite* _saveBorderNewsavePressed[3]; // ����â
  Sprite* _btndeleteState;              // ����â ����
};

#endif // __INTRO_UI_H__
