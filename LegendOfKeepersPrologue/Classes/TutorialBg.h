#ifndef __TUTORIAL_BG_H__
#define __TUTORIAL_BG_H__

#include "framework.h"

class TutorialBg
{
 public:
  TutorialBg();
  Sprite* getBgDungeonRoom() { return _bgDungeonRoom; }
  Sprite* getDRH() { return _dRH; }
  Sprite* getDRHSpeak() { return _dRHSpeak; }
  RepeatForever* getDRHSpeakAction() { return _dRHSpeakAction; }
  Sprite* getDRHSpeakEye() { return _dRHSpeakEye; }
  RepeatForever* getDRHSpeakEyeAction() { return _dRHSpeakEyeAction; }
  Sprite* getBorderScreen() { return _borderScreen; }
 private:
  Sprite* _bgDungeonRoom;
  Sprite* _dRH;
  Sprite* _dRHSpeak;
  RepeatForever* _dRHSpeakAction;
  Sprite* _dRHSpeakEye;
  RepeatForever* _dRHSpeakEyeAction;
  Sprite* _borderScreen;
};

#endif // __TUTORIAL_BG_H__
