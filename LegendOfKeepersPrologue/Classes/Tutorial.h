#ifndef __TUTORIAL_H__
#define __TUTORIAL_H__

#include "framework.h"
#include "TutorialBg.h"
#include "TutorialUI.h"
#include "TutorialLabel.h"
#include "TutorialUnit.h"
#include "TutorialTrap.h"

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
  Layer* _bgLayer[1];
  TutorialUI* _tutorialUI;
  Layer* _uiLayer[1];
  TutorialLabel* _tutorialLabel;
  Layer* _labelLayer[1];
  TutorialUnit* _tutorialUnit;
  Layer* _unitLayer[1];
  TutorialTrap* _tutorialTrap;
  Layer* _trapLayer[1];
};

#endif // __TUTORIAL_H__
