#include "Intro.h"

Intro::Intro(Scene * pScene) {
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }
  _bgLayer = Layer::create();

  // ������� �ʱ�ȭ
  _isSelect = false;
  _isOverTop = false;
  _isOverMiddle = false;
  _isOverBottom = false;

  // ��Ʈ�� ��� Ŭ����
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer->addChild(_introBg->getKeyArtBackground(), 0, _introBg->getKeyArtBackground()->getTag());
  pScene->addChild(_bgLayer);
  
  // ��Ʈ�� UI Ŭ����
  _introUI = new (std::nothrow) IntroUI;

  // ��Ʈ�� ���̺� Ŭ����
  _introLabel = new (std::nothrow) IntroLabel;

  // ��ġ �̺�Ʈ ���
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Intro::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Intro::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener,
                                                           pScene);

  // ���콺 �̺�Ʈ ���
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Intro::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                           pScene);
}

Intro::~Intro() {
  // �����Ҵ� ����
  CC_SAFE_DELETE(_introBg);
  CC_SAFE_DELETE(_introUI);
  CC_SAFE_DELETE(_introLabel);

  // ��� �̺�Ʈ ������ ����
  _eventDispatcher->removeAllEventListeners();
}

bool Intro::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();



  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();
}

void Intro::onMouseMove(Event * event) {
  // ���콺 ��ġ�� ���� ����
  EventMouse* mousePosition = (EventMouse*)event;
}