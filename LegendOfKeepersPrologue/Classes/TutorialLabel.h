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
  Label* getPlaceATrap() { return _placeATrap; }
  Label* getBoneCatapult() { return _boneCatapult; }
  Label* getConfirm() { return _confirm; }
  Label* getWe() { return _we; }
  Label* getSome() { return _some; }
 private:
  Label* _congratulations;
  Label* _continue;
  Label* _heroes;
  Label* _placeATrap;
  Label* _boneCatapult;
  Label* _confirm;
  Label* _we;
  Label* _some;
};

#endif // __TUTORIAL_LABEL_H__
