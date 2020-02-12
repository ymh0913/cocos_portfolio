#ifndef __INTRO_UI_H__
#define __INTRO_UI_H__

#include "framework.h"

class IntroUI
{
 public:
  // 인트로화면에서 선택한 버튼을 저장할 상수
  enum eSelectBtn
  {
    kSelectBtn_False,
    kSelectBtn_Play,
    kSelectBtn_Settings,
    kSelectBtn_Modding,
    kSelectBtn_Credits,
    kSelectBtn_Quit,
    kSelectBtn_Create
  };
  // 디스코드 페이스북 트위터 아이콘 버튼 클릭
  enum eIcon
  {
    kIcon_Discord,
    kIcon_Reddit,
    kIcon_Twitter,
    kIcon_Facebook
  };
  enum eSaveBorderNewsave
  {
    kSaveBorderNewsave_Top,
    kSaveBorderNewsave_Middle,
    kSaveBorderNewsave_Bottom
  };
 public:
  IntroUI();
  Sprite* getBtnPlay(byte i);
  Sprite* getBtnSettings(byte i);
  Sprite* getBtnModding(byte i);
  Sprite* getBtnCredits(byte i);
  Sprite* getBtnQuit(byte i);
  Sprite* getIconDiscord(byte i);
  Sprite* getIconReddit(byte i);
  Sprite* getIconTwitter(byte i);
  Sprite* getIconFacebook(byte i);
  Sprite* getSaveBorderNewsaveTop(byte i);
  Sprite* getSaveBorderNewsaveMiddle(byte i);
  Sprite* getSaveBorderNewsaveBottom(byte i);
  Sprite* getBtnBack(byte i);
  Sprite* getBtnDelete(byte i);
  Sprite* getBtnCreate(byte i);
  Sprite* getBtnNo(byte i);
  Sprite* getBtnYes(byte i);
 private:
  Sprite* _btnPlay[3];                    // Play 버튼
  Sprite* _btnSettings[3];                // Settings 버튼
  Sprite* _btnModding[3];                 // Modding 버튼
  Sprite* _btnCredits[3];                 // Credits 버튼
  Sprite* _btnQuit[3];                    // Quit 버튼
  Sprite* _iconDiscord[2];                // 디스코드 아이콘
  Sprite* _iconReddit[2];                 // 레딧 아이콘
  Sprite* _iconTwitter[2];                // 트위터 아이콘
  Sprite* _iconFacebook[2];               // 페이스북 아이콘
  Sprite* _saveBorderNewsaveTop[3];       // 슬롯창
  Sprite* _saveBorderNewsaveMiddle[3];    // 슬롯창
  Sprite* _saveBorderNewsaveBottom[3];    // 슬롯창
  Sprite* _btnBack[3];                    // 뒤로가기 버튼
  Sprite* _btnDelete[3];                  // 슬롯창 삭제버튼
  Sprite* _btnCreate[3];                  // 슬롯창 확인버튼
  Sprite* _btnNo[3];                      // No 버튼
  Sprite* _btnYes[3];                     // Yes 버튼
};

#endif // __INTRO_UI_H__
