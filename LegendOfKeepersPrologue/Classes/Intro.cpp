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
  _bgLayer->addChild(_introBg->getKeyArtBackground(), 0, "��Ʈ�ι��");
  _bgLayer->addChild(_introBg->getLegendOfKeepersLogo(), 0, "��Ʈ�ηΰ�");
  pScene->addChild(_bgLayer);
  
  // ��Ʈ�� UI Ŭ����
  _introUI = new (std::nothrow) IntroUI;
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play��ư�⺻");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings��ư�⺻");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding��ư�⺻");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits��ư�⺻");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit��ư�⺻");
    } else if (i == 1) {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play��ư����");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings��ư����");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding��ư����");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits��ư����");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit��ư����");
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ư����")->setVisible(false);
    } else {
      _uiLayer[0]->addChild(_introUI->getBtnPlay(i), 0, "Play��ưŬ��");
      _uiLayer[0]->addChild(_introUI->getBtnSettings(i), 0, "Settings��ưŬ��");
      _uiLayer[0]->addChild(_introUI->getBtnModding(i), 0, "Modding��ưŬ��");
      _uiLayer[0]->addChild(_introUI->getBtnCredits(i), 0, "Credits��ưŬ��");
      _uiLayer[0]->addChild(_introUI->getBtnQuit(i), 0, "Quit��ưŬ��");
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    }
  }
  for (byte i = 0; i < 2; i++) {
    if (i == 0) {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord�����ܱ⺻");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit�����ܱ⺻");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter�����ܱ⺻");
    } else {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord�����ܿ���");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit�����ܿ���");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter�����ܿ���");
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(false);
    }
  }
  pScene->addChild(_uiLayer[0]);

  _uiLayer[1]->addChild(_introUI->getSaveBorderBackground(), 0, "��������");
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top����");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle����");
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom����");
    }
  }
  pScene->addChild(_uiLayer[1]);
  _uiLayer[1]->setVisible(false);

  // ��Ʈ�� ���̺� Ŭ����
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer[0]->addChild(_introLabel->getPlay(), 0, "Play���̺�");
  _labelLayer[0]->addChild(_introLabel->getSettings(), 0, "Settings���̺�");
  _labelLayer[0]->addChild(_introLabel->getModding(), 0, "Modding���̺�");
  _labelLayer[0]->addChild(_introLabel->getCredits(), 0, "Credtis���̺�");
  _labelLayer[0]->addChild(_introLabel->getQuit(), 0, "Quit���̺�");
  _labelLayer[0]->addChild(_introLabel->getV0602(), 0, "v0.6.0.2���̺�");  
  pScene->addChild(_labelLayer[0]);

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

  bool touchPlay = _uiLayer[0]->getChildByName("Play��ư����")->
    getBoundingBox().containsPoint(touchPoint);

  if (touchPlay) {
    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
  }

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool clickPlay = _uiLayer[0]->getChildByName("Play��ưŬ��")->
    getBoundingBox().containsPoint(touchPoint);

  if (clickPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _uiLayer[1]->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
  }
}

void Intro::onMouseMove(Event * event) {
  // ���콺 ��ġ�� ���� ����
  EventMouse* mousePosition = (EventMouse*)event;

  bool overPlay = _uiLayer[0]->getChildByName("Play��ư�⺻")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  if (overPlay) {
    _uiLayer[0]->getChildByName("Play��ư����")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
  }
}