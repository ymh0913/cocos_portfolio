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

  _trapRemove = Sprite::create("TutorialScene/UI/brazierfire_1_idle_00.png");
  _trapRemove->setPosition(Vec2(VISIBLESIZE.width / 2 + 120, VISIBLESIZE.height / 2));

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

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _orc[i] = Sprite::create("TutorialScene/UI/btn_state.png");
      _skeletonMagus[i] = Sprite::create("TutorialScene/UI/btn_state.png");
      _ghost[i] = Sprite::create("TutorialScene/UI/btn_state.png");
    } else if (i == 1) {
      _orc[i] = Sprite::create("TutorialScene/UI/btn_over.png");
      _skeletonMagus[i] = Sprite::create("TutorialScene/UI/btn_over.png");
      _ghost[i] = Sprite::create("TutorialScene/UI/btn_over.png");
    } else {
      _orc[i] = Sprite::create("TutorialScene/UI/btn_press.png");
      _skeletonMagus[i] = Sprite::create("TutorialScene/UI/btn_press.png");
      _ghost[i] = Sprite::create("TutorialScene/UI/btn_press.png");
    }
    _orc[i]->setPosition(Vec2(VISIBLESIZE.width / 2 - 200, VISIBLESIZE.height / 2 + 100));
    _skeletonMagus[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 100));
    _ghost[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 200, VISIBLESIZE.height / 2 + 100));
  }

  for (byte i = 0; i < 3; i++) {
    _monsterRemove[i] = Sprite::create("TutorialScene/UI/brazierfire_1_idle_00.png");
    /*if (i == 0) {
      _monsterRemove[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 50, 300));
    } else if (i == 1) {
      _monsterRemove[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 200, 300));
    } else {
      _monsterRemove[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 350, 300));
    }*/
  }

  for (byte i = 0; i < 3; i++) {
    _clickToPlace[i] = Sprite::create("TutorialScene/UI/elementalist_attack_wolf_00.png");
    /*if (i == 0) {
      _clickToPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 50, 300));
    } else if (i == 1) {
      _clickToPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 50, 300));
    } else {
      _clickToPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 50, 300));
    }*/
  }

  for (byte i = 0; i < 3; i++) {
    _transparencyPlace[i] = Sprite::create("TutorialScene/UI/effect_tooltip.png");
    if (i == 0) {
      _transparencyPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 150, 300));
    } else if (i == 1) {
      _transparencyPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 325, 300));
    } else {
      _transparencyPlace[i]->setPosition(Vec2(VISIBLESIZE.width / 2 + 500, 300));
    }
    _transparencyPlace[i]->setScaleX(1.2f);
    _transparencyPlace[i]->setScaleY(2.5f);
    _transparencyPlace[i]->setOpacity(0);
  }

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _previous[i] = Sprite::create("TutorialScene/UI/btn_state.png");
    } else if (i == 1) {
      _previous[i] = Sprite::create("TutorialScene/UI/btn_over.png");
    } else {
      _previous[i] = Sprite::create("TutorialScene/UI/btn_press.png");
    }
    _previous[i]->setPosition(Vec2(100, 100));
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

Sprite * TutorialUI::getOrc(byte i) {
  if (i == 0) {
    return _orc[i];
  } else if (i == 1) {
    return _orc[i];
  } else {
    return _orc[i];
  }
}

Sprite * TutorialUI::getSkeletonMagus(byte i) {
  if (i == 0) {
    return _skeletonMagus[i];
  } else if (i == 1) {
    return _skeletonMagus[i];
  } else {
    return _skeletonMagus[i];
  }
}

Sprite * TutorialUI::getGhost(byte i) {
  if (i == 0) {
    return _ghost[i];
  } else if (i == 1) {
    return _ghost[i];
  } else {
    return _ghost[i];
  }
}

Sprite * TutorialUI::getMonsterRemove(byte i) {
  if (i == 0) {
    return _monsterRemove[i];
  } else if (i == 1) {
    return _monsterRemove[i];
  } else {
    return _monsterRemove[i];
  }
}

Sprite * TutorialUI::getClickToPlace(byte i) {
  if (i == 0) {
    return _clickToPlace[i];
  } else if (i == 1) {
    return _clickToPlace[i];
  } else {
    return _clickToPlace[i];
  }
}

Sprite * TutorialUI::getTransparencyPlace(byte i) {
  if (i == 0) {
    return _transparencyPlace[i];
  } else if (i == 1) {
    return _transparencyPlace[i];
  } else {
    return _transparencyPlace[i];
  }
}

Sprite * TutorialUI::getPrevious(byte i) {
  if (i == 0) {
    return _previous[i];
  } else if (i == 1) {
    return _previous[i];
  } else {
    return _previous[i];
  }
}
