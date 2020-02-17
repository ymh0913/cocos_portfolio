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
  for (byte i = 0; i < sizeof(_heroLayer) / sizeof(Layer*); i++) {
    _heroLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_trapLayer) / sizeof(Layer*); i++) {
    _trapLayer[i] = Layer::create();
  }

  srand(time(NULL));
  // 멤버변수 초기화
  _isContinue = 0;
  _isTrap = false;
  for (byte i = 0; i < 3; i++) {
    _checkBg[i] = rand() % 5;
  }
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < 3; j++) {
      if (i == j) {
        continue;
      }
      while (_checkBg[i] == _checkBg[j]) {
        _checkBg[i] = rand() % 5;
        if (_checkBg[i] != _checkBg[j]) {
          break;
        }
      }
    }
  }
  
  // 배경 클래스
  _tutorialBg = new (nothrow) TutorialBg;
  _bgLayer[0]->addChild(_tutorialBg->getDRH(), 0, "dRH");
  _bgLayer[0]->addChild(_tutorialBg->getDRHSpeak(), 0, "dRH입");
  _bgLayer[0]->getChildByName("dRH입")->runAction(_tutorialBg->getDRHSpeakAction());
  _bgLayer[0]->addChild(_tutorialBg->getDRHSpeakEye(), 0, "dRH눈");
  _bgLayer[0]->getChildByName("dRH눈")->runAction(_tutorialBg->getDRHSpeakEyeAction());
  pScene->addChild(_bgLayer[0]);

  _bgLayer[1]->addChild(_tutorialBg->getBgDungeonRoom(_checkBg[0]), 0, "튜토리얼배경");
  _bgLayer[1]->addChild(_tutorialBg->getBgDungeonGround(), 0, "튜토리얼땅배경");  
  _bgLayer[1]->addChild(_tutorialBg->getBorderScreen(), 0, "borderScreen");
  pScene->addChild(_bgLayer[1], -1);
  _bgLayer[1]->setOpacity(7);

  // UI 클래스
  _tutorialUI = new (nothrow) TutorialUI;  
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "option버튼기본");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "option버튼오버");
      _uiLayer[0]->getChildByName("option버튼오버")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_tutorialUI->getBtnOptions(i), 0, "option버튼클릭");
      _uiLayer[0]->getChildByName("option버튼클릭")->setVisible(false);
    }
  }
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼기본");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼오버");
      _uiLayer[0]->getChildByName("continue버튼오버")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼클릭");
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
    }
  }
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconTraps(), 0, "roomIconTraps");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconSpell(), 0, "roomIconSpell");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconMonster3(), 0, "roomIconMoster3");
  _uiLayer[0]->addChild(_tutorialUI->getRoomIconBoss(), 0, "roomIconBoss");
  pScene->addChild(_uiLayer[0]);

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[1]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼기본");
      _uiLayer[1]->getChildByName("boneCatapult버튼기본")->setVisible(false);
      _uiLayer[1]->addChild(_tutorialUI->getConfirm(i), 0, "confirm버튼기본");
      _uiLayer[1]->getChildByName("confirm버튼기본")->setVisible(false);
    } else if (i == 1) {
      _uiLayer[1]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼오버");
      _uiLayer[1]->getChildByName("boneCatapult버튼오버")->setVisible(false);
      _uiLayer[1]->addChild(_tutorialUI->getConfirm(i), 0, "confirm버튼오버");
      _uiLayer[1]->getChildByName("confirm버튼오버")->setVisible(false);
    } else {
      _uiLayer[1]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼클릭");
      _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
      _uiLayer[1]->addChild(_tutorialUI->getConfirm(i), 0, "confirm버튼클릭");
      _uiLayer[1]->getChildByName("confirm버튼클릭")->setVisible(false);
    }
  }  
  _uiLayer[1]->addChild(_tutorialUI->getTmp(), 0, "tmp");
  _uiLayer[1]->getChildByName("tmp")->setVisible(false);
  pScene->addChild(_uiLayer[1]);

  // Label 클래스
  _tutorialLabel = new (nothrow) TutorialLabel;
  _labelLayer[0]->addChild(_tutorialLabel->getCongratulations(), 0, "congratulations");
  _labelLayer[0]->addChild(_tutorialLabel->getContinue(), 0, "continue");
  _labelLayer[0]->addChild(_tutorialLabel->getHeroes(), 0, "heroes");
  _labelLayer[0]->getChildByName("heroes")->setVisible(false);
  pScene->addChild(_labelLayer[0]);

  _labelLayer[1]->addChild(_tutorialLabel->getBoneCatapult(), 0, "boneCatapult");
  _labelLayer[1]->getChildByName("boneCatapult")->setVisible(false);
  _labelLayer[1]->addChild(_tutorialLabel->getConfirm(), 0, "confirm");
  _labelLayer[1]->getChildByName("confirm")->setVisible(false);
  pScene->addChild(_labelLayer[1]);

  // Hero 클래스
  _tutorialHero = new (nothrow) TutorialHero;
  _heroLayer[0]->addChild(_tutorialHero->getScout(), -1, "scoutIdle");
  _heroLayer[0]->getChildByName("scoutIdle")->runAction(
    _tutorialHero->getScoutIdleAction());
  _heroLayer[0]->addChild(_tutorialHero->getScum(), -1, "scumIdle");
  _heroLayer[0]->getChildByName("scumIdle")->runAction(
    _tutorialHero->getScumIdleAction());
  _heroLayer[0]->addChild(_tutorialHero->getBarbarian(), -1, "barbarianIdle");
  _heroLayer[0]->getChildByName("barbarianIdle")->runAction(
    _tutorialHero->getBarbarianIdleAction());
  pScene->addChild(_heroLayer[0], -1);
  _heroLayer[0]->setOpacity(7);

  // Trap 클래스
  _tutorialTrap = new (nothrow) TutorialTrap;
  _trapLayer[0]->addChild(_tutorialTrap->getBoneCatapult(), 0, "boneCatapult");
  _trapLayer[0]->getChildByName("boneCatapult")->setVisible(false);
  _trapLayer[0]->addChild(_tutorialTrap->getBoneCatapultClone(), 0, "boneCatapultClone");
  _trapLayer[0]->getChildByName("boneCatapultClone")->setVisible(false);
  pScene->addChild(_trapLayer[0], -1);

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
  CC_SAFE_DELETE(_tutorialHero);
  CC_SAFE_DELETE(_tutorialTrap);
}

