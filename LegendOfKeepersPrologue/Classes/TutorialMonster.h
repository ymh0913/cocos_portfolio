#ifndef __TUTORIAL_MONSTER_H__
#define __TUTORIAL_MONSTER_H__

#include "framework.h"

class TutorialMonster
{
 public:
  TutorialMonster();
  Sprite* getOrcPortrait(byte i);
  Sprite* getOrc() { return _orc; }
  RepeatForever* getOrcIdleAction() { return _orcIdleAction; }
  Sprite* getSkeletonMagusPortrait(byte i);
  Sprite* getSkeletonMagus() { return _skeletonMagus; }
  RepeatForever* getSkeletonMagusIdleAction() { return _skeletonMagusIdleAction; }
  Sprite* getGhostPortrait(byte i);
  Sprite* getGhost() { return _ghost; }
  RepeatForever* getGhostIdleAction() { return _ghostIdleAction; }
 private:
  Sprite* _orcPortrait[2];
  Sprite* _orc;
  RepeatForever* _orcIdleAction;
  Sprite* _skeletonMagusPortrait[2];
  Sprite* _skeletonMagus;
  RepeatForever* _skeletonMagusIdleAction;
  Sprite* _ghostPortrait[2];
  Sprite* _ghost;
  RepeatForever* _ghostIdleAction;
};

#endif // __TUTORIAL_MONSTER_H__
