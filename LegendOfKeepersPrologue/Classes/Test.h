#ifndef __TEST_H__
#define __TEST_H__

#include "framework.h"
#include "TestUI.h"

class Test : Scene
{
  public:
  Test(Scene* pScene);
  bool onTouchBegan(Touch* touch, Event* event);
  private:
  TestUI* _testUI;
  Layer* _uiLayer[2];
  EventListenerTouchOneByOne* _listener;
};

#endif __TEST_H__