#include "TutorialUI.h"

TutorialUI::TutorialUI() {
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _btnOptions[i] = Sprite::create("TutorialScene/UI/btn_options_state.png");
    } else if (i == 1) {
      _btnOptions[i] = Sprite::create("TutorialScene/UI/btn_options_over.png");
    } else {
      _btnOptions[i] = Sprite::create("TutorialScene/UI/btn_options_pressed.png");
    }    
    _btnOptions[i]->setPosition(Vec2(VISIBLESIZE.width - 40, VISIBLESIZE.height - 50));
  }
}

Sprite * TutorialUI::getBtnOptions(byte i) {
  if (i == 0) {
    return _btnOptions[i];
  } else if (i == 1) {
    return _btnOptions[i];
  } else {
    return _btnOptions[i];
  }
}
