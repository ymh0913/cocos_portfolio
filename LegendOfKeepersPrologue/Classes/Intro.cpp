#include "Intro.h"

Intro::Intro(Scene * pScene, Layer* pUILayer[2], Layer* pLabelLayer) {  
  _uiLayer[0] = pUILayer[0];  // UI를 담을 레이어 주소 받아오기
  _uiLayer[1] = pUILayer[1];  // UI를 담을 레이어 주소 받아오기
  // 멤버변수 초기화
  _isSelect = false;
  _isOverTop = false;
  _isOverMiddle = false;
  _isOverBottom = false;

  // 인트로 배경 클래스
  _introBg = new (std::nothrow) IntroBg;
  pScene->addChild(_introBg->getKeyArtBackground());
  pScene->addChild(_introBg->getLegendOfKeepersLogo());

  // 인트로 UI 클래스
  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 5; i++) {
    _uiLayer[0]->addChild(_introUI->getBtnState(i));
    _uiLayer[0]->addChild(_introUI->getBtnOver(i));
    _introUI->getBtnOver(i)->setVisible(false);
  }

  for (byte i = 0; i < 2; i++) {
    _uiLayer[0]->addChild(_introUI->getIconDiscord(i));
    _uiLayer[0]->addChild(_introUI->getIconReddit(i));
    _uiLayer[0]->addChild(_introUI->getIconTwitter(i));
  }  
  _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
  _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(false);
  _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(false);
  pScene->addChild(_uiLayer[0]);

  _uiLayer[1]->addChild(_introUI->getSaveBorderBackground());
  _introUI->getSaveBorderBackground()->setVisible(false);
  for (byte i = 0; i < 3; i++) {
    _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveState(i));
    _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveHOver(i));
    _uiLayer[1]->addChild(_introUI->getSaveBorderNewsavePressed(i));
    _introUI->getSaveBorderNewsaveState(i)->setVisible(false);
    _introUI->getSaveBorderNewsaveHOver(i)->setVisible(false);
    _introUI->getSaveBorderNewsavePressed(i)->setVisible(false);
  }
  _uiLayer[1]->addChild(_introUI->getBtndeleteState());
  _introUI->getBtndeleteState()->setVisible(false);
  pScene->addChild(_uiLayer[1]);

  // 레이블을 담을 레이어 주소 받아오기
  _labelLayer = pLabelLayer;

  // 인트로 레이블 클래스
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer->addChild(_introLabel->getPlay());
  _labelLayer->addChild(_introLabel->getSettings());
  _labelLayer->addChild(_introLabel->getModding());
  _labelLayer->addChild(_introLabel->getCredits());
  _labelLayer->addChild(_introLabel->getQuit());
  _labelLayer->addChild(_introLabel->getV0602());
  pScene->addChild(_labelLayer);

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

  bool touchPlay = _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Play)->
    getBoundingBox().containsPoint(touchPoint);
  bool touchDelete = _introUI->getBtndeleteState()->
    getBoundingBox().containsPoint(touchPoint);

  if (touchPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _uiLayer[0]->setVisible(false);
    _uiLayer[1]->setVisible(true);
    _labelLayer->setVisible(false);
    _introBg->getLegendOfKeepersLogo()->setVisible(false);
    _introBg->getKeyArtBackground()->setOpacity(95);
    _introUI->getSaveBorderBackground()->setVisible(true);
    /*for (byte i = 0; i < 3; i++) {
      _introUI->getSaveBorderNewsaveState(i)->setVisible(true);
    }*/
    log("%d %d", _uiLayer[0]->getChildrenCount(), _uiLayer[1]->getChildrenCount());
  } else {
  }

  /*if (touchDelete) {
    _isSelect = _introUI->kSelectBtn_False;
    _uiLayer[0]->setVisible(true);
    _labelLayer->setVisible(true);
    _introBg->getLegendOfKeepersLogo()->setVisible(true);
    _introBg->getKeyArtBackground()->setOpacity(255);
  }*/

  return true;
}

void Intro::onMouseMove(Event * event) {
  // 마우스 위치를 담을 변수
  EventMouse* mousePosition = (EventMouse*)event;
  
  // 버튼 위에 있는 마우스를 담을 bool 변수
  bool overPlay = _introUI->getBtnState(_introUI->kIntroUIBtnOver_Play)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overSettings = _introUI->getBtnState(_introUI->kIntroUIBtnOver_Settings)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overModding = _introUI->getBtnState(_introUI->kIntroUIBtnOver_Modding)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overCredits = _introUI->getBtnState(_introUI->kIntroUIBtnOver_Credits)->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overQuit = _introUI->getBtnState(_introUI->kIntroUIBtnOver_Quit)->
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
  bool overdelete = _introUI->getBtndeleteState()->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  // bool 변수에 의해 반응할 조건문
  /*if (overPlay) {
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
  } else if (overReddit) {
    _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(false);
    _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(true);
  } else if (overTwitter) {
    _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(false);
    _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(true);
  } else if (overNewsaveTop && _isTouchPlay && !_isOverMiddle && !_isOverBottom) {
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Top)->
      setVisible(true);
    _isOverTop = true;
  } else if (overNewsaveMiddle && _isTouchPlay && !_isOverTop && !_isOverBottom) {
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Middle)->
      setVisible(true);
    _isOverMiddle = true;
  } else if (overNewsaveBottom && _isTouchPlay && !_isOverTop && !_isOverMiddle) {
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Bottom)->
      setVisible(true);
    _isOverBottom = true;
  } else {
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Play)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Settings)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Modding)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Credits)->setVisible(false);
    _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Quit)->setVisible(false);
    _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(true);
    _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
    _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(true);
    _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(false);
    _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(true);
    _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(false);
    _isOverTop = false;
    _isOverMiddle = false;
    _isOverBottom = false;
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Top)->
      setVisible(false);
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Middle)->
      setVisible(false);
    _introUI->getSaveBorderNewsaveHOver(_introUI->kSaveBorderNewsave_Bottom)->
      setVisible(false);
  }*/

  // UI버튼 선택하기 전에 반응할 조건문
  if (_isSelect == _introUI->kSelectBtn_False) {
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
    } else if (overReddit) {
      _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(false);
      _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(true);
    } else if (overTwitter) {
      _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(false);
      _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(true);
    } else {
      _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Play)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Settings)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Modding)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Credits)->setVisible(false);
      _introUI->getBtnOver(_introUI->kIntroUIBtnOver_Quit)->setVisible(false);
      _introUI->getIconDiscord(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconDiscord(_introUI->kIntroIcon_On)->setVisible(false);
      _introUI->getIconReddit(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconReddit(_introUI->kIntroIcon_On)->setVisible(false);
      _introUI->getIconTwitter(_introUI->kIntroIcon_Off)->setVisible(true);
      _introUI->getIconTwitter(_introUI->kIntroIcon_On)->setVisible(false);
    }
  }

  // Play버튼 선택 후 반응할 조건문
  if (_isSelect == _introUI->kSelectBtn_Play) {
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
    }
  }
}
