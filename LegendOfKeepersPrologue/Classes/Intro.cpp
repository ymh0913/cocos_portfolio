#include "Intro.h"

Intro::~Intro() {
  // �����Ҵ� ����
  CC_SAFE_DELETE(_introBg);
  CC_SAFE_DELETE(_introUI);
  CC_SAFE_DELETE(_introLabel);

  // �̺�Ʈ ������ ����
  _eventDispatcher->removeAllEventListeners();
}

Intro::Intro(Scene * pScene) {
  // ��Ʈ�� ��� Ŭ�� ���� �Ҵ�
  _introBg = new (std::nothrow) IntroBg;
  pScene->addChild(_introBg->getKeyArtBackground());
  pScene->addChild(_introBg->getLegendOfKeepersLogo());  

  // ��Ʈ�� UI Ŭ�� ���� �Ҵ�
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

  // ��Ʈ�� ���̺� Ŭ�� ���� �Ҵ�
  _introLabel = new (std::nothrow) IntroLabel;
  pScene->addChild(_introLabel->getPlay());
  pScene->addChild(_introLabel->getSettings());
  pScene->addChild(_introLabel->getModding());
  pScene->addChild(_introLabel->getCredits());
  pScene->addChild(_introLabel->getQuit());
  pScene->addChild(_introLabel->getV0602());

  // ��ġ �̺�Ʈ ���
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Intro::onTouchBegan, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           pScene);

  // ���콺 �̺�Ʈ ���
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
  // ���콺 ��ġ�� ���� ����
  EventMouse* mousePosition = (EventMouse*)event;
  
  // ��ư ���� �ִ� ���콺�� ���� bool ����
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


  // bool ������ ���� ������ ���ǹ�
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
