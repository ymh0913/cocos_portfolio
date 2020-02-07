#include "Intro.h"

Intro::~Intro() {
  // 동적할당 해제
  CC_SAFE_DELETE(_introBg);
  CC_SAFE_DELETE(_introUI);
  CC_SAFE_DELETE(_introLabel);

  // 이벤트 리스너 해제
  _eventDispatcher->removeAllEventListeners();
}

Intro::Intro(Scene * pScene) {
  // 인트로 배경 클라스 동적 할당
  _introBg = new (std::nothrow) IntroBg;
  pScene->addChild(_introBg->getKeyArtBackground());
  pScene->addChild(_introBg->getLegendOfKeepersLogo());  

  // 인트로 UI 클라스 동적 할당
  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 5; i++) {
    pScene->addChild(_introUI->getBtnState(i));
    pScene->addChild(_introUI->getBtnOver(i));
    _introUI->getBtnOver(i)->setVisible(false);
  }
  for (byte i = 0; i < 2; i++) {
    pScene->addChild(_introUI->getIconDiscord(i));
    pScene->addChild(_introUI->getIconReddit(i));
  }
  _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
  _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(false);

  // 인트로 레이블 클라스 동적 할당
  _introLabel = new (std::nothrow) IntroLabel;
  pScene->addChild(_introLabel->getPlay());
  pScene->addChild(_introLabel->getSettings());
  pScene->addChild(_introLabel->getModding());
  pScene->addChild(_introLabel->getCredits());
  pScene->addChild(_introLabel->getQuit());
  pScene->addChild(_introLabel->getV0602());

  // 터치 이벤트 등록
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Intro::onTouchBegan, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           pScene);

  // 마우스 이벤트 등록
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Intro::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                           pScene);
}

bool Intro::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  return true;
}

void Intro::onMouseMove(Event * event) {
  // 마우스 위치를 담을 변수
  EventMouse* mousePosition = (EventMouse*)event;
  
  // 버튼 위에 있는 마우스를 담을 bool 변수
  bool overPlay = _introUI->getBtnState(0)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overSettings = _introUI->getBtnState(1)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overModding = _introUI->getBtnState(2)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overCredits = _introUI->getBtnState(3)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overQuit = _introUI->getBtnState(4)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overDiscord = _introUI->getIconDiscord()->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));


  // bool 변수에 의해 반응할 조건문
  if (overPlay) {
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Play)->setVisible(true);
  } else if (overSettings) {       
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Settings)->setVisible(true);
  } else if (overModding) {        
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Modding)->setVisible(true);
  } else if (overCredits) {        
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Credits)->setVisible(true);
  } else if (overQuit) {           
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Quit)->setVisible(true);
  } else if (overDiscord) {
    _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(false);
    _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(true);
  } else {
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Play)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Settings)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Modding)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Credits)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Quit)->setVisible(false);
    _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(true);
    _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
  }
}
