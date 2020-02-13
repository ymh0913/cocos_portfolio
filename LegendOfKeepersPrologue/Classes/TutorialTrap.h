#ifndef __TUTORIAL_TRAP_H__
#define __TUTORIAL_TRAP_H__

#include "framework.h"

class TutorialTrap
{
  public:
  TutorialTrap();
  Sprite* getBoneCatapult() { return _boneCatapult; }
  private:
  Sprite* _boneCatapult;
};

#endif // __TUTORIAL_TRAP_H__
