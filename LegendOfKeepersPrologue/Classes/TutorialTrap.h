#ifndef __TUTORIAL_TRAP_H__
#define __TUTORIAL_TRAP_H__

#include "framework.h"

class TutorialTrap
{
 public:
  TutorialTrap();
  Sprite* getBoneCatapult() { return _boneCatapult; }
  Sprite* getBoneCatapultClone() { return _boneCatapultClone; }
 private:
  Sprite* _boneCatapult;
  Sprite* _boneCatapultClone;
};

#endif // __TUTORIAL_TRAP_H__
