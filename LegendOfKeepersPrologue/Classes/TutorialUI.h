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
  Sprite* getTrapRemove() { return _trapRemove; }
  Sprite* getConfirm(byte i);
  Sprite* getOrc(byte i);
  Sprite* getSkeletonMagus(byte i);
  Sprite* getGhost(byte i);
  Sprite* getMonsterRemove(byte i);
  Sprite* getClickToPlace(byte i);
  Sprite* getTransparencyPlace(byte i);
  Sprite* getPrevious(byte i);
  Sprite* getThugTurn();
  Sprite* getScoutTurn();
  Sprite* getBarbarianTurn();
  Sprite* getOrcTurn();
  Sprite* getSkeletonMagusTurn();
  Sprite* getGhostTurn();
 private:
  Sprite* _btnOptions[3];
  Sprite* _btnContinue[3];
  Sprite* _roomIconTraps;
  Sprite* _roomIconSpell;
  Sprite* _roomIconMonster3;
  Sprite* _roomIconBoss;
  Sprite* _boneCatapult[3];
  Sprite* _trapRemove;
  Sprite* _confirm[3];
  Sprite* _orc[3];
  Sprite* _skeletonMagus[3];
  Sprite* _ghost[3];
  Sprite* _clickToPlace[3];
  Sprite* _monsterRemove[3];
  Sprite* _transparencyPlace[3];
  Sprite* _previous[3];
  Sprite* _thugTurn;
  Sprite* _scoutTurn;
  Sprite* _barbarianTurn;
  Sprite* _orcTurn;
  Sprite* _skeletonMagusTurn;
  Sprite* _ghostTurn;
};

#endif // __TUTORIAL_UI_H__
