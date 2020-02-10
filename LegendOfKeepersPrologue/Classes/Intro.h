#ifndef __INTRO_H__
#define __INTRO_H__

#include "framework.h"
#include "IntroBg.h"
#include "IntroUI.h"
#include "IntroLabel.h"

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
  Scene* _scene;
  Layer* _uiLayer[2];
  Layer* _labelLayer[2];
  Layer* _bgLayer;
  byte _isSelect;
  bool _isOverTop;
  bool _isOverMiddle;
  bool _isOverBottom;
  void initIntroUI();
  bool _initIntroUI;
  void initPlayUI();
  bool _initPlayUI;
};

#endif // __INTRO_H__
