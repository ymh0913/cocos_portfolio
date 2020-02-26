#ifndef __TUTORIAL_MASTER_H__
#define __TUTORIAL_MASTER_H__

#include "framework.h"

class TutorialMaster
{
 public:
  TutorialMaster();
  Sprite* getSlaveholder() { return _slaveholder; }
  RepeatForever* getSlaveholderIdleAction() { return _slaveholderIdleAction; }
  Repeat* getSlaveholderAttack1Action() { return _slaveholderAttack1Action; }
 private:
  Sprite* _slaveholder;
  RepeatForever* _slaveholderIdleAction;
  Repeat* _slaveholderAttack1Action;
};

#endif // __TUTORIAL_MASTER_H__
