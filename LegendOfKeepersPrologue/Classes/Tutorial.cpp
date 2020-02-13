#include "Tutorial.h"

Tutorial::Tutorial(Scene * pScene) {
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) {
    _bgLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_unitLayer) / sizeof(Layer*); i++) {
    _unitLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_trapLayer) / sizeof(Layer*); i++) {
    _trapLayer[i] = Layer::create();
  }

  // 배경 클래스
  _tutorialBg = new (std::nothrow) TutorialBg;
  _bgLayer[0]->addChild(_tutorialBg->getBgDungeonRoom(), 0, "튜토리얼배경");
  _bgLayer[0]->addChild(_tutorialBg->getDRH(), 0, "DRH");
  _bgLayer[0]->addChild(_tutorialBg->getDRHSpeak(), 0, "DRHSpeak");
  _bgLayer[0]->getChildByName("DRHSpeak")->runAction(_tutorialBg->getDRHSpeakAction());
  _bgLayer[0]->addChild(_tutorialBg->getDRHSpeakEye(), 0, "DRHSpeakEye");
  _bgLayer[0]->getChildByName("DRHSpeakEye")->runAction(_tutorialBg->getDRHSpeakEyeAction());
  _bgLayer[0]->addChild(_tutorialBg->getBorderScreen(), 0, "BorderScreen");
  pScene->addChild(_bgLayer[0]);

  // UI 클래스
  _tutorialUI = new (std::nothrow) TutorialUI;
  
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "Option버튼기본");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "Option버튼오버");
      _uiLayer[0]->getChildByName("Option버튼오버")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "Option버튼클릭");
      _uiLayer[0]->getChildByName("Option버튼클릭")->setVisible(false);
    }
  }
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "Continue버튼기본");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "Continue버튼오버");
      _uiLayer[0]->getChildByName("Continue버튼오버")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "Continue버튼클릭");
      _uiLayer[0]->getChildByName("Continue버튼클릭")->setVisible(false);
    }
  }
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconTraps(), 0, "roomIconTraps");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconSpell(), 0, "roomIconSpell");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconMonster3(), 0, "roomIconMoster3");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconBoss(), 0, "roomIconBoss");
  pScene->addChild(_uiLayer[0]);

  // Label 클래스
  _tutorialLabel = new (std::nothrow) TutorialLabel;
  _labelLayer[0]->addChild(_tutorialLabel->getCongratulations(), 0, "Congratulations");
  _labelLayer[0]->addChild(_tutorialLabel->getContinue(), 0, "Continue");
  _labelLayer[0]->addChild(_tutorialLabel->getHeroes(), 0, "Heroes");
  _labelLayer[0]->getChildByName("Heroes")->setVisible(false);
  pScene->addChild(_labelLayer[0]);

  // Unit 클래스
  _tutorialUnit = new (std::nothrow) TutorialUnit;
  _unitLayer[0]->addChild(_tutorialUnit->getKaron(), 0, "karonIdle");
  _unitLayer[0]->getChildByName("karonIdle")->runAction(
    _tutorialUnit->getKaronIdleAction());
  _unitLayer[0]->addChild(_tutorialUnit->getMardin(), 0, "mardinIdle");
  _unitLayer[0]->getChildByName("mardinIdle")->runAction(
    _tutorialUnit->getMardinIdleAction());
  _unitLayer[0]->addChild(_tutorialUnit->getThokhall(), 0, "thokhallIdle");
  _unitLayer[0]->getChildByName("thokhallIdle")->runAction(
    _tutorialUnit->getThokhallIdleAction());
  pScene->addChild(_unitLayer[0]);

  // Trap 클래스
  _tutorialTrap = new (std::nothrow) TutorialTrap;
  _trapLayer[0]->addChild(_tutorialTrap->getBoneCatapult(), 0, "boneCatapult");
  pScene->addChild(_trapLayer[0]);

  // 터치 이벤트 등록
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Tutorial::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Tutorial::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           pScene);

  // 마우스 이벤트 등록
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Tutorial::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                           pScene);
}

Tutorial::~Tutorial() {
  CC_SAFE_DELETE(_tutorialBg);
  CC_SAFE_DELETE(_tutorialUI);
  CC_SAFE_DELETE(_tutorialLabel);
  CC_SAFE_DELETE(_tutorialUnit);
  CC_SAFE_DELETE(_tutorialTrap);
}

bool Tutorial::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  return true;
}

void Tutorial::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();
}

void Tutorial::onMouseMove(Event * event) {
  EventMouse* mousePosition = (EventMouse*)event;
}
