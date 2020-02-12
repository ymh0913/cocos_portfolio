#ifndef __TUTORIAL_SCENE_H__
#define __TUTORIAL_SCENE_H__

#include "framework.h"
#include "Tutorial.h"

class TutorialScene : public Scene
{
 public:
  static Scene* createScene();
  virtual bool init();
  virtual ~TutorialScene();
  CREATE_FUNC(TutorialScene);
 private:
  Tutorial* _tutorial;
};

#endif // __TUTORIAL_SCENE_H__
