#ifndef __TUTORIAL_BG_H__
#define __TUTORIAL_BG_H__

#include "framework.h"

class TutorialBg
{
 public:
  TutorialBg();
  Sprite* getBgDungeonRoom(byte i);
  Sprite* getBgDungeonGround(byte i);
  Sprite* getDRH() { return _dRH; }
  Sprite* getDRHSpeak() { return _dRHSpeak; }
  RepeatForever* getDRHSpeakAction() { return _dRHSpeakAction; }
  Sprite* getDRHSpeakEye() { return _dRHSpeakEye; }
  RepeatForever* getDRHSpeakEyeAction() { return _dRHSpeakEyeAction; }
  Sprite* getBorderScreen() { return _borderScreen; }
 private:
  Sprite* _bgDungeonRoom[5];
  Sprite* _bgDungeonGround[3];
  Sprite* _dRH;
  Sprite* _dRHSpeak;
  RepeatForever* _dRHSpeakAction;
  Sprite* _dRHSpeakEye;
  RepeatForever* _dRHSpeakEyeAction;
  Sprite* _borderScreen;
};

#endif // __TUTORIAL_BG_H__
