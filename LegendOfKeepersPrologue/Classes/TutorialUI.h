#ifndef __TUTORIAL_UI_H__
#define __TUTORIAL_UI_H__

#include "framework.h"

class TutorialUI
{
 public:
  TutorialUI();
  Sprite* getBtnOptions(byte i);
  Sprite* getBtnContinue(byte i);
  Sprite* getRoomIconTraps() { return _roomIconTraps; }
  Sprite* getRoomIconSpell() { return _roomIconSpell; }
  Sprite* getRoomIconMonster3() { return _roomIconMonster3; }
  Sprite* getRoomIconBoss() { return _roomIconBoss; }
  Sprite* getBoneCatapult(byte i);
  Sprite* getTmp() { return _tmp; }
  Sprite* getConfirm(byte i);
 private:
  Sprite* _btnOptions[3];
  Sprite* _btnContinue[3];
  Sprite* _roomIconTraps;
  Sprite* _roomIconSpell;
  Sprite* _roomIconMonster3;
  Sprite* _roomIconBoss;
  Sprite* _boneCatapult[3];
  Sprite* _tmp;
  Sprite* _confirm[3];
};

#endif // __TUTORIAL_UI_H__
