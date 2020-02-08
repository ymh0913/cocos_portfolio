#include "IntroScene.h"

Scene* IntroScene::createScene() {
  return IntroScene::create();
}

bool IntroScene::init() {
  if (!Scene::init()) {
    return false;
  }

  for (byte i = 0; i < 2; i++) {
    _uiLayer[i] = Layer::create();
    _labelLayer[i] = Layer::create();
  }

  _intro = new (std::nothrow) Intro(this, _uiLayer, _labelLayer);

  return true;
}

IntroScene::~IntroScene() {
  CC_SAFE_DELETE(_intro);
}
