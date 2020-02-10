#ifndef __TEST_UI_H__
#define __TEST_UI_H__

#include "framework.h"

class TestUI
{
  public:
  TestUI();
  Sprite* getBigHelloWorld();
  Sprite* getSmallHelloWorld();
  Sprite* getHelloWorld(byte i);
  private:
  Sprite* _bigHelloWorld;
  Sprite* _smallHelloWorld;
  Sprite* _helloWorld[10];
};

#endif __TEST_UI_H__
