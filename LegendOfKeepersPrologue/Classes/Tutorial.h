#ifndef __TUTORIAL_H__
#define __TUTORIAL_H__

#include "framework.h"
#include "TutorialBg.h"
#include "TutorialUI.h"
#include "TutorialLabel.h"
#include "TutorialHero.h"
#include "TutorialTrap.h"
#include "TutorialMonster.h"
#include "TutorialMaster.h"

class Tutorial : Scene
{
 public:
  Tutorial(Scene* pScene);
  ~Tutorial();
 private:
  EventListenerTouchOneByOne* _touchListener;
  bool onTouchBegan(Touch* touch, Event* event);
  void onTouchEnded(Touch* touch, Event* event);
  EventListenerMouse* _mouseListener;
  void onMouseMove(Event* event);
  TutorialBg* _tutorialBg;
  Layer* _bgLayer[2];
  TutorialUI* _tutorialUI;
  Layer* _uiLayer[2];
  TutorialLabel* _tutorialLabel;
  Layer* _labelLayer[2];
  TutorialHero* _tutorialHero;
  Layer* _heroLayer[1];
  TutorialTrap* _tutorialTrap;
  Layer* _trapLayer[1];  
  byte _isContinue;
  bool _isTrap;
};

#endif // __TUTORIAL_H__
