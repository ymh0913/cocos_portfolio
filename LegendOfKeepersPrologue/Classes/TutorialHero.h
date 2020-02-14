#ifndef __TUTORIAL_HERO_H__
#define __TUTORIAL_HERO_H__

#include "framework.h"

class TutorialHero
{
 public:
  TutorialHero();
  Sprite* getScout() { return _scout; }
  RepeatForever* getScoutIdleAction() { return _scoutIdleAction; }
  Sprite* getScum() { return _scum; }
  RepeatForever* getScumIdleAction() { return _scumIdleAction; }
  Sprite* getBarbarian() { return _barbarian; }
  RepeatForever* getBarbarianIdleAction() { return _barbarianIdleAction; }
 private:
  Sprite* _scout;
  RepeatForever* _scoutIdleAction;
  Sprite* _scum;
  RepeatForever* _scumIdleAction;
  Sprite* _barbarian;
  RepeatForever* _barbarianIdleAction;
};

#endif // __TUTORIAL_HERO_H__
