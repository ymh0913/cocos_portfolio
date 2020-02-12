#ifndef __INTRO_H__
#define __INTRO_H__

#include "framework.h"
#include "IntroBg.h"
#include "IntroUI.h"
#include "IntroLabel.h"
#include "TutorialScene.h"

class Intro : Scene
{
 public:
  Intro(Scene* pScene);
  ~Intro();
 private:
  IntroBg* _introBg;
  IntroUI* _introUI;
  IntroLabel* _introLabel;
  EventListenerTouchOneByOne* _touchListener;
  bool onTouchBegan(Touch* touch, Event* event);
  void onTouchEnded(Touch* touch, Event* event);
  EventListenerMouse* _mouseListener;
  void onMouseMove(Event* event);
  Layer* _bgLayer[3];
  Layer* _uiLayer[3];
  Layer* _labelLayer[3];  
  byte _isSelect;
  bool _isTop;
  bool _isMiddle;
  bool _isBottom;
};

#endif // __INTRO_H__
