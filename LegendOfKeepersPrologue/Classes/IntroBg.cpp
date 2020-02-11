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
}