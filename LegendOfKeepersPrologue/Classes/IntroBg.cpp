#include "IntroBg.h"

IntroBg::IntroBg() {
  _keyArtBackground = Sprite::create(
    "IntroScene/Bg/keyArtBackground.png");
  _keyArtBackground->setAnchorPoint(Vec2(0, 0));
  _keyArtBackground->setScale(2.0f / 3.0f);  

  _legendOfKeepersLogo = Sprite::create(
    "IntroScene/Bg/Legend_Of_Keepers_Logo.png");
  _legendOfKeepersLogo->setScale(1.0f / 3.0f);
  _legendOfKeepersLogo->setPosition(Vec2(VISIBLESIZE.width / 2,
                                         VISIBLESIZE.height / 2 + 150));

  _saveBorderBackground = Sprite::create(
    "IntroScene/Bg/save_border_background.png");
  _saveBorderBackground->setScale(1.375f);
  _saveBorderBackground->setPosition(Vec2(640, 360));

  _tutorialBorderBackground = Sprite::create(
    "IntroScene/Bg/save_border_newsave_pressed.png");
  _tutorialBorderBackground->setScale(1.375f);
  _tutorialBorderBackground->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2));
}