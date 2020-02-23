#include "TutorialMonster.h"

TutorialMonster::TutorialMonster() {
  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _orcPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_orc #101977.png");
    } else {
      _orcPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_orc.png");
    }
    _orcPortrait[i]->setScale(1.5f);
    _orcPortrait[i]->setPosition(Vec2(VISIBLESIZE.width / 2 - 200, VISIBLESIZE.height / 2 + 150));
  }

  _orc = Sprite::create("TutorialScene/Monster/Orc/orc_warrior_1_idle_00 #103888.png");
  _orc->setScale(1.5f);
  _orc->setPosition(Vec2::ZERO);
  auto orcIdleAnimation = Animation::create();
  orcIdleAnimation->setDelayPerUnit(0.15f);
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_00 #103888.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_01 #103965.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_02 #104043.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_03 #104119.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_04 #104195.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_05 #104269.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_06 #104345.png");
  orcIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Orc/orc_warrior_1_idle_07 #104419.png");
  auto orcIdleAnimate = Animate::create(orcIdleAnimation);
  _orcIdleAction = RepeatForever::create(orcIdleAnimate);

  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _skeletonMagusPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_skeleton_mage #102168.png");
    } else {
      _skeletonMagusPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_skeleton_mage #101657.png");
    }
    _skeletonMagusPortrait[i]->setScale(1.5f);
    _skeletonMagusPortrait[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 150));
  }

  _skeletonMagus = Sprite::create("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_00 #104573.png");  
  _skeletonMagus->setScale(1.5f);
  _skeletonMagus->setPosition(Vec2::ZERO);
  auto skeletonMagusIdleAnimation = Animation::create();
  skeletonMagusIdleAnimation->setDelayPerUnit(0.15f);
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_00 #104573.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_01 #104649.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_02 #104725.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_03 #104801.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_04 #104874.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_05 #104948.png");
  skeletonMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Skeleton Magus/skeletonmage_1_idle_06 #105020.png");
  auto skeletonMagusIdleAnimate = Animate::create(skeletonMagusIdleAnimation);
  _skeletonMagusIdleAction = RepeatForever::create(skeletonMagusIdleAnimate);

  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _ghostPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_ghost.png");
    } else {
      _ghostPortrait[i] = Sprite::create("TutorialScene/Portrait/portrait_mobs_ghost #101859.png");
    }
    _ghostPortrait[i]->setScale(1.5f);
    _ghostPortrait[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 200, VISIBLESIZE.height / 2 + 150));
  }

  _ghost = Sprite::create("TutorialScene/Monster/Ghost/ghost_idle_00.png");
  _ghost->setScale(1.5f);
  _ghost->setPosition(Vec2::ZERO);
  auto ghostMagusIdleAnimation = Animation::create();
  ghostMagusIdleAnimation->setDelayPerUnit(0.15f);
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_00.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_01.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_02.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_03.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_04.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_05.png");
  ghostMagusIdleAnimation->addSpriteFrameWithFile("TutorialScene/Monster/Ghost/ghost_idle_06.png");
  auto ghostIdleAnimate = Animate::create(ghostMagusIdleAnimation);
  _ghostIdleAction = RepeatForever::create(ghostIdleAnimate);
}

Sprite * TutorialMonster::getOrcPortrait(byte i) {
  if (i == 0) {
    return _orcPortrait[i];
  } else {
    return _orcPortrait[i];
  }
}

Sprite * TutorialMonster::getSkeletonMagusPortrait(byte i) {
  if (i == 0) {
    return _skeletonMagusPortrait[i];
  } else {
    return _skeletonMagusPortrait[i];
  }
}

Sprite * TutorialMonster::getGhostPortrait(byte i) {
  if (i == 0) {
    return _ghostPortrait[i];
  } else {
    return _ghostPortrait[i];
  }
}
