#ifndef __TUTORIAL_BG_H__
#define __TUTORIAL_BG_H__

#include "framework.h"

class TutorialBg
{
 public:
  TutorialBg();
  Sprite* getBgDungeonRoom() { return _bgDungeonRoom; }
 private:
  Sprite* _bgDungeonRoom;
};

#endif // __TUTORIAL_BG_H__
