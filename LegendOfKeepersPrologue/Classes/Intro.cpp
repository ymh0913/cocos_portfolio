#include "Intro.h"

Intro::Intro(Scene * pScene) {
  // 레이어 생성
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) {
    _bgLayer[i] = Layer::create();
  }

  // 멤버변수 초기화
  _isSelect = 0;
  _isOverTop = false;
  _isOverMiddle = false;
  _isOverBottom = false;

  // 배경 클래스
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer[0]->addChild(_introBg->getKeyArtBackground(), 0, "인트로배경");
  _bgLayer[0]->addChild(_introBg->getLegendOfKeepersLogo(), 0, "인트로로고");
  pScene->addChild(_bgLayer[0]);

  _bgLayer[1]->addChild(_introBg->getSaveBorderBackground(), 0, "저장경계배경");
  pScene->addChild(_bgLayer[1]);
  _bgLayer[1]->setVisible(false);

  // UI 클래스
  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play버튼기본");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings버튼기본");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding버튼기본");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits버튼기본");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit버튼기본");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play버튼오버");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings버튼오버");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding버튼오버");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits버튼오버");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit버튼오버");
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼오버")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play버튼클릭");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings버튼클릭");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding버튼클릭");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits버튼클릭");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit버튼클릭");
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    }
  }
  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord아이콘기본");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit아이콘기본");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter아이콘기본");
    } else {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord아이콘오버");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit아이콘오버");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter아이콘오버");
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(false);
    }
  }
  pScene->addChild(_uiLayer[0]);

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯기본");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯기본");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯기본");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back버튼기본");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete버튼기본");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm버튼기본");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯오버");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯오버");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯오버");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back버튼오버");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete버튼오버");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm버튼오버");
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Confirm버튼오버")->setVisible(false);
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back버튼클릭");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete버튼클릭");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm버튼클릭");
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Confirm버튼클릭")->setVisible(false);
    }
  }
  pScene->addChild(_uiLayer[1]);
  _uiLayer[1]->setVisible(false);

  // 인트로 레이블 클래스
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer[0]->addChild(_introLabel->getPlay(), 0, "Play레이블");
  _labelLayer[0]->addChild(_introLabel->getSettings(), 0, "Settings레이블");
  _labelLayer[0]->addChild(_introLabel->getModding(), 0, "Modding레이블");
  _labelLayer[0]->addChild(_introLabel->getCredits(), 0, "Credtis레이블");
  _labelLayer[0]->addChild(_introLabel->getQuit(), 0, "Quit레이블");
  _labelLayer[0]->addChild(_introLabel->getV0602(), 0, "v0.6.0.2레이블");  
  pScene->addChild(_labelLayer[0]);

  _labelLayer[1]->addChild(_introLabel->getBack(), 0, "Back레이블");
  _labelLayer[1]->addChild(_introLabel->getDelete(), 0, "Delete레이블");
  _labelLayer[1]->addChild(_introLabel->getConfirm(), 0, "Confirm레이블");
  pScene->addChild(_labelLayer[1]);
  _labelLayer[1]->setVisible(false);

  // 터치 이벤트 등록
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Intro::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Intro::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           pScene);

  // 마우스 이벤트 등록
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Intro::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                           pScene);
}

Intro::~Intro() {
  // 동적할당 해제
  CC_SAFE_DELETE(_introBg);
  CC_SAFE_DELETE(_introUI);
  CC_SAFE_DELETE(_introLabel);

  // 모든 이벤트 리스너 해제
  _eventDispatcher->removeAllEventListeners();
}

bool Intro::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchPlay = _uiLayer[0]->getChildByName("Play버튼오버")->
    getBoundingBox().containsPoint(touchPoint);
  bool touchBack = _uiLayer[1]->getChildByName("Back버튼오버")->
    getBoundingBox().containsPoint(touchPoint);

  if (touchPlay) {
    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(true);
  } else if (touchBack) {
    _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
  }

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool clickPlay = _uiLayer[0]->getChildByName("Play버튼클릭")->
    getBoundingBox().containsPoint(touchPoint);
  bool clickBack = _uiLayer[1]->getChildByName("Back버튼클릭")->
    getBoundingBox().containsPoint(touchPoint);

  if (clickPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _bgLayer[1]->setVisible(true);
    _uiLayer[1]->setVisible(true);
    _labelLayer[1]->setVisible(true);
    _bgLayer[0]->getChildByName("인트로배경")->setOpacity(95);
    _bgLayer[0]->getChildByName("인트로로고")->setVisible(false);
    _uiLayer[0]->setVisible(false);
    _labelLayer[0]->setVisible(false);
  } else if (clickBack) {
    _isSelect = _introUI->kSelectBtn_False;
    _bgLayer[0]->getChildByName("인트로배경")->setOpacity(255);
    _bgLayer[0]->getChildByName("인트로로고")->setVisible(true);
    _uiLayer[0]->setVisible(true);
    _labelLayer[0]->setVisible(true);
    _bgLayer[1]->setVisible(false);
    _uiLayer[1]->setVisible(false);
    _labelLayer[1]->setVisible(false);
  } else {
    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
  }
}

void Intro::onMouseMove(Event * event) {
  // 마우스 위치를 담을 변수
  EventMouse* mousePosition = (EventMouse*)event;

  bool overPlay = _uiLayer[0]->getChildByName("Play버튼기본")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overBack = _uiLayer[1]->getChildByName("Back버튼기본")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  if (overPlay) {
    _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(true);
  } else if (overBack) {
    _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
    _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
  }
}