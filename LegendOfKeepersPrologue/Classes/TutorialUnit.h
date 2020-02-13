#ifndef __TUTORIAL_UNIT_H__
#define __TUTORIAL_UNIT_H__

#include "framework.h"

class TutorialUnit
{
 public:
  TutorialUnit();
  Sprite* getKaron() { return _karon; }
  RepeatForever* getKaronIdleAction() { return _karonIdleAction; }
  Sprite* getMardin() { return _mardin; }
  RepeatForever* getMardinIdleAction() { return _mardinIdleAction; }
  Sprite* getThokhall() { return _thokhall; }
  RepeatForever* getThokhallIdleAction() { return _thokhallIdleAction; }
 private:
  Sprite* _karon;
  RepeatForever* _karonIdleAction;
  Sprite* _mardin;
  RepeatForever* _mardinIdleAction;
  Sprite* _thokhall;
  RepeatForever* _thokhallIdleAction;
};

#endif // __TUTORIAL_UNIT_H__
