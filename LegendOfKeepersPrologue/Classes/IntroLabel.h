#ifndef __INTRO_LABEL_H__
#define __INTRO_LABEL_H__

#include "framework.h"

class IntroLabel
{
 public:
  IntroLabel();
  Label* getPlay() { return _play; }
  Label* getSettings() { return _settings; }
  Label* getModding() { return _modding; }
  Label* getCredits() { return _credits; }
  Label* getQuit() { return _quit; }
  Label* getV0602() { return _v0602; }
 private:
  Label* _play;
  Label* _settings;
  Label* _modding;
  Label* _credits;
  Label* _quit;
  Label* _v0602;
};

#endif // __INTRO_LABEL_H__
