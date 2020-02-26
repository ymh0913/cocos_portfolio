#ifndef __TUTORIAL_HERO_H__
#define __TUTORIAL_HERO_H__

#include "framework.h"

class TutorialHero
{
 public:
  TutorialHero();
  Sprite* getScout() { return _scout; }
  RepeatForever* getScoutIdleAction() { return _scoutIdleAction; }
  Sprite* getThug() { return _thug; }
  RepeatForever* getThugIdleAction() { return _thugIdleAction; }
  Sprite* getBarbarian() { return _barbarian; }
  RepeatForever* getBarbarianIdleAction() { return _barbarianIdleAction; }
  Sprite* getScoutLifeBar() { return _scoutLifeBar; }
 private:
  Sprite* _scout;
  RepeatForever* _scoutIdleAction;
  Sprite* _thug;
  RepeatForever* _thugIdleAction;
  Sprite* _barbarian;
  RepeatForever* _barbarianIdleAction;
  Sprite* _scoutLifeBar;
  
};

#endif // __TUTORIAL_HERO_H__
