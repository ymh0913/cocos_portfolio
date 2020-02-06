#ifndef __INTRO_H__
#define __INTRO_H__

#include "framework.h"
#include "IntroBg.h"
#include "IntroUI.h"

class Intro
{
 public:
  Intro(Scene* pScene);
 private:
  IntroBg* _introBg;
  IntroUI* _introUI;
};

#endif // __INTRO_H__
