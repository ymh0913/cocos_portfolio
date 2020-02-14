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

  _scum = Sprite::create("TutorialScene/Hero/Scum/scum_idle_00 #103540.png");
  _scum->setPosition(Vec2(300, 300));
  _scum->setScale(1.5f);
  auto scumIdleAnimation = Animation::create();
  scumIdleAnimation->setDelayPerUnit(0.15f);
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_00 #103540.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_01 #103620.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_02 #103700.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_03 #103777.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_04 #103856.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_05 #105495.png");
  scumIdleAnimation->addSpriteFrameWithFile(
    "TutorialScene/Hero/Scum/scum_idle_06 #105568.png");
  auto scumIdleAnimate = Animate::create(scumIdleAnimation);
  _scumIdleAction = RepeatForever::create(scumIdleAnimate);

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
