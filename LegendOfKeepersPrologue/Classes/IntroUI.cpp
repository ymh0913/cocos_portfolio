#include "IntroUI.h"

IntroUI::IntroUI() {
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _btnPlay[i] = Sprite::create("IntroScene/UI/btn_state.png");
      _btnSettings[i] = Sprite::create("IntroScene/UI/btn_state.png");
      _btnModding[i] = Sprite::create("IntroScene/UI/btn_state.png");
      _btnCredits[i] = Sprite::create("IntroScene/UI/btn_state.png");
      _btnQuit[i] = Sprite::create("IntroScene/UI/btn_state.png");
    } else if (i == 1) {
      _btnPlay[i] = Sprite::create("IntroScene/UI/btn_over.png");
      _btnSettings[i] = Sprite::create("IntroScene/UI/btn_over.png");
      _btnModding[i] = Sprite::create("IntroScene/UI/btn_over.png");
      _btnCredits[i] = Sprite::create("IntroScene/UI/btn_over.png");
      _btnQuit[i] = Sprite::create("IntroScene/UI/btn_over.png");
    } else {
      _btnPlay[i] = Sprite::create("IntroScene/UI/btn_press.png");
      _btnSettings[i] = Sprite::create("IntroScene/UI/btn_press.png");
      _btnModding[i] = Sprite::create("IntroScene/UI/btn_press.png");
      _btnCredits[i] = Sprite::create("IntroScene/UI/btn_press.png");
      _btnQuit[i] = Sprite::create("IntroScene/UI/btn_press.png");
    }
    _btnPlay[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 50));
    _btnSettings[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 100));
    _btnModding[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 150));
    _btnCredits[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 200));
    _btnQuit[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 250));
  }

  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _iconDiscord[i] = Sprite::create("IntroScene/UI/icon_discord_off.png");
      _iconDiscord[i]->setPosition(Vec2(120, 100));
      _iconReddit[i] = Sprite::create("IntroScene/UI/icon_reddit_off.png");
      _iconReddit[i]->setPosition(Vec2(170, 100));
      _iconReddit[i] = Sprite::create("IntroScene/UI/icon_reddit_off.png");
      _iconReddit[i]->setPosition(Vec2(170, 100));
      _iconTwitter[i] = Sprite::create("IntroScene/UI/icon_twitter_off.png");
      _iconTwitter[i]->setPosition(Vec2(220, 100));
    } else {
      _iconDiscord[i] = Sprite::create("IntroScene/UI/icon_discord_on.png");
      _iconDiscord[i]->setPosition(Vec2(120, 100));
      _iconReddit[i] = Sprite::create("IntroScene/UI/icon_reddit_on.png");
      _iconReddit[i]->setPosition(Vec2(170, 100));
      _iconReddit[i] = Sprite::create("IntroScene/UI/icon_reddit_on.png");
      _iconReddit[i]->setPosition(Vec2(170, 100));
      _iconTwitter[i] = Sprite::create("IntroScene/UI/icon_twitter_on.png");
      _iconTwitter[i]->setPosition(Vec2(220, 100));
    }
  }

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _saveBorderNewsaveTop[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_state.png");
      _saveBorderNewsaveTop[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 60));
      _saveBorderNewsaveMiddle[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_state.png");
      _saveBorderNewsaveMiddle[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 60));
      _saveBorderNewsaveBottom[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_state.png");
      _saveBorderNewsaveBottom[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 180));
    } else if (i == 1) {
      _saveBorderNewsaveTop[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_hover.png");
      _saveBorderNewsaveTop[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 60));
      _saveBorderNewsaveMiddle[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_hover.png");
      _saveBorderNewsaveMiddle[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 60));
      _saveBorderNewsaveBottom[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_hover.png");
      _saveBorderNewsaveBottom[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 180));
    } else {
      _saveBorderNewsaveTop[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_pressed.png");
      _saveBorderNewsaveTop[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 60));
      _saveBorderNewsaveMiddle[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_pressed.png");
      _saveBorderNewsaveMiddle[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 60));
      _saveBorderNewsaveBottom[i] = Sprite::create(
        "IntroScene/UI/save_border_newsave_pressed.png");
      _saveBorderNewsaveBottom[i]->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 180));
    }    
  }

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _btnBack[i] = Sprite::create("IntroScene/UI/btn_state.png");
      _btnDelete[i] = Sprite::create("IntroScene/UI/btndelete_state.png");
      _btnConfirm[i] = Sprite::create("IntroScene/UI/btn_state.png");
    } else if (i == 1) {
      _btnBack[i] = Sprite::create("IntroScene/UI/btn_over.png");
      _btnDelete[i] = Sprite::create("IntroScene/UI/btndelete_over.png");
      _btnConfirm[i] = Sprite::create("IntroScene/UI/btn_over.png");
    } else {
      _btnBack[i] = Sprite::create("IntroScene/UI/btn_press.png");
      _btnDelete[i] = Sprite::create("IntroScene/UI/btndelete_press.png");
      _btnConfirm[i] = Sprite::create("IntroScene/UI/btn_press.png");
    }    
    _btnBack[i]->setPosition(Vec2(480, 100));    
    _btnDelete[i]->setPosition(Vec2(VISIBLESIZE.width / 2, 100));    
    _btnConfirm[i]->setPosition(Vec2(800, 100));
  }
}

