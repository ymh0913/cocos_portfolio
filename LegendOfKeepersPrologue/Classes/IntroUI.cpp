#include "IntroUI.h"

IntroUI::IntroUI() {
  for (byte i = 0; i < 5; i++) {
    _btnState[i] = Sprite::create("IntroScene/UI/btn_state.png");
    _btnState[i]->setScale(1.75f);
    _btnState[i]->setPosition(Vec2(990, 540 - i * 90));

    _btnOver[i] = Sprite::create("IntroScene/UI/btn_over.png");
    _btnOver[i]->setScale(1.75f);
    _btnOver[i]->setPosition(Vec2(990, 540 - i * 90));

    _btnPressed[i] = Sprite::create("IntroScene/UI/btn_press.png");
    _btnPressed[i]->setScale(1.75f);
    _btnPressed[i]->setPosition(Vec2(990, 540 - i * 90));
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

  _saveBorderBackground = Sprite::create(
    "IntroScene/UI/save_border_background.png");
  _saveBorderBackground->setScale(2);
  _saveBorderBackground->setPosition(Vec2(990, 540));

  for (byte i = 0; i < 3; i++) {
    _saveBorderNewsaveState[i] = Sprite::create(
      "IntroScene/UI/save_border_newsave_state.png");
    _saveBorderNewsaveState[i]->setScale(2);
    _saveBorderNewsaveState[i]->setPosition(Vec2(990, 720 - i * 180));

    _saveBorderNewsaveHOver[i] = Sprite::create(
      "IntroScene/UI/save_border_newsave_hover.png");
    _saveBorderNewsaveHOver[i]->setScale(2);
    _saveBorderNewsaveHOver[i]->setPosition(Vec2(990, 720 - i * 180));

    _saveBorderNewsavePressed[i] = Sprite::create(
      "IntroScene/UI/save_border_newsave_pressed.png");
    _saveBorderNewsavePressed[i]->setScale(2);
    _saveBorderNewsavePressed[i]->setPosition(Vec2(990, 720 - i * 180));
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
  }
  
  for (byte i = 0; i < 3; i++) {
    _btnBack[i]->setScale(2);
    _btnBack[i]->setPosition(Vec2(720, 150));
    _btnDelete[i]->setScale(2);
    _btnDelete[i]->setPosition(Vec2(990, 150));
    _btnConfirm[i]->setScale(2);
    _btnConfirm[i]->setPosition(Vec2(1260, 150));
  }
}

Sprite * IntroUI::getBtnState(byte i) {
  if (i == 0) {
    return _btnState[i];
  } else if (i == 1) {
    return _btnState[i];
  } else if (i == 2) {
    return _btnState[i];
  } else if (i == 3) {
    return _btnState[i];
  } else {
    return _btnState[i];
  }
}

Sprite * IntroUI::getBtnOver(byte i) {
  if (i == 0) {
    return _btnOver[i];
  } else if (i == 1) {
    return _btnOver[i];
  } else if (i == 2) {
    return _btnOver[i];
  } else if (i == 3) {
    return _btnOver[i];
  } else {
    return _btnOver[i];
  }
}

Sprite * IntroUI::getBtnPressed(byte i) {
  if (i == 0) {
    return _btnPressed[i];
  } else if (i == 1) {
    return _btnPressed[i];
  } else if (i == 2) {
    return _btnPressed[i];
  } else if (i == 3) {
    return _btnPressed[i];
  } else {
    return _btnPressed[i];
  }
}

Sprite * IntroUI::getIconDiscord(byte i) {
  if (i == 0) {    
    return _iconDiscord[i];
  } else {    
    return _iconDiscord[i];
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

Sprite * IntroUI::getSaveBorderBackground() {
  return _saveBorderBackground;
}

Sprite * IntroUI::getSaveBorderNewsaveState(byte i) {
  if (i == 0) {
    return _saveBorderNewsaveState[i];
  } else if (i == 1) {
    return _saveBorderNewsaveState[i];
  } else {
    return _saveBorderNewsaveState[i];
  }  
}

Sprite * IntroUI::getSaveBorderNewsaveHOver(byte i) {
  if (i == 0) {
    return _saveBorderNewsaveHOver[i];
  } else if (i == 1) {
    return _saveBorderNewsaveHOver[i];
  } else {
    return _saveBorderNewsaveHOver[i];
  }
}

Sprite * IntroUI::getSaveBorderNewsavePressed(byte i) {
  if (i == 0) {
    return _saveBorderNewsavePressed[i];
  } else if (i == 1) {
    return _saveBorderNewsavePressed[i];
  } else {
    return _saveBorderNewsavePressed[i];
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
