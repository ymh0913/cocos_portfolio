#include "Tutorial.h"

Tutorial::Tutorial(Scene * pScene) {
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) {
    _bgLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }

  // 배경 클래스
  _tutorialBg = new (std::nothrow) TutorialBg;
  _bgLayer[0]->addChild(_tutorialBg->getBgDungeonRoom(), 0, "튜토리얼배경");
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
  pScene->addChild(_uiLayer[0]);

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
