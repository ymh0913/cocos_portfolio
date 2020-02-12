#ifndef __INTRO_UI_H__
#define __INTRO_UI_H__

#include "framework.h"

class IntroUI
{
 public:
  // ��Ʈ��ȭ�鿡�� ������ ��ư�� ������ ���
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
  // ���ڵ� ���̽��� Ʈ���� ������ ��ư Ŭ��
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
  Sprite* _btnPlay[3];                    // Play ��ư
  Sprite* _btnSettings[3];                // Settings ��ư
  Sprite* _btnModding[3];                 // Modding ��ư
  Sprite* _btnCredits[3];                 // Credits ��ư
  Sprite* _btnQuit[3];                    // Quit ��ư
  Sprite* _iconDiscord[2];                // ���ڵ� ������
  Sprite* _iconReddit[2];                 // ���� ������
  Sprite* _iconTwitter[2];                // Ʈ���� ������
  Sprite* _iconFacebook[2];               // ���̽��� ������
  Sprite* _saveBorderNewsaveTop[3];       // ����â
  Sprite* _saveBorderNewsaveMiddle[3];    // ����â
  Sprite* _saveBorderNewsaveBottom[3];    // ����â
  Sprite* _btnBack[3];                    // �ڷΰ��� ��ư
  Sprite* _btnDelete[3];                  // ����â ������ư
  Sprite* _btnCreate[3];                  // ����â Ȯ�ι�ư
  Sprite* _btnNo[3];                      // No ��ư
  Sprite* _btnYes[3];                     // Yes ��ư
};

#endif // __INTRO_UI_H__
