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
  _slaveholderIdleAction->retain();

  auto slaveholderAttack1Animation = Animation::create();
  slaveholderAttack1Animation->setDelayPerUnit(0.15f);
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_00.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_01.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_02.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_03.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_04.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_05.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_06.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_07.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_08.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_09.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_10.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_11.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_12.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_13.png");
  slaveholderAttack1Animation->addSpriteFrameWithFile("TutorialScene/Master/Slave Holder/centaure_attack1_14.png");
  auto slaveholderAttack1Animate = Animate::create(slaveholderAttack1Animation);
  _slaveholderAttack1Action = Repeat::create(slaveholderAttack1Animate, 1);
  _slaveholderAttack1Action->retain(); // retain()함수가 있어야 호출코드를 영역을 벗어나더라도 액션이 유지된다.
}
