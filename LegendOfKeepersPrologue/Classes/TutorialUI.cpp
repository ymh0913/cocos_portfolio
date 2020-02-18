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

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _btnContinue[i] = Sprite::create("TutorialScene/UI/btn_state.png");
    } else if (i == 1) {
      _btnContinue[i] = Sprite::create("TutorialScene/UI/btn_over.png");
    } else {
      _btnContinue[i] = Sprite::create("TutorialScene/UI/btn_press.png");
    }
    _btnContinue[i]->setPosition(Vec2(900, 300));
  }

  _roomIconTraps = Sprite::create("TutorialScene/UI/room_icon_traps.png");
  _roomIconTraps->setPosition(Vec2(VISIBLESIZE.width / 2 - 100, VISIBLESIZE.height - 100));
  _roomIconSpell = Sprite::create("TutorialScene/UI/room_icon_spell.png");
  _roomIconSpell->setPosition(Vec2(VISIBLESIZE.width / 2 - 50, VISIBLESIZE.height - 100));
  _roomIconMonster3 = Sprite::create("TutorialScene/UI/room_icon_monster3.png");
  _roomIconMonster3->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height - 100));
  _roomIconBoss = Sprite::create("TutorialScene/UI/room_icon_boss.png");
  _roomIconBoss->setPosition(Vec2(VISIBLESIZE.width / 2 + 50, VISIBLESIZE.height - 100));

  _remove = Sprite::create("TutorialScene/UI/brazierfire_1_idle_00.png");
  _remove->setPosition(Vec2(VISIBLESIZE.width / 2 + 120, VISIBLESIZE.height / 2));

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _boneCatapult[i] = Sprite::create("TutorialScene/UI/btn_state.png");
      _confirm[i] = Sprite::create("TutorialScene/UI/btn_state.png");
    } else if (i == 1) {
      _boneCatapult[i] = Sprite::create("TutorialScene/UI/btn_over.png");
      _confirm[i] = Sprite::create("TutorialScene/UI/btn_over.png");
    } else {
      _boneCatapult[i] = Sprite::create("TutorialScene/UI/btn_press.png");
      _confirm[i] = Sprite::create("TutorialScene/UI/btn_press.png");
    }
    _boneCatapult[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 100));
    _confirm[i]->setPosition(Vec2(VISIBLESIZE.width - 100, 100));
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

Sprite * TutorialUI::getBtnContinue(byte i) {
  if (i == 0) {
    return _btnContinue[i];
  } else if (i == 1) {
    return _btnContinue[i];
  } else {
    return _btnContinue[i];
  }
}

Sprite * TutorialUI::getBoneCatapult(byte i) {
  if (i == 0) {
    return _boneCatapult[i];
  } else if (i == 1) {
    return _boneCatapult[i];
  } else {
    return _boneCatapult[i];
  }
}

Sprite * TutorialUI::getConfirm(byte i) {
  if (i == 0) {
    return _confirm[i];
  } else if (i == 1) {
    return _confirm[i];
  } else {
    return _confirm[i];
  }
}
