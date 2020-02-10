#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include "framework.h"
#include "Test.h"

class TestScene : Scene
{
  public:
  static Scene* createScene();
  virtual bool init();
  virtual ~TestScene();
  CREATE_FUNC(TestScene);
  private:
  Test* _test;
};

#endif __TEST_SCENE_H__