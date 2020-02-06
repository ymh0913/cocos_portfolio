#include "Intro.h"

Intro::Intro(Scene * pScene) {
  _introBg = new (std::nothrow) IntroBg;
  pScene->addChild(_introBg->getKeyArtBackground());
  pScene->addChild(_introBg->getLegendOfKeepersLogo());

  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 5; i++) {
    pScene->addChild(_introUI->getBtnState(i));
  }
}
