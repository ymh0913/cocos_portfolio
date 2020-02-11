#include "Intro.h"

Intro::Intro(Scene * pScene) {
  // ���̾� ����
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) {
    _bgLayer[i] = Layer::create();
  }

  // ������� �ʱ�ȭ
  _isSelect = 0;
  _isOverTop = false;
  _isOverMiddle = false;
  _isOverBottom = false;

  // ��� Ŭ����
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer[0]->addChild(_introBg->getKeyArtBackground(), 0, "��Ʈ�ι��");
  _bgLayer[0]->addChild(_introBg->getLegendOfKeepersLogo(), 0, "��Ʈ�ηΰ�");
  pScene->addChild(_bgLayer[0]);

  _bgLayer[1]->addChild(_introBg->getSaveBorderBackground(), 0, "��������");
  pScene->addChild(_bgLayer[1]);
  _bgLayer[1]->setVisible(false);

  // UI Ŭ����
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

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top���Ա⺻");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle���Ա⺻");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom���Ա⺻");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back��ư�⺻");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete��ư�⺻");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm��ư�⺻");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top���Կ���");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle���Կ���");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom���Կ���");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back��ư����");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete��ư����");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm��ư����");
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Confirm��ư����")->setVisible(false);
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back��ưŬ��");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete��ưŬ��");
      _uiLayer[1]->addChild(_introUI->getBtnConfirm(i), 0, "Confirm��ưŬ��");
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Confirm��ưŬ��")->setVisible(false);
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

  _labelLayer[1]->addChild(_introLabel->getBack(), 0, "Back���̺�");
  _labelLayer[1]->addChild(_introLabel->getDelete(), 0, "Delete���̺�");
  _labelLayer[1]->addChild(_introLabel->getConfirm(), 0, "Confirm���̺�");
  pScene->addChild(_labelLayer[1]);
  _labelLayer[1]->setVisible(false);

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
  bool touchBack = _uiLayer[1]->getChildByName("Back��ư����")->
    getBoundingBox().containsPoint(touchPoint);

  if (touchPlay) {
    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(true);
  } else if (touchBack) {
    _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
  }

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool clickPlay = _uiLayer[0]->getChildByName("Play��ưŬ��")->
    getBoundingBox().containsPoint(touchPoint);
  bool clickBack = _uiLayer[1]->getChildByName("Back��ưŬ��")->
    getBoundingBox().containsPoint(touchPoint);

  if (clickPlay) {
    _isSelect = _introUI->kSelectBtn_Play;
    _bgLayer[1]->setVisible(true);
    _uiLayer[1]->setVisible(true);
    _labelLayer[1]->setVisible(true);
    _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(95);
    _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(false);
    _uiLayer[0]->setVisible(false);
    _labelLayer[0]->setVisible(false);
  } else if (clickBack) {
    _isSelect = _introUI->kSelectBtn_False;
    _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(255);
    _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(true);
    _uiLayer[0]->setVisible(true);
    _labelLayer[0]->setVisible(true);
    _bgLayer[1]->setVisible(false);
    _uiLayer[1]->setVisible(false);
    _labelLayer[1]->setVisible(false);
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
  bool overBack = _uiLayer[1]->getChildByName("Back��ư�⺻")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  if (overPlay) {
    _uiLayer[0]->getChildByName("Play��ư����")->setVisible(true);
  } else if (overBack) {
    _uiLayer[1]->getChildByName("Back��ư����")->setVisible(true);
  } else {
    _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
    _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
  }
}