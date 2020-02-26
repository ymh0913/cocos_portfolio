#include "TutorialBg.h"

TutorialBg::TutorialBg() {
  for (byte i = 0; i < 5; i++) {
    if (i == 0) {
      _bgDungeonRoom[i] = Sprite::create(
        "TutorialScene/Bg/bg_dungeon_room0_1.png");
    } else if (i == 1) {
      _bgDungeonRoom[i] = Sprite::create(
        "TutorialScene/Bg/bg_dungeon_room1_1.png");
    } else if (i == 2) {
      _bgDungeonRoom[i] = Sprite::create(
        "TutorialScene/Bg/bg_dungeon_room2_1.png");
    } else if (i == 3) {
      _bgDungeonRoom[i] = Sprite::create(
        "TutorialScene/Bg/bg_dungeon_room3_1.png");
    } else {
      _bgDungeonRoom[i] = Sprite::create(
        "TutorialScene/Bg/bg_dungeon_room4_1.png");
    }
    _bgDungeonRoom[i]->setAnchorPoint(Vec2(0, 0));
    _bgDungeonRoom[i]->setScale(1.5f);
    _bgDungeonRoom[i]->setPosition(Vec2(-160, 150));
  }

  for (byte i = 0; i < 4; i++) {
    _bgDungeonGround[i] = Sprite::create("TutorialScene/Bg/bg_dungeon_ground_1.png");
    _bgDungeonGround[i]->setAnchorPoint(Vec2(0, 0));
    _bgDungeonGround[i]->setScaleX(2);
  }

  _dRH = Sprite::create(
    "TutorialScene/DRH/DRH_state.png");
  _dRH->setAnchorPoint(Vec2(0, 0));
  _dRH->setScale(1.35f);

  _dRHSpeak = Sprite::create(
    "TutorialScene/DRH/DRH_speak_1.png");
  _dRHSpeak->setAnchorPoint(Vec2(0, 0));
  _dRHSpeak->setPosition(Vec2(270, 220));

  auto speakAnimation = Animation::create();
  speakAnimation->setDelayPerUnit(0.15f);
  speakAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_1.png");
  speakAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_2.png");
  speakAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_3.png");
  speakAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_4.png");
  auto speakAnimate = Animate::create(speakAnimation);
  _dRHSpeakAction = RepeatForever::create(speakAnimate);

  _dRHSpeakEye = Sprite::create(
    "TutorialScene/DRH/DRH_speak_eye_1.png");
  _dRHSpeakEye->setAnchorPoint(Vec2(0, 0));
  _dRHSpeakEye->setPosition(Vec2(275, 243));

  auto speakEyeAnimation = Animation::create();
  speakEyeAnimation->setDelayPerUnit(0.15f);
  speakEyeAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_eye_1.png");
  speakEyeAnimation->addSpriteFrameWithFile("TutorialScene/DRH/DRH_speak_eye_2.png");
  auto speakEyeAnimate = Animate::create(speakEyeAnimation);
  _dRHSpeakEyeAction = RepeatForever::create(speakEyeAnimate);

  _borderScreen = Sprite::create(
    "TutorialScene/Bg/border_screen.png");
  _borderScreen->setAnchorPoint(Vec2(0, 0));
  _borderScreen->setScale(1.5f);
  _borderScreen->setPosition(Vec2(540, 360));

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _placementMobtrapsFront[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_state.png");
      _placementMobtrapsMiddle[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_state.png");
      _placementMobtrapsBack[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_state.png");
    } else if (i == 1) {
      _placementMobtrapsFront[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_over.png");
      _placementMobtrapsMiddle[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_over.png");
      _placementMobtrapsBack[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_over.png");
    } else {
      _placementMobtrapsFront[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_press.png");
      _placementMobtrapsMiddle[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_press.png");
      _placementMobtrapsBack[i] = Sprite::create("TutorialScene/Bg/placement_mobtraps_press.png");
    }
    _placementMobtrapsFront[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 100, 250));
    _placementMobtrapsMiddle[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 250, 250));
    _placementMobtrapsBack[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 400, 250));
  }

  _empty = Sprite::create("TutorialScene/Bg/empty.png");
  _empty->setAnchorPoint(Vec2(0, 0));
  _empty->setColor(Color3B::BLACK);
  _empty->setScale(10);
}

Sprite * TutorialBg::getBgDungeonRoom(byte i) {
  if (i == 0) {
    return _bgDungeonRoom[i];
  } else if (i == 1) {
    return _bgDungeonRoom[i];
  } else if (i == 2) {
    return _bgDungeonRoom[i];
  } else if (i == 3) {
    return _bgDungeonRoom[i];
  } else {
    return _bgDungeonRoom[i];
  }
}

Sprite * TutorialBg::getBgDungeonGround(byte i) {
  if (i == 0) {
    return _bgDungeonGround[i];
  } else if (i == 1) {
    return _bgDungeonGround[i];
  } else if (i == 2) {
    return _bgDungeonGround[i];
  } else if (i = 3) {
    return _bgDungeonGround[i];
  }
}

Sprite * TutorialBg::getPlacementMobtrapsFront(byte i) {
  if (i == 0) {
    return _placementMobtrapsFront[i];
  } else if (i == 1) {
    return _placementMobtrapsFront[i];
  } else {
    return _placementMobtrapsFront[i];
  }
}

Sprite * TutorialBg::getPlacementMobtrapsMiddle(byte i) {
  if (i == 0) {
    return _placementMobtrapsMiddle[i];
  } else if (i == 1) {
    return _placementMobtrapsMiddle[i];
  } else {
    return _placementMobtrapsMiddle[i];
  }
}

Sprite * TutorialBg::getPlacementMobtrapsBack(byte i) {
  if (i == 0) {
    return _placementMobtrapsBack[i];
  } else if (i == 1) {
    return _placementMobtrapsBack[i];
  } else {
    return _placementMobtrapsBack[i];
  }
}
