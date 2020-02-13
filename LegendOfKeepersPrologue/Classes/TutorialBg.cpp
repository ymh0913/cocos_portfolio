#include "TutorialBg.h"

TutorialBg::TutorialBg() {
  _bgDungeonRoom = Sprite::create(
    "TutorialScene/Bg/bg_dungeon_room0_1.png");
  _bgDungeonRoom->setAnchorPoint(Vec2(0, 0));
  _bgDungeonRoom->setScale(1.5f);
  _bgDungeonRoom->setPosition(Vec2(-160, 150));

  _dRH = Sprite::create(
    "TutorialScene/Bg/DRH_state.png");
  _dRH->setAnchorPoint(Vec2(0, 0));

  _dRHSpeak = Sprite::create(
    "TutorialScene/Bg/DRH_speak_1.png");
  _dRHSpeak->setAnchorPoint(Vec2(0, 0));
  _dRHSpeak->setPosition(Vec2(270, 220));

  auto speakAnimation = Animation::create();
  speakAnimation->setDelayPerUnit(0.15f);
  speakAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_1.png");  
  speakAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_2.png");
  speakAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_3.png");
  speakAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_4.png");
  auto speakAnimate = Animate::create(speakAnimation);
  _dRHSpeakAction = RepeatForever::create(speakAnimate);

  _dRHSpeakEye = Sprite::create(
    "TutorialScene/Bg/DRH_speak_eye_1.png");
  _dRHSpeakEye->setAnchorPoint(Vec2(0, 0));
  _dRHSpeakEye->setPosition(Vec2(275, 243));

  auto speakEyeAnimation = Animation::create();
  speakEyeAnimation->setDelayPerUnit(0.15f);
  speakEyeAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_eye_1.png");
  speakEyeAnimation->addSpriteFrameWithFile("TutorialScene/Bg/DRH_speak_eye_2.png");
  auto speakEyeAnimate = Animate::create(speakEyeAnimation);
  _dRHSpeakEyeAction = RepeatForever::create(speakEyeAnimate);

  _borderScreen = Sprite::create(
    "TutorialScene/Bg/border_screen.png");
  _borderScreen->setAnchorPoint(Vec2(0, 0));
  _borderScreen->setScale(1.5f);
  _borderScreen->setPosition(Vec2(540, 360));
}
