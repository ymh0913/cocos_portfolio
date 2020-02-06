#include "IntroUI.h"

IntroUI::IntroUI() {
  for (byte i = 0; i < 5; i++) {
    _btnState[i] = Sprite::create("IntroScene/UI/btn_state.png");
    _btnState[i]->setScale(1.75f);
    _btnState[i]->setPosition(Vec2(960, 540 - i * 90));
  }
}
