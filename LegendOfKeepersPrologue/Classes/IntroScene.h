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
  Layer* _uiLayer[2];
  Layer* _labelLayer[2];
};

#endif // __INTRO_SCENE_H__
