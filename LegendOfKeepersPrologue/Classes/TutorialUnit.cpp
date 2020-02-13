#include "TutorialUnit.h"

TutorialUnit::TutorialUnit() {
  _karon = Sprite::create("TutorialScene/Unit/Scout/scout_idle_00.png");
  _karon->setPosition(Vec2(150, 300));
  _karon->setScale(1.5f);
  auto karonIdleAnimation = Animation::create();
  karonIdleAnimation->setDelayPerUnit(0.15f);
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_00.png");
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_01.png");
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_02.png");
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_03.png");
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_04.png");
  karonIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scout/scout_idle_05.png");
  auto karonIdleAnimate = Animate::create(karonIdleAnimation);
  _karonIdleAction = RepeatForever::create(karonIdleAnimate);

  _mardin = Sprite::create("TutorialScene/Unit/Scum/scum_idle_00 #103540.png");
  _mardin->setPosition(Vec2(300, 300));
  _mardin->setScale(1.5f);
  auto mardinIdleAnimation = Animation::create();
  mardinIdleAnimation->setDelayPerUnit(0.15f);
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_00 #103540.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_01 #103620.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_02 #103700.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_03 #103777.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_04 #103856.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_05 #105495.png");
  mardinIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Scum/scum_idle_06 #105568.png");
  auto mardinIdleAnimate = Animate::create(mardinIdleAnimation);
  _mardinIdleAction = RepeatForever::create(mardinIdleAnimate);

  _thokhall = Sprite::create("TutorialScene/Unit/Barbarian/barbarian_1_idle_00.png");
  _thokhall->setPosition(Vec2(450, 300));
  _thokhall->setScale(1.5f);
  auto thokhallIdleAnimation = Animation::create();
  thokhallIdleAnimation->setDelayPerUnit(0.15f);
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_00.png");
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_01.png");
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_02.png");
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_03.png");
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_04.png");
  thokhallIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Unit/Barbarian/barbarian_1_idle_05.png");
  auto thokhallIdleAnimate = Animate::create(thokhallIdleAnimation);
  _thokhallIdleAction = RepeatForever::create(thokhallIdleAnimate);
}
