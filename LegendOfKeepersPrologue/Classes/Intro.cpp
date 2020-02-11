#include "Intro.h"

Intro::Intro(Scene * pScene) {
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }
  _bgLayer = Layer::create();

  // 멤버변수 초기화
  _isSelect = false;
  _isOverTop = false;
  _isOverMiddle = false;
  _isOverBottom = false;

  // 인트로 배경 클래스
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer->addChild(_introBg->getKeyArtBackground(), 0, "인트로배경");
  _bgLayer->addChild(_introBg->getLegendOfKeepersLogo(), 0, "인트로로고");
  pScene->addChild(_bgLayer);
  
  // 인트로 UI 클래스
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

  _uiLayer[1]->addChild(_introUI->getSaveBorderBackground(), 0, "저장경계배경");
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯");
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯");
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

  if (touchPlay) {
    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
  }

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool clickPlay = _uiLayer[0]->getChildByName("Play버튼클릭")->
    getBoundingBox().containsPoint(touchPoint);

  if (clickPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _uiLayer[1]->setVisible(true);
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

  if (overPlay) {
    _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
  }
}