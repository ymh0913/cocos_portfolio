#ifndef __INTRO_H__
#define __INTRO_H__

#include "framework.h"
#include "IntroBg.h"
#include "IntroUI.h"
#include "IntroLabel.h"

class Intro : Scene
{
 public:
  Intro(){}
  ~Intro();
  Intro(Scene* pScene);
 private:
  static Intro* _instance;
  IntroBg* _introBg;
  IntroUI* _introUI;
  IntroLabel* _introLabel;
  EventListenerTouchOneByOne* _touchListener;
  bool onTouchBegan(Touch* touch, Event* event);
  EventListenerMouse* _mouseListener;
  void onMouseMove(Event* event);
};

#endif // __INTRO_H__
