#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "framework.h"
#include "Intro.h"

class IntroScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  CREATE_FUNC(IntroScene);
  virtual ~IntroScene();
 private:
  Intro* _intro;
  void callPerFrame(float delta);
};

#endif // __INTRO_SCENE_H__
