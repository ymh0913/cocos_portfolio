#include "TutorialMaster.h"

TutorialMaster::TutorialMaster() {
  _slaveholder = Sprite::create("TutorialScene/Master/Slave Holder/centaure_idle_00.png");
  _slaveholder->setPosition(Vec2(VISIBLESIZE.width / 2 + 300, VISIBLESIZE.height / 2 - 100));
  _slaveholder->setScale(1.5f);
  auto slaveholderIdleAnimation = Animation::create();
  slaveholderIdleAnimation->setDelayPerUnit(0.15f);
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_00.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_01.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_02.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_03.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_04.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_05.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_06.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_08.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_09.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_10.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_11.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_12.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_13.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_14.png");
  slaveholderIdleAnimation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_idle_15.png");
  auto slaveholderIdleAnimate = Animate::create(slaveholderIdleAnimation);
  _slaveholderIdleAction = RepeatForever::create(slaveholderIdleAnimate);
}

Sprite * TutorialMaster::getSlaveholder() {
  return _slaveholder;
}

RepeatForever * TutorialMaster::getSlaveholderIdleAction() {
  return _slaveholderIdleAction;
}
