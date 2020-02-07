#include "IntroUI.h"

IntroUI::IntroUI() {
  for (byte i = 0; i < 5; i++) {
    _btnState[i] = Sprite::create("IntroScene/UI/btn_state.png");
    _btnState[i]->setScale(1.75f);
    _btnState[i]->setPosition(Vec2(960, 540 - i * 90));

    _btnOver[i] = Sprite::create("IntroScene/UI/btn_over.png");
    _btnOver[i]->setScale(1.75f);
    _btnOver[i]->setPosition(Vec2(960, 540 - i * 90));
  }
}

Sprite* IntroUI::getBtnState(byte i) {
  if (i == 0) {
    return _btnState[0];
  } else if (i == 1) {
    return _btnState[1];
  } else if (i == 2) {
    return _btnState[2];
  } else if (i == 3) {
    return _btnState[3];
  } else {
    return _btnState[4];
  }
}

Sprite* IntroUI::getBtnOver(byte i) {
  if (i == 0) {
    return _btnOver[0];
  } else if (i == 1) {
    return _btnOver[1];
  } else if (i == 2) {
    return _btnOver[2];
  } else if (i == 3) {
    return _btnOver[3];
  } else {
    return _btnOver[4];
  }
}

Sprite* IntroUI::getIconDiscord(byte i) {
  if (i == 0) {
    _iconDiscord = Sprite::create("IntroScene/UI/icon_discord_off.png");
    _iconDiscord->setPosition(Vec2(120, 100));
    return _iconDiscord;
  } else {
    _iconDiscord = Sprite::create("IntroScene/UI/icon_discord_on.png");
    _iconDiscord->setPosition(Vec2(120, 100));
    return _iconDiscord;
  }
}

Sprite * IntroUI::getIconReddit(byte i) {
  if (i == 0) {
    _iconReddit = Sprite::create("IntroScene/UI/icon_reddit_off.png");
    _iconReddit->setPosition(Vec2(170, 100));
    return _iconReddit;
  } else {
    _iconReddit = Sprite::create("IntroScene/UI/icon_reddit_on.png");
    _iconReddit->setPosition(Vec2(170, 100));
    return _iconReddit;
  }
}

Sprite * IntroUI::getIconTwitter(byte i) {
  if (i == 0) {
    _iconReddit = Sprite::create("IntroScene/UI/icon_reddit_off.png");
    _iconReddit->setPosition(Vec2(170, 100));
    return _iconReddit;
  } else {
    _iconReddit = Sprite::create("IntroScene/UI/icon_reddit_on.png");
    _iconReddit->setPosition(Vec2(170, 100));
    return _iconReddit;
  }
}
