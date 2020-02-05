#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "framework.h"

class IntroScene : public Scene
{
  public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(IntroScene);
};

#endif // __INTRO_SCENE_H__
