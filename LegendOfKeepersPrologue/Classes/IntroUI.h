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
  enum eIntroUIBtn
  {
    kIntroUIBtn_Play,
    kIntroUIBtn_Settings,
    kIntroUIBtn_Modding,
    kIntroUIBtn_Credits,
    kIntroUIBtn_Quit
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
  Sprite* getBtnPressed(byte i);
  Sprite* getIconDiscord(byte i);
  Sprite* getIconReddit(byte i);
  Sprite* getIconTwitter(byte i);
  Sprite* getSaveBorderBackground();
  Sprite* getSaveBorderNewsaveState(byte i);
  Sprite* getSaveBorderNewsaveHOver(byte i);
  Sprite* getSaveBorderNewsavePressed(byte i);
  Sprite* getBtnBackState();
  Sprite* getBtndeleteState();
  Sprite* getBtnConfirmState();
 private:
  Sprite* _btnState[5];                 // �⺻ ��ư
  Sprite* _btnOver[5];                  // ��ư�� ������ ��
  Sprite* _btnPressed[5];               // ��ư Ŭ������ ��
  Sprite* _iconDiscord[2];              // ���ڵ� ������
  Sprite* _iconReddit[2];               // ���� ������
  Sprite* _iconTwitter[2];              // ���� ������
  Sprite* _saveBorderBackground;        // ���� ����â ���
  Sprite* _saveBorderNewsaveState[3];   // ����â
  Sprite* _saveBorderNewsaveHOver[3];   // ����â
  Sprite* _saveBorderNewsavePressed[3]; // ����â
  Sprite* _btnBackState;                // �ڷΰ��� ��ư
  Sprite* _btndeleteState;              // ����â ������ư
  Sprite* _btnConfirmState;             // ����â Ȯ�ι�ư
};

#endif // __INTRO_UI_H__
