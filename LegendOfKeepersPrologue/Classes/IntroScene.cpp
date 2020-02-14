#include "IntroScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  _intro = new (nothrow) Intro(this);

  return true;
}

IntroScene::~IntroScene() {
  CC_SAFE_DELETE(_intro);
}
