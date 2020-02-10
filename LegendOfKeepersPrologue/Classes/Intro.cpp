#include "Intro.h"

Intro::Intro(Scene * pScene) {
  _scene = pScene;

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
  _initIntroUI = false;

  // 인트로 배경 클래스
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer->addChild(_introBg->getKeyArtBackground());
  _bgLayer->addChild(_introBg->getLegendOfKeepersLogo());
  _scene->addChild(_bgLayer);

  // 인트로 UI 클래스
  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 5; i++) {
    _uiLayer[0]->addChild(_introUI->getBtnState(i));
  }
  _uiLayer[0]->addChild(_introUI->getIconDiscord(_introUI->kIntroIcon_Off));
  _uiLayer[0]->addChild(_introUI->getIconReddit(_introUI->kIntroIcon_Off));
  _uiLayer[0]->addChild(_introUI->getIconTwitter(_introUI->kIntroIcon_Off));
  _scene->addChild(_uiLayer[0]);
  if (!_initIntroUI) {

  }

  /*_uiLayer[1]->addChild(_introUI->getSaveBorderBackground());
  for (byte i = 0; i < 3; i++) {
    _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveState(i));
  }
  _uiLayer[1]->addChild(_introUI->getBtnBack(_introUI->kSaveBorderBtn_State));
  _uiLayer[1]->addChild(_introUI->getBtnDelete(_introUI->kSaveBorderBtn_State));
  _uiLayer[1]->addChild(_introUI->getBtnConfirm(_introUI->kSaveBorderBtn_State));  
  _scene->addChild(_uiLayer[1]);*/


  //_labelLayer[1] = pLabelLayer[1];

  // 인트로 레이블 클래스
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer[0]->addChild(_introLabel->getPlay());
  _labelLayer[0]->addChild(_introLabel->getSettings());
  _labelLayer[0]->addChild(_introLabel->getModding());
  _labelLayer[0]->addChild(_introLabel->getCredits());
  _labelLayer[0]->addChild(_introLabel->getQuit());
  _labelLayer[0]->addChild(_introLabel->getV0602());
  _scene->addChild(_labelLayer[0]);

  /*_labelLayer[1]->addChild(_introLabel->getBack());
  _labelLayer[1]->addChild(_introLabel->getDelete());
  _labelLayer[1]->addChild(_introLabel->getConfirm());
  _scene->addChild(_labelLayer[1]);*/

  // 터치 이벤트 등록
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Intro::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Intro::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           _scene);

  // 마우스 이벤트 등록
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Intro::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                           _scene);
}

Intro::~Intro() {
  // 동적할당 해제
  CC_SAFE_DELETE(_introBg);
  CC_SAFE_DELETE(_introUI);
  CC_SAFE_DELETE(_introLabel);

  // 이벤트 리스너 해제
  _eventDispatcher->removeAllEventListeners();
}

bool Intro::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchPlay = _introUI->getBtnOver(_introUI->kIntroUIBtn_Play)->
    getBoundingBox().containsPoint(touchPoint);
  /*bool touchBack = _introUI->getBtnBack(_introUI->kSaveBorderBtn_Over)->
    getBoundingBox().containsPoint(touchPoint);*/

  if (touchPlay) {
    _introUI->getBtnPressed(_introUI->kIntroUIBtn_Play)->setVisible(true);
  } else if (/*touchBack*/0) {
    //_introUI->getBtnBack(_introUI->kSaveBorderBtn_Pressed)->setVisible(true);
  } else {
  }

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  /*bool touchPlay = _introUI->getBtnOver(_introUI->kIntroUIBtn_Play)->
    getBoundingBox().containsPoint(touchPoint);
  bool touchBack = _introUI->getBtnBack(_introUI->kSaveBorderBtn_Over)->
    getBoundingBox().containsPoint(touchPoint);

  if (touchPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _uiLayer[0]->setVisible(false);
    _labelLayer[0]->setVisible(false);
    _introBg->getLegendOfKeepersLogo()->setVisible(false);
    _introBg->getKeyArtBackground()->setOpacity(95);
    _introUI->getSaveBorderBackground()->setVisible(true);
    for (byte i = 0; i < 3; i++) {
      _introUI->getSaveBorderNewsaveState(i)->setVisible(true);
    }
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_State)->setVisible(true);
    _introUI->getBtnDelete(_introUI->kSaveBorderBtn_State)->setVisible(true);
    _introUI->getBtnConfirm(_introUI->kSaveBorderBtn_State)->setVisible(true);
    _introLabel->getBack()->setVisible(true);
    _introLabel->getDelete()->setVisible(true);
    _introLabel->getConfirm()->setVisible(true);
  } else if (touchBack) {
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_Pressed)->setVisible(true);
    _isSelect = _introUI->kSelectBtn_False;
    _uiLayer[0]->setVisible(true);
    _labelLayer[0]->setVisible(true);
    _introBg->getLegendOfKeepersLogo()->setVisible(true);
    _introBg->getKeyArtBackground()->setOpacity(255);
    _introUI->getSaveBorderBackground()->setVisible(false);
    for (byte i = 0; i < 3; i++) {
      _introUI->getSaveBorderNewsaveState(i)->setVisible(false);
    }
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_State)->setVisible(false);
    _introUI->getBtnDelete(_introUI->kSaveBorderBtn_State)->setVisible(false);
    _introUI->getBtnConfirm(_introUI->kSaveBorderBtn_State)->setVisible(false);
    _introLabel->getBack()->setVisible(false);
    _introLabel->getDelete()->setVisible(false);
    _introLabel->getConfirm()->setVisible(false);
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_Pressed)->setVisible(false);
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_Over)->setVisible(false);
    _introUI->getBtnPressed(_introUI->kIntroUIBtn_Play)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtn_Play)->setVisible(false);
  } else {
    _introUI->getBtnPressed(_introUI->kIntroUIBtn_Play)->setVisible(false);
    _introUI->getBtnBack(_introUI->kSaveBorderBtn_Pressed)->setVisible(false);
  }*/
}

