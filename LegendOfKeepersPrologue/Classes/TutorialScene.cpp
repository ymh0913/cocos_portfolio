#include "TutorialScene.h"

Scene * TutorialScene::createScene() {
  return TutorialScene::create();
}

bool TutorialScene::init() {
  if (!Scene::init()) {
    return false;
  }

  _tutorial = new (nothrow) Tutorial(this);

  return true;
}

TutorialScene::~TutorialScene() {
  CC_SAFE_DELETE(_tutorial);
}
