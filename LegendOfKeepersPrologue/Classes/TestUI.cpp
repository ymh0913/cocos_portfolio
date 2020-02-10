#include "TestUI.h"

TestUI::TestUI() {
  _bigHelloWorld = Sprite::create("HelloWorld.png");
  _bigHelloWorld->setPosition(Vec2(990, 540));

  _smallHelloWorld = Sprite::create("HelloWorld.png");
  _smallHelloWorld->setScale(0.5f);
  _smallHelloWorld->setPosition(Vec2(1260, 540));

  for (byte i = 0; i < 10; i++) {
    _helloWorld[i] = Sprite::create("HelloWorld.png");
    _helloWorld[i]->setScale(0.5f);
    _helloWorld[i]->setPosition(Vec2(rand() % 1980, rand() % 1080));
  }
}

Sprite * TestUI::getBigHelloWorld() {
  return _bigHelloWorld;
}

Sprite * TestUI::getSmallHelloWorld() {
  return _smallHelloWorld;
}

Sprite * TestUI::getHelloWorld(byte i) {
  if (i == 0) {
    return _helloWorld[i];
  } else if (i == 1) {
    return _helloWorld[i];
  } else if (i == 2) {
    return _helloWorld[i];
  } else if (i == 3) {
    return _helloWorld[i];
  } else if (i == 4) {
    return _helloWorld[i];
  } else if (i == 5) {
    return _helloWorld[i];
  } else if (i == 6) {
    return _helloWorld[i];
  } else if (i == 7) {
    return _helloWorld[i];
  } else if (i == 8) {
    return _helloWorld[i];
  } else if (i == 9) {
    return _helloWorld[i];
  }

}
