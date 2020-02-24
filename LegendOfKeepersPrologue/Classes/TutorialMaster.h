#ifndef __TUTORIAL_MASTER_H__
#define __TUTORIAL_MASTER_H__

#include "framework.h"

class TutorialMaster
{
 public:
  TutorialMaster();
  Sprite* getSlaveholder();
  RepeatForever* getSlaveholderIdleAction();
 private:
  Sprite* _slaveholder;
  RepeatForever* _slaveholderIdleAction;
};

#endif // __TUTORIAL_MASTER_H__
