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
  _isTop = false;
  _isMiddle = false;
  _isBottom = false;

  // 배경 클래스
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer[0]->addChild(_introBg->getKeyArtBackground(), 0, "인트로배경");
  _bgLayer[0]->addChild(_introBg->getLegendOfKeepersLogo(), 0, "인트로로고");
  pScene->addChild(_bgLayer[0]);

  _bgLayer[1]->addChild(_introBg->getSaveBorderBackground(), 0, "저장경계배경");
  _bgLayer[1]->setVisible(false);
  pScene->addChild(_bgLayer[1]);

  _bgLayer[2]->addChild(_introBg->getTutorialBorderBackground(), 0, "튜토리얼경계배경");
  _bgLayer[2]->setVisible(false);
  pScene->addChild(_bgLayer[2]);

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
      _uiLayer[0]->addChild(_introUI->getIconFacebook(i), 0, "Facebook아이콘기본");
    } else {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord아이콘오버");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit아이콘오버");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter아이콘오버");
      _uiLayer[0]->addChild(_introUI->getIconFacebook(i), 0, "Facebook아이콘오버");
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook아이콘오버")->setVisible(false);
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
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create버튼기본");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯오버");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯오버");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯오버");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back버튼오버");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete버튼오버");
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create버튼오버");
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼오버")->setVisible(false);
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom슬롯클릭");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back버튼클릭");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete버튼클릭");
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create버튼클릭");
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
    }
  }
  _uiLayer[1]->setVisible(false);
  pScene->addChild(_uiLayer[1]);

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No버튼기본");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes버튼기본");
    } else if (i == 1) {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No버튼오버");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes버튼오버");
      _uiLayer[2]->getChildByName("No버튼오버")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes버튼오버")->setVisible(false);
    } else {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No버튼클릭");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes버튼클릭");
      _uiLayer[2]->getChildByName("No버튼클릭")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes버튼클릭")->setVisible(false);
    }
  }
  _uiLayer[2]->setVisible(false);
  pScene->addChild(_uiLayer[2]);

  // Label 클래스
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer[0]->addChild(_introLabel->getPlay(), 0, "Play레이블");
  _labelLayer[0]->addChild(_introLabel->getSettings(), 0, "Settings레이블");
  _labelLayer[0]->addChild(_introLabel->getModding(), 0, "Modding레이블");
  _labelLayer[0]->addChild(_introLabel->getCredits(), 0, "Credtis레이블");
  _labelLayer[0]->addChild(_introLabel->getQuit(), 0, "Quit레이블");
  _labelLayer[0]->addChild(_introLabel->getV0602(), 0, "v0.6.0.2레이블");  
  pScene->addChild(_labelLayer[0]);

  _labelLayer[1]->addChild(_introLabel->getTitleSaveTop(), 0, "TitleSaveTop레이블");
  _labelLayer[1]->addChild(_introLabel->getTitleSaveMiddle(), 0, "TitleSaveMiddle레이블");
  _labelLayer[1]->addChild(_introLabel->getTitleSaveBottom(), 0, "TitleSaveBottom레이블");
  _labelLayer[1]->addChild(_introLabel->getBack(), 0, "Back레이블");
  _labelLayer[1]->addChild(_introLabel->getDelete(), 0, "Delete레이블");
  _labelLayer[1]->addChild(_introLabel->getCreate(), 0, "Create레이블");
  _labelLayer[1]->setVisible(false);
  pScene->addChild(_labelLayer[1]);

  _labelLayer[2]->addChild(_introLabel->getTutorial(), 0, "tutorial?레이블");
  _labelLayer[2]->addChild(_introLabel->getNo(), 0, "No레이블");
  _labelLayer[2]->addChild(_introLabel->getYes(), 0, "Yes레이블");
  _labelLayer[2]->setVisible(false);
  pScene->addChild(_labelLayer[2]);


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

  bool touchPlay = false, touchSettings = false, touchModding = false,
    touchCredits = false, touchQuit = false;
  bool touchTop = false, touchMiddle = false, touchBottom = false, touchBack,
    touchDelete = false, touchCreate = false;

  if (_isSelect == _introUI->kSelectBtn_False) {
    touchPlay = _uiLayer[0]->getChildByName("Play버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchSettings = _uiLayer[0]->getChildByName("Settings버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchModding = _uiLayer[0]->getChildByName("Modding버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchCredits = _uiLayer[0]->getChildByName("Credits버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchQuit = _uiLayer[0]->getChildByName("Quit버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchPlay) {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(true);
    } else if (touchSettings) {
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(true);
    } else if (touchModding) {
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(true);
    } else if (touchCredits) {
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(true);
    } else if (touchQuit) {
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    touchTop = _uiLayer[1]->getChildByName("Top슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchMiddle = _uiLayer[1]->getChildByName("Middle슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchBottom = _uiLayer[1]->getChildByName("Bottom슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchBack = _uiLayer[1]->getChildByName("Back버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchDelete = _uiLayer[1]->getChildByName("Delete버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchCreate = _uiLayer[1]->getChildByName("Create버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchTop) {
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
    } else if (touchMiddle) {
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
    } else if (touchBottom) {
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
    } else if (touchBack) {
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(true);
    } else if (touchDelete) {
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(true);
    } else if (touchCreate && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
    }
  }

  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (touchPlay) {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(true);
    } else if (touchSettings) {
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(true);
    } else if (touchModding) {
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(true);
    } else if (touchCredits) {
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(true);
    } else if (touchQuit) {
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    }
  }*/
  
  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    touchTop = _uiLayer[1]->getChildByName("Top슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchMiddle = _uiLayer[1]->getChildByName("Middle슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchBottom = _uiLayer[1]->getChildByName("Bottom슬롯오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchBack = _uiLayer[1]->getChildByName("Back버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchDelete = _uiLayer[1]->getChildByName("Delete버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    touchCreate = _uiLayer[1]->getChildByName("Create버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
  }*/

  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    if (touchTop) {
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
    } else if (touchMiddle) {
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
    } else if (touchBottom) {
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(true);
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
    } else if (touchBack) {
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(true);
    } else if (touchDelete) {
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(true);
    } else if (touchCreate && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
    }
  }*/

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  // 인트로씬에서 마우스 클릭을 담을 변수
  bool clickPlay = false, clickSettings = false, clickModding = false,
    clickCredits = false, clickQuit = false;
  // Play버튼을 누른 후 마우스 클릭을 담을 변수
  bool clickTop = false, clickMiddle = false, clickBottom = false,
    clickBack = false, clickDelete = false, clickCreate = false;
  // Create버튼을 누른 후 마우스 클릭을 담을 변수
  bool clickNo = false, clickYes = false;
  
  if (_isSelect == _introUI->kSelectBtn_False) {
    clickPlay = _uiLayer[0]->getChildByName("Play버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickSettings = _uiLayer[0]->getChildByName("Settings버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickModding = _uiLayer[0]->getChildByName("Modding버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickCredits = _uiLayer[0]->getChildByName("Credits버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickQuit = _uiLayer[0]->getChildByName("Quit버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickPlay) {
      _isSelect = _introUI->kSelectBtn_Play;
      _bgLayer[1]->setVisible(true);
      _uiLayer[1]->setVisible(true);
      _labelLayer[1]->setVisible(true);
      _bgLayer[0]->getChildByName("인트로배경")->setOpacity(95);
      _bgLayer[0]->getChildByName("인트로로고")->setVisible(false);
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->setVisible(false);
      _labelLayer[0]->setVisible(false);
    } else if (clickSettings) {
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
    } else if (clickModding) {
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
    } else if (clickCredits) {
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
    } else if (clickQuit) {
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    } else {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    clickTop = _uiLayer[1]->getChildByName("Top슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickMiddle = _uiLayer[1]->getChildByName("Middle슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickBottom = _uiLayer[1]->getChildByName("Bottom슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickBack = _uiLayer[1]->getChildByName("Back버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickDelete = _uiLayer[1]->getChildByName("Delete버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickCreate = _uiLayer[1]->getChildByName("Create버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickTop) {
      _isTop = true;
      _isMiddle = false;
      _isBottom = false;
    } else if (clickMiddle) {
      _isMiddle = true;
      _isTop = false;
      _isBottom = false;
    } else if (clickBottom) {
      _isBottom = true;
      _isTop = false;
      _isMiddle = false;
    } else if (clickBack) {
      _isSelect = _introUI->kSelectBtn_False;
      _bgLayer[0]->getChildByName("인트로배경")->setOpacity(255);
      _bgLayer[0]->getChildByName("인트로로고")->setVisible(true);
      _uiLayer[0]->setVisible(true);
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _labelLayer[0]->setVisible(true);
      _bgLayer[1]->setVisible(false);
      _uiLayer[1]->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _labelLayer[1]->setVisible(false);
    } else if (clickDelete/* 세이브파일이 만들어지고 활성화될 것*/) {

    } else if (clickCreate && (_isTop || _isMiddle || _isBottom)) {
      _isSelect = _introUI->kSelectBtn_Create;
      _bgLayer[2]->setVisible(true);
      _uiLayer[2]->setVisible(true);
      _labelLayer[2]->setVisible(true);
      _bgLayer[1]->setVisible(false);
      _uiLayer[1]->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
      _labelLayer[1]->setVisible(false);
    } else {
      _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Create) {
    clickNo = _uiLayer[2]->getChildByName("No버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickYes = _uiLayer[2]->getChildByName("Yes버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    if (_isSelect == _introUI->kSelectBtn_Create) {
      if (clickNo) {
        _uiLayer[2]->getChildByName("No버튼클릭")->setVisible(true);
      } else if (clickYes) {
        _uiLayer[2]->getChildByName("Yes버튼클릭")->setVisible(true);
        auto pScene = TutorialScene::createScene();
        DIRECTOR->replaceScene(pScene);
      } else {
        _uiLayer[2]->getChildByName("No버튼클릭")->setVisible(false);
        _uiLayer[2]->getChildByName("Yes버튼클릭")->setVisible(false);
      }
    }
  }

  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (clickPlay) {
      _isSelect = _introUI->kSelectBtn_Play;
      _bgLayer[1]->setVisible(true);
      _uiLayer[1]->setVisible(true);
      _labelLayer[1]->setVisible(true);
      _bgLayer[0]->getChildByName("인트로배경")->setOpacity(95);
      _bgLayer[0]->getChildByName("인트로로고")->setVisible(false);
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->setVisible(false);
      _labelLayer[0]->setVisible(false);
    } else if (clickSettings) {
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
    } else if (clickModding) {
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
    } else if (clickCredits) {
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
    } else if (clickQuit) {
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    } else {
      _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼클릭")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼클릭")->setVisible(false);
    }
  }*/

  /*bool clickTop = false, clickMiddle = false, clickBottom = false,
    clickBack = false, clickDelete = false, clickCreate = false;
  if (_isSelect == _introUI->kSelectBtn_Play) {
    clickTop = _uiLayer[1]->getChildByName("Top슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickMiddle = _uiLayer[1]->getChildByName("Middle슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickBottom = _uiLayer[1]->getChildByName("Bottom슬롯클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickBack = _uiLayer[1]->getChildByName("Back버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickDelete = _uiLayer[1]->getChildByName("Delete버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickCreate = _uiLayer[1]->getChildByName("Create버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
  }*/

  //if (_isSelect == _introUI->kSelectBtn_Play) {
  //  if (clickTop) {
  //    _isTop = true;
  //    _isMiddle = false;
  //    _isBottom = false;
  //  } else if (clickMiddle) {
  //    _isMiddle = true;
  //    _isTop = false;
  //    _isBottom = false;
  //  } else if (clickBottom) {
  //    _isBottom = true;
  //    _isTop = false;
  //    _isMiddle = false;
  //  } else if (clickBack) {
  //    _isSelect = _introUI->kSelectBtn_False;
  //    _bgLayer[0]->getChildByName("인트로배경")->setOpacity(255);
  //    _bgLayer[0]->getChildByName("인트로로고")->setVisible(true);
  //    _uiLayer[0]->setVisible(true);
  //    _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
  //    _uiLayer[0]->getChildByName("Play버튼클릭")->setVisible(false);
  //    _labelLayer[0]->setVisible(true);      
  //    _bgLayer[1]->setVisible(false);
  //    _uiLayer[1]->setVisible(false);
  //    _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
  //    _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
  //    _labelLayer[1]->setVisible(false);
  //  } else if (clickDelete/* 세이브파일이 만들어지고 활성화될 것*/) {

  //  } else if (clickCreate && (_isTop || _isMiddle || _isBottom)) {
  //    _isSelect = _introUI->kSelectBtn_Create;
  //    _bgLayer[2]->setVisible(true);
  //    _uiLayer[2]->setVisible(true);
  //    _labelLayer[2]->setVisible(true);
  //    _bgLayer[1]->setVisible(false);
  //    _uiLayer[1]->setVisible(false);
  //    _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
  //    _labelLayer[1]->setVisible(false);
  //  } else {
  //    _uiLayer[1]->getChildByName("Back버튼클릭")->setVisible(false);
  //    _uiLayer[1]->getChildByName("Create버튼클릭")->setVisible(false);
  //  }
  //}

  /*bool clickNo = _uiLayer[2]->getChildByName("No버튼클릭")->
    getBoundingBox().containsPoint(touchPoint);
  bool clickYes = _uiLayer[2]->getChildByName("Yes버튼클릭")->
    getBoundingBox().containsPoint(touchPoint);

  if (_isSelect == _introUI->kSelectBtn_Create) {
    if (clickNo) {

    } else if (clickYes) {
      auto pScene = TutorialScene::createScene();
      DIRECTOR->replaceScene(pScene);
    } else {

    }
  }*/
}

void Intro::onMouseMove(Event * event) {
  // 마우스 위치를 담을 변수
  EventMouse* mousePosition = (EventMouse*)event;

  // 인트로씬에서 마우스가 버튼 위에 있는지 판단할 변수
  bool overPlay = false, overSettings = false, overModding = false,
    overCredits = false, overQuit = false, overDiscord = false,
    overReddit = false, overTwitter = false, overFacebook = false;
  // Play버튼을 누른 후 마우스가 버튼 위에 있는지 판단할 변수
  bool overTop = false, overMiddle = false, overBottom = false,
    overBack = false, overDelete = false, overCreate = false;
  // Create버튼을 누른 후 마우스가 버튼 위에 있는지 판단할 변수
  bool overNo = false, overYes = false;

  if (_isSelect == _introUI->kSelectBtn_False) {
    overPlay = _uiLayer[0]->getChildByName("Play버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overSettings = _uiLayer[0]->getChildByName("Settings버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overModding = _uiLayer[0]->getChildByName("Modding버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCredits = _uiLayer[0]->getChildByName("Credits버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overQuit = _uiLayer[0]->getChildByName("Quit버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDiscord = _uiLayer[0]->getChildByName("Discord아이콘기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overReddit = _uiLayer[0]->getChildByName("Reddit아이콘기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overTwitter = _uiLayer[0]->getChildByName("Twitter아이콘기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overFacebook = _uiLayer[0]->getChildByName("Facebook아이콘기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // 인트로씬에서 마우스가 버튼 위에 있을 때 실행할 조건문
    if (overPlay) {
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(true);
    } else if (overSettings) {
      _uiLayer[0]->getChildByName("Settings버튼오버")->setVisible(true);
    } else if (overModding) {
      _uiLayer[0]->getChildByName("Modding버튼오버")->setVisible(true);
    } else if (overCredits) {
      _uiLayer[0]->getChildByName("Credits버튼오버")->setVisible(true);
    } else if (overQuit) {
      _uiLayer[0]->getChildByName("Quit버튼오버")->setVisible(true);
    } else if (overDiscord) {
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(true);
    } else if (overReddit) {
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(true);
    } else if (overTwitter) {
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(true);
    } else if (overFacebook) {
      _uiLayer[0]->getChildByName("Facebook아이콘오버")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook아이콘오버")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    overTop = _uiLayer[1]->getChildByName("Top슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overMiddle = _uiLayer[1]->getChildByName("Middle슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBottom = _uiLayer[1]->getChildByName("Bottom슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBack = _uiLayer[1]->getChildByName("Back버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDelete = _uiLayer[1]->getChildByName("Delete버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCreate = _uiLayer[1]->getChildByName("Create버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // Play버튼을 누른 후 마우스가 버튼위에 있을 때 실행할 조건문
    if (overTop) {
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(true);
    } else if (overMiddle) {
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(true);
    } else if (overBottom) {
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(true);
    } else if (overBack) {
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(true);
    } else if (overDelete && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(true);
    } else if (overCreate) {
      _uiLayer[1]->getChildByName("Create버튼오버")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼오버")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Create) {
    overNo = _uiLayer[2]->getChildByName("No버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overYes = _uiLayer[2]->getChildByName("Yes버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // Create버튼을 누른 후 마우스가 버튼위에 있을 때 실행할 조건문
    if (overNo) {
      _uiLayer[2]->getChildByName("No버튼오버")->setVisible(true);
    } else if (overYes) {
      _uiLayer[2]->getChildByName("Yes버튼오버")->setVisible(true);
    } else {
      _uiLayer[2]->getChildByName("No버튼오버")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes버튼오버")->setVisible(false);
    }
  }

  // 인트로씬에서 마우스가 버튼 위에 있을 때 실행할 조건문
  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (overPlay) {
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(true);
    } else if (overSettings) {
      _uiLayer[0]->getChildByName("Settings버튼오버")->setVisible(true);
    } else if (overModding) {
      _uiLayer[0]->getChildByName("Modding버튼오버")->setVisible(true);
    } else if (overCredits) {
      _uiLayer[0]->getChildByName("Credits버튼오버")->setVisible(true);
    } else if (overQuit) {
      _uiLayer[0]->getChildByName("Quit버튼오버")->setVisible(true);
    } else if (overDiscord) {
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(true);
    } else if (overReddit) {
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(true);
    } else if (overTwitter) {
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(true);
    } else if (overFacebook) {
      _uiLayer[0]->getChildByName("Facebook아이콘오버")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Discord아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter아이콘오버")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook아이콘오버")->setVisible(false);
    }
  }*/

  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    overTop = _uiLayer[1]->getChildByName("Top슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overMiddle = _uiLayer[1]->getChildByName("Middle슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBottom = _uiLayer[1]->getChildByName("Bottom슬롯기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBack = _uiLayer[1]->getChildByName("Back버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDelete = _uiLayer[1]->getChildByName("Delete버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCreate = _uiLayer[1]->getChildByName("Create버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
  }*/

  // Play버튼을 누른 후 마우스가 버튼위에 있을 때 실행할 조건문
  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    if (overTop) {
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(true);
    } else if (overMiddle) {
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(true);
    } else if (overBottom) {
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(true);
    } else if (overBack) {
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(true);
    } else if (overDelete && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(true);
    } else if (overCreate) {
      _uiLayer[1]->getChildByName("Create버튼오버")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom슬롯오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Back버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("Create버튼오버")->setVisible(false);
    }
  }*/

  /*bool overNo = _uiLayer[2]->getChildByName("No버튼기본")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overYes = _uiLayer[2]->getChildByName("Yes버튼기본")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  if (_isSelect == _introUI->kSelectBtn_Create) {
    if (overNo) {
      _uiLayer[2]->getChildByName("No버튼오버")->setVisible(true);
    } else if (overYes) {
      _uiLayer[2]->getChildByName("Yes버튼오버")->setVisible(true);
    } else {
      _uiLayer[2]->getChildByName("No버튼오버")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes버튼오버")->setVisible(false);
    }
  }*/
}