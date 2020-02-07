#include "IntroScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  _intro = new (std::nothrow) Intro(this);

  this->schedule(schedule_selector(IntroScene::callPerFrame));

  return true;
}

IntroScene::~IntroScene() {
  CC_SAFE_DELETE(_intro);
}

void IntroScene::callPerFrame(float delta) {
}
