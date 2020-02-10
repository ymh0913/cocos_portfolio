#include "Test.h"

Test::Test(Scene * pScene) {
  for (byte i = 0; i < 2; i++) {
    _uiLayer[i] = Layer::create();
  }

  _testUI = new (std::nothrow) TestUI;
  _uiLayer[0]->addChild(_testUI->getBigHelloWorld());
  _uiLayer[1]->addChild(_testUI->getSmallHelloWorld());
  for (byte i = 0; i < 10; i++) {
    _uiLayer[0]->addChild(_testUI->getHelloWorld(i));
  }  
  pScene->addChild(_uiLayer[0]);
  pScene->addChild(_uiLayer[1]);

  _listener = EventListenerTouchOneByOne::create();
  _listener->setSwallowTouches(true);
  _listener->onTouchBegan = CC_CALLBACK_2(Test::onTouchBegan, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener,
                                                           pScene);
}

bool Test::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchBig = _testUI->getBigHelloWorld()->getBoundingBox().
    containsPoint(touchPoint);
  bool touchSmall = _testUI->getSmallHelloWorld()->getBoundingBox().
    containsPoint(touchPoint);

  if (touchBig) {
    _uiLayer[0]->setVisible(true);
    _uiLayer[1]->setVisible(true);
  } else if (touchSmall) {
    _uiLayer[1]->setVisible(true);
    _uiLayer[0]->setVisible(true);
  }

  return true;
}