void Intro::onMouseMove(Event * event) {
  // 마우스 위치를 담을 변수
  EventMouse* mousePosition = (EventMouse*)event;
  
  // 버튼 위에 있는 마우스를 담을 bool 변수
  bool overPlay = _introUI->getBtnState(_introUI->kIntroUIBtn_Play)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  /*bool overSettings = _introUI->getBtnState(_introUI->kIntroUIBtn_Settings)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overModding = _introUI->getBtnState(_introUI->kIntroUIBtn_Modding)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overCredits = _introUI->getBtnState(_introUI->kIntroUIBtn_Credits)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overQuit = _introUI->getBtnState(_introUI->kIntroUIBtn_Quit)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overDiscord = _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overReddit = _introUI->getIconReddit(_introUI->kIntroIcon_Off)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overTwitter = _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overNewsaveTop = _introUI->
    getSaveBorderNewsaveState(_introUI->kSaveBorderNewsave_Top)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overNewsaveMiddle = _introUI->
    getSaveBorderNewsaveState(_introUI->kSaveBorderNewsave_Middle)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overNewsaveBottom = _introUI->
    getSaveBorderNewsaveState(_introUI->kSaveBorderNewsave_Bottom)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overBack = _introUI->getBtnBack(_introUI->kSaveBorderBtn_State)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));*/

  // UI버튼 선택하기 전에 반응할 조건문
  if (_isSelect == _introUI->kSelectBtn_False) {
    if (overPlay) {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Play)->setVisible(true);
    } /*else if (overSettings) {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Settings)->setVisible(true);
    } else if (overModding) {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Modding)->setVisible(true);
    } else if (overCredits) {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Credits)->setVisible(true);
    } else if (overQuit) {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Quit)->setVisible(true);
    } else if (overDiscord) {
      _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(false);
      _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(true);
    } else if (overReddit) {
      _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(false);
      _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(true);
    } else if (overTwitter) {
      _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(false);
      _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(true);
    } else {
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Play)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Settings)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Modding)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Credits)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtn_Quit)->setVisible(false);
      _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
      _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(false);
      _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(false);
    }*/
  }

  // Play버튼 선택 후 반응할 조건문
  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    if (overNewsaveTop && !_isOverMiddle && !_isOverBottom) {
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Top)->
        setVisible(true);
      _isOverTop = true;
    } else if (overNewsaveMiddle && !_isOverTop && !_isOverBottom) {
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Middle)->
        setVisible(true);
      _isOverMiddle = true;
    } else if (overNewsaveBottom && !_isOverTop && !_isOverMiddle) {
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Bottom)->
        setVisible(true);
      _isOverBottom = true;
    } else if (overBack) {
      _introUI->getBtnBack(_introUI->kSaveBorderBtn_Over)->setVisible(true);
    } else {
      _isOverTop = false;
      _isOverMiddle = false;
      _isOverBottom = false;
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Top)->
        setVisible(false);
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Middle)->
        setVisible(false);
      _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Bottom)->
        setVisible(false);
      _introUI->getBtnBack(_introUI->kSaveBorderBtn_Over)->setVisible(false);
    }
  }*/
}

void Intro::initIntroUI() {
}

void Intro::initPlayUI() {
}