bool Tutorial::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchContinue = false, touchBoneCatapult = false;

  if (_isContinue < 2) {
    touchContinue = _uiLayer[0]->getChildByName("continue버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchContinue) {
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
    }
    
  } else {
    touchBoneCatapult = _uiLayer[1]->getChildByName("boneCatapult버튼오버")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchBoneCatapult) {
      _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
    }
  }

  return true;
}

void Tutorial::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool clickContinue = false, clickBoneCatapult = false, clickTmp = false;

  if (_isContinue == 0) {
    clickContinue = _uiLayer[0]->getChildByName("continue버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickContinue) {
      _isContinue++;
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
      _labelLayer[0]->getChildByName("congratulations")->setVisible(false);
      _labelLayer[0]->getChildByName("heroes")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
    }

  } else if (_isContinue == 1) {
    clickContinue = _uiLayer[0]->getChildByName("continue버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickContinue) {
      _isContinue++;
      _bgLayer[1]->setOpacity(255);
      _uiLayer[1]->getChildByName("boneCatapult버튼기본")->setVisible(true);
      _labelLayer[1]->getChildByName("boneCatapult")->setVisible(true);
      _trapLayer[0]->getChildByName("boneCatapult")->setVisible(true);
      _bgLayer[0]->setVisible(false);
      _uiLayer[0]->getChildByName("continue버튼기본")->setVisible(false);
      _uiLayer[0]->getChildByName("continue버튼오버")->setVisible(false);
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
      _labelLayer[0]->setVisible(false);
      _bgLayer[1]->getChildByName("borderScreen")->setVisible(false);      
    } else {
      _uiLayer[0]->getChildByName("continue버튼클릭")->setVisible(false);
    }

  } else {
    clickBoneCatapult = _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->
      getBoundingBox().containsPoint(touchPoint);
    clickTmp = _uiLayer[1]->getChildByName("tmp")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickBoneCatapult) {
      _isTrap = true;
      _uiLayer[1]->getChildByName("tmp")->setVisible(true);
      _uiLayer[1]->getChildByName("confirm버튼기본")->setVisible(true);      
      _labelLayer[1]->getChildByName("confirm")->setVisible(true);
      _trapLayer[0]->getChildByName("boneCatapultClone")->setVisible(true);
      _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
    } else if (clickTmp) {
      _isTrap = false;
      _uiLayer[1]->getChildByName("tmp")->setVisible(false);
      _uiLayer[1]->getChildByName("confirm버튼기본")->setVisible(false);
      _uiLayer[1]->getChildByName("confirm버튼오버")->setVisible(false);
      _uiLayer[1]->getChildByName("confirm버튼클릭")->setVisible(false);
      _labelLayer[1]->getChildByName("confirm")->setVisible(false);
      _trapLayer[0]->getChildByName("boneCatapultClone")->setVisible(false);
    } else if (_isTrap) {

    } else {
      _uiLayer[1]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
    }
  }

}

void Tutorial::onMouseMove(Event * event) {
  EventMouse* mousePosition = (EventMouse*)event;

  bool overContinue = false, overOption = false, overBoneCatapult = false,
    overConfirm = false;

  overOption = _uiLayer[0]->getChildByName("option버튼기본")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  if (overOption) {
    _uiLayer[0]->getChildByName("option버튼오버")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("option버튼오버")->setVisible(false);
  }

  if (_isContinue < 2) {
    overContinue = _uiLayer[0]->getChildByName("continue버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    if (overContinue) {
      _uiLayer[0]->getChildByName("continue버튼오버")->setVisible(true);
    }  else {
      _uiLayer[0]->getChildByName("continue버튼오버")->setVisible(false);
    }

  } else {
    overBoneCatapult = _uiLayer[1]->getChildByName("boneCatapult버튼기본")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    if (overBoneCatapult) {
      _uiLayer[1]->getChildByName("boneCatapult버튼오버")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("boneCatapult버튼오버")->setVisible(false);
    }
  }
}
