#ifndef __TUTORIAL_LABEL_H__
#define __TUTORIAL_LABEL_H__

#include "framework.h"

class TutorialLabel
{
 public:
  TutorialLabel();
  Label* getCongratulations() { return _congratulations; }
  Label* getContinue() { return _continue; }
  Label* getHeroes() { return _heroes; }
 private:
  Label* _congratulations;
  Label* _continue;
  Label* _heroes;
};

#endif // __TUTORIAL_LABEL_H__
