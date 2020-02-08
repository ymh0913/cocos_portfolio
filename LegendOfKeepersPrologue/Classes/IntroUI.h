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
  Sprite* _btnState[5];                 // 기본 버튼
  Sprite* _btnOver[5];                  // 버튼이 덮혔을 때
  Sprite* _btnPressed[5];               // 버튼 클릭했을 때
  Sprite* _iconDiscord[2];              // 디스코드 아이콘
  Sprite* _iconReddit[2];               // 레딧 아이콘
  Sprite* _iconTwitter[2];              // 레딧 아이콘
  Sprite* _saveBorderBackground;        // 슬롯 저장창 배경
  Sprite* _saveBorderNewsaveState[3];   // 슬롯창
  Sprite* _saveBorderNewsaveHOver[3];   // 슬롯창
  Sprite* _saveBorderNewsavePressed[3]; // 슬롯창
  Sprite* _btnBackState;                // 뒤로가기 버튼
  Sprite* _btndeleteState;              // 슬롯창 삭제버튼
  Sprite* _btnConfirmState;             // 슬롯창 확인버튼
};

#endif // __INTRO_UI_H__
