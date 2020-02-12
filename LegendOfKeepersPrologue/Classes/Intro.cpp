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
  _isTop = false;
  _isMiddle = false;
  _isBottom = false;

  // ��� Ŭ����
  _introBg = new (std::nothrow) IntroBg;
  _bgLayer[0]->addChild(_introBg->getKeyArtBackground(), 0, "��Ʈ�ι��");
  _bgLayer[0]->addChild(_introBg->getLegendOfKeepersLogo(), 0, "��Ʈ�ηΰ�");
  pScene->addChild(_bgLayer[0]);

  _bgLayer[1]->addChild(_introBg->getSaveBorderBackground(), 0, "��������");
  _bgLayer[1]->setVisible(false);
  pScene->addChild(_bgLayer[1]);

  _bgLayer[2]->addChild(_introBg->getTutorialBorderBackground(), 0, "Ʃ�丮������");
  _bgLayer[2]->setVisible(false);
  pScene->addChild(_bgLayer[2]);

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
      _uiLayer[0]->addChild(_introUI->getIconFacebook(i), 0, "Facebook�����ܱ⺻");
    } else {
      _uiLayer[0]->addChild(_introUI->getIconDiscord(i), 0, "Discord�����ܿ���");
      _uiLayer[0]->addChild(_introUI->getIconReddit(i), 0, "Reddit�����ܿ���");
      _uiLayer[0]->addChild(_introUI->getIconTwitter(i), 0, "Twitter�����ܿ���");
      _uiLayer[0]->addChild(_introUI->getIconFacebook(i), 0, "Facebook�����ܿ���");
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook�����ܿ���")->setVisible(false);
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
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create��ư�⺻");
    } else if (i == 1) {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top���Կ���");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle���Կ���");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom���Կ���");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back��ư����");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete��ư����");
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create��ư����");
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ư����")->setVisible(false);
    } else {
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveTop(i), 0, "Top����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveMiddle(i), 0, "Middle����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getSaveBorderNewsaveBottom(i), 0, "Bottom����Ŭ��");
      _uiLayer[1]->addChild(_introUI->getBtnBack(i), 0, "Back��ưŬ��");
      _uiLayer[1]->addChild(_introUI->getBtnDelete(i), 0, "Delete��ưŬ��");
      _uiLayer[1]->addChild(_introUI->getBtnCreate(i), 0, "Create��ưŬ��");
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
    }
  }
  _uiLayer[1]->setVisible(false);
  pScene->addChild(_uiLayer[1]);

  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No��ư�⺻");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes��ư�⺻");
    } else if (i == 1) {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No��ư����");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes��ư����");
      _uiLayer[2]->getChildByName("No��ư����")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes��ư����")->setVisible(false);
    } else {
      _uiLayer[2]->addChild(_introUI->getBtnNo(i), 0, "No��ưŬ��");
      _uiLayer[2]->addChild(_introUI->getBtnYes(i), 0, "Yes��ưŬ��");
      _uiLayer[2]->getChildByName("No��ưŬ��")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes��ưŬ��")->setVisible(false);
    }
  }
  _uiLayer[2]->setVisible(false);
  pScene->addChild(_uiLayer[2]);

  // Label Ŭ����
  _introLabel = new (std::nothrow) IntroLabel;
  _labelLayer[0]->addChild(_introLabel->getPlay(), 0, "Play���̺�");
  _labelLayer[0]->addChild(_introLabel->getSettings(), 0, "Settings���̺�");
  _labelLayer[0]->addChild(_introLabel->getModding(), 0, "Modding���̺�");
  _labelLayer[0]->addChild(_introLabel->getCredits(), 0, "Credtis���̺�");
  _labelLayer[0]->addChild(_introLabel->getQuit(), 0, "Quit���̺�");
  _labelLayer[0]->addChild(_introLabel->getV0602(), 0, "v0.6.0.2���̺�");  
  pScene->addChild(_labelLayer[0]);

  _labelLayer[1]->addChild(_introLabel->getTitleSaveTop(), 0, "TitleSaveTop���̺�");
  _labelLayer[1]->addChild(_introLabel->getTitleSaveMiddle(), 0, "TitleSaveMiddle���̺�");
  _labelLayer[1]->addChild(_introLabel->getTitleSaveBottom(), 0, "TitleSaveBottom���̺�");
  _labelLayer[1]->addChild(_introLabel->getBack(), 0, "Back���̺�");
  _labelLayer[1]->addChild(_introLabel->getDelete(), 0, "Delete���̺�");
  _labelLayer[1]->addChild(_introLabel->getCreate(), 0, "Create���̺�");
  _labelLayer[1]->setVisible(false);
  pScene->addChild(_labelLayer[1]);

  _labelLayer[2]->addChild(_introLabel->getTutorial(), 0, "tutorial?���̺�");
  _labelLayer[2]->addChild(_introLabel->getNo(), 0, "No���̺�");
  _labelLayer[2]->addChild(_introLabel->getYes(), 0, "Yes���̺�");
  _labelLayer[2]->setVisible(false);
  pScene->addChild(_labelLayer[2]);


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

  bool touchPlay = false, touchSettings = false, touchModding = false,
    touchCredits = false, touchQuit = false;
  bool touchTop = false, touchMiddle = false, touchBottom = false, touchBack,
    touchDelete = false, touchCreate = false;

  if (_isSelect == _introUI->kSelectBtn_False) {
    touchPlay = _uiLayer[0]->getChildByName("Play��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchSettings = _uiLayer[0]->getChildByName("Settings��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchModding = _uiLayer[0]->getChildByName("Modding��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchCredits = _uiLayer[0]->getChildByName("Credits��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchQuit = _uiLayer[0]->getChildByName("Quit��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchPlay) {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(true);
    } else if (touchSettings) {
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(true);
    } else if (touchModding) {
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(true);
    } else if (touchCredits) {
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(true);
    } else if (touchQuit) {
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    touchTop = _uiLayer[1]->getChildByName("Top���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchMiddle = _uiLayer[1]->getChildByName("Middle���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchBottom = _uiLayer[1]->getChildByName("Bottom���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchBack = _uiLayer[1]->getChildByName("Back��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchDelete = _uiLayer[1]->getChildByName("Delete��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchCreate = _uiLayer[1]->getChildByName("Create��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    if (touchTop) {
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
    } else if (touchMiddle) {
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
    } else if (touchBottom) {
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
    } else if (touchBack) {
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(true);
    } else if (touchDelete) {
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(true);
    } else if (touchCreate && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
    }
  }

  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (touchPlay) {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(true);
    } else if (touchSettings) {
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(true);
    } else if (touchModding) {
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(true);
    } else if (touchCredits) {
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(true);
    } else if (touchQuit) {
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    }
  }*/
  
  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    touchTop = _uiLayer[1]->getChildByName("Top���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchMiddle = _uiLayer[1]->getChildByName("Middle���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchBottom = _uiLayer[1]->getChildByName("Bottom���Կ���")->
      getBoundingBox().containsPoint(touchPoint);
    touchBack = _uiLayer[1]->getChildByName("Back��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchDelete = _uiLayer[1]->getChildByName("Delete��ư����")->
      getBoundingBox().containsPoint(touchPoint);
    touchCreate = _uiLayer[1]->getChildByName("Create��ư����")->
      getBoundingBox().containsPoint(touchPoint);
  }*/

  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    if (touchTop) {
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
    } else if (touchMiddle) {
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
    } else if (touchBottom) {
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(true);
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
    } else if (touchBack) {
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(true);
    } else if (touchDelete) {
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(true);
    } else if (touchCreate && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom����Ŭ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
    }
  }*/

  return true;
}

void Intro::onTouchEnded(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  // ��Ʈ�ξ����� ���콺 Ŭ���� ���� ����
  bool clickPlay = false, clickSettings = false, clickModding = false,
    clickCredits = false, clickQuit = false;
  // Play��ư�� ���� �� ���콺 Ŭ���� ���� ����
  bool clickTop = false, clickMiddle = false, clickBottom = false,
    clickBack = false, clickDelete = false, clickCreate = false;
  // Create��ư�� ���� �� ���콺 Ŭ���� ���� ����
  bool clickNo = false, clickYes = false;
  
  if (_isSelect == _introUI->kSelectBtn_False) {
    clickPlay = _uiLayer[0]->getChildByName("Play��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickSettings = _uiLayer[0]->getChildByName("Settings��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickModding = _uiLayer[0]->getChildByName("Modding��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickCredits = _uiLayer[0]->getChildByName("Credits��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickQuit = _uiLayer[0]->getChildByName("Quit��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    if (clickPlay) {
      _isSelect = _introUI->kSelectBtn_Play;
      _bgLayer[1]->setVisible(true);
      _uiLayer[1]->setVisible(true);
      _labelLayer[1]->setVisible(true);
      _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(95);
      _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(false);
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->setVisible(false);
      _labelLayer[0]->setVisible(false);
    } else if (clickSettings) {
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
    } else if (clickModding) {
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
    } else if (clickCredits) {
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
    } else if (clickQuit) {
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    } else {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    clickTop = _uiLayer[1]->getChildByName("Top����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickMiddle = _uiLayer[1]->getChildByName("Middle����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickBottom = _uiLayer[1]->getChildByName("Bottom����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickBack = _uiLayer[1]->getChildByName("Back��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickDelete = _uiLayer[1]->getChildByName("Delete��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickCreate = _uiLayer[1]->getChildByName("Create��ưŬ��")->
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
      _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(255);
      _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(true);
      _uiLayer[0]->setVisible(true);
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _labelLayer[0]->setVisible(true);
      _bgLayer[1]->setVisible(false);
      _uiLayer[1]->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _labelLayer[1]->setVisible(false);
    } else if (clickDelete/* ���̺������� ��������� Ȱ��ȭ�� ��*/) {

    } else if (clickCreate && (_isTop || _isMiddle || _isBottom)) {
      _isSelect = _introUI->kSelectBtn_Create;
      _bgLayer[2]->setVisible(true);
      _uiLayer[2]->setVisible(true);
      _labelLayer[2]->setVisible(true);
      _bgLayer[1]->setVisible(false);
      _uiLayer[1]->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
      _labelLayer[1]->setVisible(false);
    } else {
      _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Create) {
    clickNo = _uiLayer[2]->getChildByName("No��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickYes = _uiLayer[2]->getChildByName("Yes��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    if (_isSelect == _introUI->kSelectBtn_Create) {
      if (clickNo) {
        _uiLayer[2]->getChildByName("No��ưŬ��")->setVisible(true);
      } else if (clickYes) {
        _uiLayer[2]->getChildByName("Yes��ưŬ��")->setVisible(true);
        auto pScene = TutorialScene::createScene();
        DIRECTOR->replaceScene(pScene);
      } else {
        _uiLayer[2]->getChildByName("No��ưŬ��")->setVisible(false);
        _uiLayer[2]->getChildByName("Yes��ưŬ��")->setVisible(false);
      }
    }
  }

  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (clickPlay) {
      _isSelect = _introUI->kSelectBtn_Play;
      _bgLayer[1]->setVisible(true);
      _uiLayer[1]->setVisible(true);
      _labelLayer[1]->setVisible(true);
      _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(95);
      _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(false);
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->setVisible(false);
      _labelLayer[0]->setVisible(false);
    } else if (clickSettings) {
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
    } else if (clickModding) {
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
    } else if (clickCredits) {
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
    } else if (clickQuit) {
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    } else {
      _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ưŬ��")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ưŬ��")->setVisible(false);
    }
  }*/

  /*bool clickTop = false, clickMiddle = false, clickBottom = false,
    clickBack = false, clickDelete = false, clickCreate = false;
  if (_isSelect == _introUI->kSelectBtn_Play) {
    clickTop = _uiLayer[1]->getChildByName("Top����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickMiddle = _uiLayer[1]->getChildByName("Middle����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickBottom = _uiLayer[1]->getChildByName("Bottom����Ŭ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickBack = _uiLayer[1]->getChildByName("Back��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickDelete = _uiLayer[1]->getChildByName("Delete��ưŬ��")->
      getBoundingBox().containsPoint(touchPoint);
    clickCreate = _uiLayer[1]->getChildByName("Create��ưŬ��")->
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
  //    _bgLayer[0]->getChildByName("��Ʈ�ι��")->setOpacity(255);
  //    _bgLayer[0]->getChildByName("��Ʈ�ηΰ�")->setVisible(true);
  //    _uiLayer[0]->setVisible(true);
  //    _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
  //    _uiLayer[0]->getChildByName("Play��ưŬ��")->setVisible(false);
  //    _labelLayer[0]->setVisible(true);      
  //    _bgLayer[1]->setVisible(false);
  //    _uiLayer[1]->setVisible(false);
  //    _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
  //    _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
  //    _labelLayer[1]->setVisible(false);
  //  } else if (clickDelete/* ���̺������� ��������� Ȱ��ȭ�� ��*/) {

  //  } else if (clickCreate && (_isTop || _isMiddle || _isBottom)) {
  //    _isSelect = _introUI->kSelectBtn_Create;
  //    _bgLayer[2]->setVisible(true);
  //    _uiLayer[2]->setVisible(true);
  //    _labelLayer[2]->setVisible(true);
  //    _bgLayer[1]->setVisible(false);
  //    _uiLayer[1]->setVisible(false);
  //    _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
  //    _labelLayer[1]->setVisible(false);
  //  } else {
  //    _uiLayer[1]->getChildByName("Back��ưŬ��")->setVisible(false);
  //    _uiLayer[1]->getChildByName("Create��ưŬ��")->setVisible(false);
  //  }
  //}

  /*bool clickNo = _uiLayer[2]->getChildByName("No��ưŬ��")->
    getBoundingBox().containsPoint(touchPoint);
  bool clickYes = _uiLayer[2]->getChildByName("Yes��ưŬ��")->
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
  // ���콺 ��ġ�� ���� ����
  EventMouse* mousePosition = (EventMouse*)event;

  // ��Ʈ�ξ����� ���콺�� ��ư ���� �ִ��� �Ǵ��� ����
  bool overPlay = false, overSettings = false, overModding = false,
    overCredits = false, overQuit = false, overDiscord = false,
    overReddit = false, overTwitter = false, overFacebook = false;
  // Play��ư�� ���� �� ���콺�� ��ư ���� �ִ��� �Ǵ��� ����
  bool overTop = false, overMiddle = false, overBottom = false,
    overBack = false, overDelete = false, overCreate = false;
  // Create��ư�� ���� �� ���콺�� ��ư ���� �ִ��� �Ǵ��� ����
  bool overNo = false, overYes = false;

  if (_isSelect == _introUI->kSelectBtn_False) {
    overPlay = _uiLayer[0]->getChildByName("Play��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overSettings = _uiLayer[0]->getChildByName("Settings��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overModding = _uiLayer[0]->getChildByName("Modding��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCredits = _uiLayer[0]->getChildByName("Credits��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overQuit = _uiLayer[0]->getChildByName("Quit��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDiscord = _uiLayer[0]->getChildByName("Discord�����ܱ⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overReddit = _uiLayer[0]->getChildByName("Reddit�����ܱ⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overTwitter = _uiLayer[0]->getChildByName("Twitter�����ܱ⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overFacebook = _uiLayer[0]->getChildByName("Facebook�����ܱ⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // ��Ʈ�ξ����� ���콺�� ��ư ���� ���� �� ������ ���ǹ�
    if (overPlay) {
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(true);
    } else if (overSettings) {
      _uiLayer[0]->getChildByName("Settings��ư����")->setVisible(true);
    } else if (overModding) {
      _uiLayer[0]->getChildByName("Modding��ư����")->setVisible(true);
    } else if (overCredits) {
      _uiLayer[0]->getChildByName("Credits��ư����")->setVisible(true);
    } else if (overQuit) {
      _uiLayer[0]->getChildByName("Quit��ư����")->setVisible(true);
    } else if (overDiscord) {
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(true);
    } else if (overReddit) {
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(true);
    } else if (overTwitter) {
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(true);
    } else if (overFacebook) {
      _uiLayer[0]->getChildByName("Facebook�����ܿ���")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook�����ܿ���")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Play) {
    overTop = _uiLayer[1]->getChildByName("Top���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overMiddle = _uiLayer[1]->getChildByName("Middle���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBottom = _uiLayer[1]->getChildByName("Bottom���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBack = _uiLayer[1]->getChildByName("Back��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDelete = _uiLayer[1]->getChildByName("Delete��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCreate = _uiLayer[1]->getChildByName("Create��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // Play��ư�� ���� �� ���콺�� ��ư���� ���� �� ������ ���ǹ�
    if (overTop) {
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(true);
    } else if (overMiddle) {
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(true);
    } else if (overBottom) {
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(true);
    } else if (overBack) {
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(true);
    } else if (overDelete && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(true);
    } else if (overCreate) {
      _uiLayer[1]->getChildByName("Create��ư����")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ư����")->setVisible(false);
    }

  } else if (_isSelect == _introUI->kSelectBtn_Create) {
    overNo = _uiLayer[2]->getChildByName("No��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overYes = _uiLayer[2]->getChildByName("Yes��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    // Create��ư�� ���� �� ���콺�� ��ư���� ���� �� ������ ���ǹ�
    if (overNo) {
      _uiLayer[2]->getChildByName("No��ư����")->setVisible(true);
    } else if (overYes) {
      _uiLayer[2]->getChildByName("Yes��ư����")->setVisible(true);
    } else {
      _uiLayer[2]->getChildByName("No��ư����")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes��ư����")->setVisible(false);
    }
  }

  // ��Ʈ�ξ����� ���콺�� ��ư ���� ���� �� ������ ���ǹ�
  /*if (_isSelect == _introUI->kSelectBtn_False) {
    if (overPlay) {
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(true);
    } else if (overSettings) {
      _uiLayer[0]->getChildByName("Settings��ư����")->setVisible(true);
    } else if (overModding) {
      _uiLayer[0]->getChildByName("Modding��ư����")->setVisible(true);
    } else if (overCredits) {
      _uiLayer[0]->getChildByName("Credits��ư����")->setVisible(true);
    } else if (overQuit) {
      _uiLayer[0]->getChildByName("Quit��ư����")->setVisible(true);
    } else if (overDiscord) {
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(true);
    } else if (overReddit) {
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(true);
    } else if (overTwitter) {
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(true);
    } else if (overFacebook) {
      _uiLayer[0]->getChildByName("Facebook�����ܿ���")->setVisible(true);
    } else {
      _uiLayer[0]->getChildByName("Play��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Settings��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Modding��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Credits��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Quit��ư����")->setVisible(false);
      _uiLayer[0]->getChildByName("Discord�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Reddit�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Twitter�����ܿ���")->setVisible(false);
      _uiLayer[0]->getChildByName("Facebook�����ܿ���")->setVisible(false);
    }
  }*/

  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    overTop = _uiLayer[1]->getChildByName("Top���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overMiddle = _uiLayer[1]->getChildByName("Middle���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBottom = _uiLayer[1]->getChildByName("Bottom���Ա⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overBack = _uiLayer[1]->getChildByName("Back��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overDelete = _uiLayer[1]->getChildByName("Delete��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
    overCreate = _uiLayer[1]->getChildByName("Create��ư�⺻")->
      getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                          mousePosition->getCursorY()));
  }*/

  // Play��ư�� ���� �� ���콺�� ��ư���� ���� �� ������ ���ǹ�
  /*if (_isSelect == _introUI->kSelectBtn_Play) {
    if (overTop) {
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(true);
    } else if (overMiddle) {
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(true);
    } else if (overBottom) {
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(true);
    } else if (overBack) {
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(true);
    } else if (overDelete && (_isTop || _isMiddle || _isBottom)) {
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(true);
    } else if (overCreate) {
      _uiLayer[1]->getChildByName("Create��ư����")->setVisible(true);
    } else {
      _uiLayer[1]->getChildByName("Top���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Middle���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Bottom���Կ���")->setVisible(false);
      _uiLayer[1]->getChildByName("Back��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Delete��ư����")->setVisible(false);
      _uiLayer[1]->getChildByName("Create��ư����")->setVisible(false);
    }
  }*/

  /*bool overNo = _uiLayer[2]->getChildByName("No��ư�⺻")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));
  bool overYes = _uiLayer[2]->getChildByName("Yes��ư�⺻")->
    getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(),
                                        mousePosition->getCursorY()));

  if (_isSelect == _introUI->kSelectBtn_Create) {
    if (overNo) {
      _uiLayer[2]->getChildByName("No��ư����")->setVisible(true);
    } else if (overYes) {
      _uiLayer[2]->getChildByName("Yes��ư����")->setVisible(true);
    } else {
      _uiLayer[2]->getChildByName("No��ư����")->setVisible(false);
      _uiLayer[2]->getChildByName("Yes��ư����")->setVisible(false);
    }
  }*/
}