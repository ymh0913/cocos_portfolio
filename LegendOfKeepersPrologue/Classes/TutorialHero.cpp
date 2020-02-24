#include "TutorialHero.h"

TutorialHero::TutorialHero() {
  _scout = Sprite::create("TutorialScene/Hero/Scout/scout_idle_00.png");
  _scout->setPosition(Vec2(150, 300));
  _scout->setScale(1.5f);
  auto scoutIdleAnimation = Animation::create();
  scoutIdleAnimation->setDelayPerUnit(0.15f);
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_00.png");
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_01.png");
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_02.png");
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_03.png");
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_04.png");
  scoutIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scout/scout_idle_05.png");
  auto scoutIdleAnimate = Animate::create(scoutIdleAnimation);
  _scoutIdleAction = RepeatForever::create(scoutIdleAnimate);

  _thug = Sprite::create("TutorialScene/Hero/Thug/scum_idle_00 #103540.png");
  _thug->setPosition(Vec2(300, 300));
  _thug->setScale(1.5f);
  auto thugIdleAnimation = Animation::create();
  thugIdleAnimation->setDelayPerUnit(0.15f);
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_00 #103540.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_01 #103620.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_02 #103700.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_03 #103777.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_04 #103856.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_05 #105495.png");
  thugIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Thug/scum_idle_06 #105568.png");
  auto thugIdleAnimate = Animate::create(thugIdleAnimation);
  _thugIdleAction = RepeatForever::create(thugIdleAnimate);

  _barbarian = Sprite::create("TutorialScene/Hero/Barbarian/barbarian_1_idle_00.png");
  _barbarian->setPosition(Vec2(450, 300));
  _barbarian->setScale(1.5f);
  auto barbarianIdleAnimation = Animation::create();
  barbarianIdleAnimation->setDelayPerUnit(0.15f);
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_00.png");
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_01.png");
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_02.png");
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_03.png");
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_04.png");
  barbarianIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Barbarian/barbarian_1_idle_05.png");
  auto barbarianIdleAnimate = Animate::create(barbarianIdleAnimation);
  _barbarianIdleAction = RepeatForever::create(barbarianIdleAnimate);
}
