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
  Label* getPlaceYourMonsters() { return _placeYourMonsters; }
  Label* getRaguk() { return _raguk; }
  Label* getKhidus() { return _khidus; }
  Label* getOra() { return _ora; }
  Label* getGrogmar() { return _grogmar; }
  Label* getAurora() { return _aurora; }
  Label* getPrevious() { return _previous; }
 private:
  Label* _congratulations;
  Label* _continue;
  Label* _heroes;
  Label* _placeATrap;
  Label* _boneCatapult;
  Label* _confirm;
  Label* _we;
  Label* _some;
  Label* _placeYourMonsters;
  Label* _raguk;
  Label* _khidus;
  Label* _ora;
  Label* _grogmar;
  Label* _aurora;
  Label* _previous;
};

#endif // __TUTORIAL_LABEL_H__