Sprite * IntroUI::getIconDiscord(byte i) {
  if (i == 0) {    
    return _iconDiscord[i];
  } else {    
    return _iconDiscord[i];
  }
}

Sprite * IntroUI::getSaveBorderNewsaveTop(byte i) {
  if (i == 0) {
    return _saveBorderNewsaveTop[i];
  } else if (i == 1) {
    return _saveBorderNewsaveTop[i];
  } else {
    return _saveBorderNewsaveTop[i];
  }  
}

Sprite * IntroUI::getSaveBorderNewsaveMiddle(byte i) {
  if (i == 0) {
    return _saveBorderNewsaveMiddle[i];
  } else if (i == 1) {
    return _saveBorderNewsaveMiddle[i];
  } else {
    return _saveBorderNewsaveMiddle[i];
  }
}

Sprite * IntroUI::getSaveBorderNewsaveBottom(byte i) {
  if (i == 0) {
    return _saveBorderNewsaveBottom[i];
  } else if (i == 1) {
    return _saveBorderNewsaveBottom[i];
  } else {
    return _saveBorderNewsaveBottom[i];
  }
}

Sprite * IntroUI::getBtnPlay(byte i) {
  if (i == 0) {
    return _btnPlay[i];
  } else if (i == 1) {
    return _btnPlay[i];
  } else {
    return _btnPlay[i];
  }
}

Sprite * IntroUI::getBtnSettings(byte i) {
  if (i == 0) {
    return _btnSettings[i];
  } else if (i == 1) {
    return _btnSettings[i];
  } else {
    return _btnSettings[i];
  }
}

Sprite * IntroUI::getBtnModding(byte i) {
  if (i == 0) {
    return _btnModding[i];
  } else if (i == 1) {
    return _btnModding[i];
  } else {
    return _btnModding[i];
  }
}

Sprite * IntroUI::getBtnCredits(byte i) {
  if (i == 0) {
    return _btnCredits[i];
  } else if (i == 1) {
    return _btnCredits[i];
  } else {
    return _btnCredits[i];
  }
}

Sprite * IntroUI::getBtnQuit(byte i) {
  if (i == 0) {
    return _btnQuit[i];
  } else if (i == 1) {
    return _btnQuit[i];
  } else {
    return _btnQuit[i];
  }
}

Sprite * IntroUI::getIconReddit(byte i) {
  if (i == 0) {
    return _iconReddit[i];
  } else {
    return _iconReddit[i];
  }
}

Sprite * IntroUI::getIconTwitter(byte i) {
  if (i == 0) {
    return _iconTwitter[i];
  } else {
    return _iconTwitter[i];
  }
}

Sprite * IntroUI::getBtnBack(byte i) {
  if (i == 0) {
    return _btnBack[i];
  } else if (i == 1) {
    return _btnBack[i];
  } else {
    return _btnBack[i];
  }
}

Sprite * IntroUI::getBtnDelete(byte i) {
  if (i == 0) {
    return _btnDelete[i];
  } else if (i == 1) {
    return _btnDelete[i];
  } else {
    return _btnDelete[i];
  }
}

Sprite * IntroUI::getBtnConfirm(byte i) {
  if (i == 0) {
    return _btnConfirm[i];
  } else if (i == 1) {
    return _btnConfirm[i];
  } else {
    return _btnConfirm[i];
  }
}
