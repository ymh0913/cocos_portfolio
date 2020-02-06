#include "IntroScene.h"

Scene * IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  _intro = new (std::nothrow) Intro(this);

  return true;
}
