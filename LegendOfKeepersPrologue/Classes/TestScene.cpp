#include "TestScene.h"

Scene * TestScene::createScene() {
  return TestScene::create();
}

bool TestScene::init() {
  if (!Scene::init()) {
    return false;
  }
  
  _test = new (std::nothrow) Test(this);

  return true;
}

TestScene::~TestScene() {
  CC_SAFE_DELETE(_test);
}
