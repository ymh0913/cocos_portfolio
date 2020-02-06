#include "IntroBg.h"

IntroBg::IntroBg() {
  _keyArtBackground = Sprite::create(
    "IntroScene/Bg/keyArtBackground.png");
  _keyArtBackground->setAnchorPoint(Vec2(0, 0));
  _keyArtBackground->setPosition(Vec2(0, 0));

  _Legend_Of_Keepers_Logo = Sprite::create(
    "IntroScene/Bg/Legend_Of_Keepers_Logo.png");
  _Legend_Of_Keepers_Logo->setScale(1.25f / 3.0f);  
  _Legend_Of_Keepers_Logo->setPosition(Vec2(960, 810));
}
