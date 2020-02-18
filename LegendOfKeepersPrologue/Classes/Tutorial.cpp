#include "Tutorial.h"

Tutorial::Tutorial(Scene * pScene) {
  _scene = pScene;

  // ������� �ʱ�ȭ
  _room = kRoomName_Trap;
  _continue = 0;
  _isTrap = false;

  // ���̾� ����
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) { 
    _bgLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }

  // �����Ҵ�
  _tutorialBg = new (nothrow) TutorialBg;
  _tutorialUI = new (nothrow) TutorialUI;
  _tutorialLabel = new (nothrow) TutorialLabel;
  _tutorialHero = new (nothrow) TutorialHero;
  _tutorialTrap = new (nothrow) TutorialTrap;
  

  // ���� UI
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option��ư�⺻");
    } else if (i == 1) {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option��ư����");
      _scene->getChildByName("option��ư����")->setVisible(false);
    } else {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option��ưŬ��");
      _scene->getChildByName("option��ưŬ��")->setVisible(false);
    }
  }
  _scene->addChild(_tutorialUI->getRoomIconTraps(), 1, "roomIconTraps");
  _scene->addChild(_tutorialUI->getRoomIconSpell(), 1, "roomIconSpell");
  _scene->addChild(_tutorialUI->getRoomIconMonster3(), 1, "roomIconMoster3");
  _scene->addChild(_tutorialUI->getRoomIconBoss(), 1, "roomIconBoss");
  
  // DRH
  _bgLayerDRH = Layer::create();
  _uiLayerDRH = Layer::create();
  _labelLayerDRH = Layer::create();
  _bgLayerDRH->addChild(_tutorialBg->getDRH(), 0, "DRH");
  _bgLayerDRH->addChild(_tutorialBg->getDRHSpeak(), 0, "DRH��");
  _bgLayerDRH->getChildByName("DRH��")->runAction(_tutorialBg->getDRHSpeakAction());
  _bgLayerDRH->addChild(_tutorialBg->getDRHSpeakEye(), 0, "DRH��");
  _bgLayerDRH->getChildByName("DRH��")->runAction(_tutorialBg->getDRHSpeakEyeAction());
  _bgLayerDRH->addChild(_tutorialBg->getBorderScreen(), 0, "borderScreen");
  _scene->addChild(_bgLayerDRH, 2);
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue��ư�⺻");
    } else if (i == 1) {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue��ư����");
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
    } else {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue��ưŬ��");
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
    }    
  }
  _scene->addChild(_uiLayerDRH, 2);
  _labelLayerDRH->addChild(_tutorialLabel->getContinue(), 0, "continue");
  _labelLayerDRH->addChild(_tutorialLabel->getCongratulations(), 0, "congratulations");
  _labelLayerDRH->addChild(_tutorialLabel->getHeroes(), 0, "heroes");
  _labelLayerDRH->getChildByName("heroes")->setVisible(false);
  _scene->addChild(_labelLayerDRH, 2);
  
  // ��� ������ ����
  srand(time(NULL));
  for (byte i = 0; i < 4; i++) {
    _checkBg[i] = rand() % 5;
  }
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 4; j++) {
      if (i == j) {
        continue;
      }
      while (_checkBg[i] == _checkBg[j]) {
        _checkBg[j] = rand() % 5;
      }
    }
  }

  /* RoomName_Trap */
  // ���
  _bgLayer[kRoomName_Trap]->addChild(_tutorialBg->getBgDungeonRoom(_checkBg[kRoomName_Trap]), 0, "Ʃ�丮����");
  _bgLayer[kRoomName_Trap]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Trap), 0, "Ʃ�丮�󶥹��");
  _scene->addChild(_bgLayer[kRoomName_Trap]);
  // UI
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult��ư�⺻");
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getConfirm(i), 0, "confirm��ư�⺻");
      _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư�⺻")->setVisible(false);
    } else if (i == 1) {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult��ư����");
      _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư����")->setVisible(false);
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getConfirm(i), 0, "confirm��ư����");
      _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư����")->setVisible(false);
    } else {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult��ưŬ��");
      _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->setVisible(false);
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getConfirm(i), 0, "confirm��ưŬ��");
      _uiLayer[kRoomName_Trap]->getChildByName("confirm��ưŬ��")->setVisible(false);
    }
  }
  _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getRemove(), 0, "remove");
  _uiLayer[kRoomName_Trap]->getChildByName("remove")->setVisible(false);
  _uiLayer[kRoomName_Trap]->setVisible(false);
  _scene->addChild(_uiLayer[kRoomName_Trap], 1);
  // Label
  _labelLayer[kRoomName_Trap]->addChild(_tutorialLabel->getPlaceATrap(), 0, "placeATrap");
  _labelLayer[kRoomName_Trap]->addChild(_tutorialLabel->getBoneCatapult(), 0, "boneCatapult");
  _labelLayer[kRoomName_Trap]->addChild(_tutorialLabel->getConfirm(), 0, "confirm");
  _labelLayer[kRoomName_Trap]->getChildByName("confirm")->setVisible(false);  
  _labelLayer[kRoomName_Trap]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Trap], 1);
  // �����
  _heroLayer = Layer::create();
  _heroLayer->addChild(_tutorialHero->getScout(), 0, "scoutIdle");
  _heroLayer->getChildByName("scoutIdle")->runAction(
    _tutorialHero->getScoutIdleAction());
  _heroLayer->addChild(_tutorialHero->getScum(), 0, "scumIdle");
  _heroLayer->getChildByName("scumIdle")->runAction(
    _tutorialHero->getScumIdleAction());
  _heroLayer->addChild(_tutorialHero->getBarbarian(), 0, "barbarianIdle");
  _heroLayer->getChildByName("barbarianIdle")->runAction(
    _tutorialHero->getBarbarianIdleAction());
  _heroLayer->setOpacity(7);
  _scene->addChild(_heroLayer, 1);
  // Ʈ��
  _trapLayer = Layer::create();  
  _trapLayer->addChild(_tutorialTrap->getBoneCatapult(), 0, "boneCatapult");
  _trapLayer->addChild(_tutorialTrap->getBoneCatapultClone(), 0, "boneCatapultClone");
  _trapLayer->getChildByName("boneCatapultClone")->setVisible(false);
  _trapLayer->setVisible(false);
  _scene->addChild(_trapLayer);

  /* RoomName_Spell */
  // ���
  _bgLayer[kRoomName_Spell]->addChild(_tutorialBg->getBgDungeonRoom(_checkBg[kRoomName_Spell]), 0, "Ʃ�丮����");
  _bgLayer[kRoomName_Spell]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Spell), 0, "Ʃ�丮�󶥹��");
  _bgLayer[kRoomName_Spell]->setVisible(false);
  _scene->addChild(_bgLayer[kRoomName_Spell]);
  // Label
  _labelLayer[kRoomName_Spell]->addChild(_tutorialLabel->getWe(), 0, "we");  
  _labelLayer[kRoomName_Spell]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Spell], 2);

  /* RoomName_Monster */
  // ���
  _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getBgDungeonRoom(_checkBg[kRoomName_Monster]), 0, "Ʃ�丮����");
  _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Monster), 0, "Ʃ�丮�󶥹��");
  _bgLayer[kRoomName_Monster]->setVisible(false);
  _scene->addChild(_bgLayer[kRoomName_Monster]);
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getSome(), 0, "some");
  _labelLayer[kRoomName_Monster]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Monster], 2);

  // ��ġ �̺�Ʈ ���
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Tutorial::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Tutorial::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, _scene);

  // ���콺 �̺�Ʈ ���
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Tutorial::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, _scene);
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

  bool touchOption = _scene->getChildByName("option��ư����")->
    getBoundingBox().containsPoint(touchPoint);
  if (touchOption) {
    _scene->getChildByName("option��ưŬ��")->setVisible(true);
  } else {
    _scene->getChildByName("option��ưŬ��")->setVisible(false);
  }
  
  if (_room == kRoomName_Trap) {
    if (_continue < 2) {
      bool touchContinue = _uiLayerDRH->getChildByName("continue��ư����")->getBoundingBox().containsPoint(touchPoint);
      if (touchContinue) {
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(true);
      } else {
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
      }
    } else {
      bool touchBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư����")->getBoundingBox().containsPoint(touchPoint);
      if (touchBoneCatapult) {
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->setVisible(true);
      } else {
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->setVisible(false);
      }

      if (_isTrap) {
        bool touchConfirm = _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư����")->getBoundingBox().containsPoint(touchPoint);
        if (touchConfirm) {
          _uiLayer[kRoomName_Trap]->getChildByName("confirm��ưŬ��")->setVisible(true);
        } else {
          _uiLayer[kRoomName_Trap]->getChildByName("confirm��ưŬ��")->setVisible(false);
        }
      }
    }

  } else if (_room == kRoomName_Spell) {
    bool touchContinue = _uiLayerDRH->getChildByName("continue��ư����")->getBoundingBox().containsPoint(touchPoint);
    if (touchContinue) {
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(true);
    } else {
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
    }

  } else if (_room == kRoomName_Monster) {
    bool touchContinue = _uiLayerDRH->getChildByName("continue��ư����")->getBoundingBox().containsPoint(touchPoint);
    if (touchContinue) {
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(true);
    } else {
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
    }
  }

  return true;
}

void Tutorial::onTouchEnded(Touch * touch, Event * event) {
  auto clickPoint = touch->getLocation();

  bool clickOption = _scene->getChildByName("option��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
  if (clickOption) {
  } else {
  }

  if (_room == kRoomName_Trap) {
    if (_continue == 0) {
      bool clickContinue = _uiLayerDRH->getChildByName("continue��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
      if (clickContinue) {
        _continue++;
        _labelLayerDRH->getChildByName("heroes")->setVisible(true);
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
        _labelLayerDRH->getChildByName("congratulations")->setVisible(false);
      } else {
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
      }
    } else if (_continue == 1) {
      bool clickContinue = _uiLayerDRH->getChildByName("continue��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
      if (clickContinue) {
        _continue++;
        _uiLayer[kRoomName_Trap]->setVisible(true);
        _labelLayer[kRoomName_Trap]->setVisible(true);
        _heroLayer->setOpacity(255);
        _trapLayer->setVisible(true);
        _bgLayerDRH->setVisible(false);
        _uiLayerDRH->setVisible(false);
        _labelLayerDRH->setVisible(false);
        _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
        _labelLayerDRH->getChildByName("heroes")->setVisible(false);
      } else {
        _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
      }
    } else {
      bool clickBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
      bool clickRemove = _uiLayer[kRoomName_Trap]->getChildByName("remove")->getBoundingBox().containsPoint(clickPoint);
      if (clickBoneCatapult) {
        _isTrap = true;
        _uiLayer[kRoomName_Trap]->getChildByName("remove")->setVisible(true);
        _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư�⺻")->setVisible(true);
        _labelLayer[kRoomName_Trap]->getChildByName("confirm")->setVisible(true);
        _trapLayer->getChildByName("boneCatapultClone")->setVisible(true);
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư����")->setVisible(false);
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->setVisible(false);

      } else if (clickRemove) {
        _isTrap = false;
        _uiLayer[kRoomName_Trap]->getChildByName("remove")->setVisible(false);
        _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư�⺻")->setVisible(false);
        _labelLayer[kRoomName_Trap]->getChildByName("confirm")->setVisible(false);
        _trapLayer->getChildByName("boneCatapultClone")->setVisible(false);

      } else {
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ưŬ��")->setVisible(false);
      }

      if (_isTrap) {
        bool clickConfirm = _uiLayer[kRoomName_Trap]->getChildByName("confirm��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
        if (clickConfirm) {
          _room = kRoomName_Spell;
          _bgLayer[kRoomName_Spell]->setVisible(true);
          _bgLayerDRH->setVisible(true);
          _uiLayerDRH->setVisible(true);
          _labelLayerDRH->setVisible(true);
          _labelLayer[kRoomName_Spell]->setVisible(true);
          _bgLayer[kRoomName_Trap]->setVisible(false);
          _uiLayer[kRoomName_Trap]->setVisible(false);
          _labelLayer[kRoomName_Trap]->setVisible(false);
          _trapLayer->setVisible(false);
        }
      }
    }

  } else if (_room == kRoomName_Spell) {
    bool clickContinue = _uiLayerDRH->getChildByName("continue��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
    if (clickContinue) {
      _room = kRoomName_Monster;
      _bgLayer[kRoomName_Monster]->setVisible(true);
      _bgLayerDRH->setVisible(true);
      _uiLayerDRH->setVisible(true);
      _labelLayerDRH->setVisible(true);
      _labelLayer[kRoomName_Monster]->setVisible(true);
      _bgLayer[kRoomName_Spell]->setVisible(false);
      _labelLayer[kRoomName_Spell]->setVisible(false);
      _heroLayer->setVisible(false);
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
    } else {
      _uiLayerDRH->getChildByName("continue��ưŬ��")->setVisible(false);
    }

  } else if (_room == kRoomName_Monster) {
    bool clickContinue = _uiLayerDRH->getChildByName("continue��ưŬ��")->getBoundingBox().containsPoint(clickPoint);
    if (clickContinue) {
      
    }
  }
}

void Tutorial::onMouseMove(Event * event) {
  EventMouse* mousePosition = (EventMouse*)event;

  bool overOption = _scene->getChildByName("option��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
  if (overOption) {
    _scene->getChildByName("option��ư����")->setVisible(true);
  } else {
    _scene->getChildByName("option��ư����")->setVisible(false);
  }

  if (_room == kRoomName_Trap) {
    if (_continue < 2) {
      bool overContinue = _uiLayerDRH->getChildByName("continue��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
      if (overContinue) {
        _uiLayerDRH->getChildByName("continue��ư����")->setVisible(true);
      } else {
        _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
      }

    } else {
      bool overBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));      
      if (overBoneCatapult) {
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư����")->setVisible(true);
      } else {
        _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult��ư����")->setVisible(false);
      }

      if (_isTrap) {
        bool overConfirm = _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
        if (overConfirm) {
          _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư����")->setVisible(true);
        } else {
          _uiLayer[kRoomName_Trap]->getChildByName("confirm��ư����")->setVisible(false);
        }
      }
    }

  } else if (_room == kRoomName_Spell) {
    bool overContinue = _uiLayerDRH->getChildByName("continue��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
    if (overContinue) {
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(true);
    } else {
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
    }

  } else if (_room == kRoomName_Monster) {
    bool overContinue = _uiLayerDRH->getChildByName("continue��ư�⺻")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
    if (overContinue) {
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(true);
    } else {
      _uiLayerDRH->getChildByName("continue��ư����")->setVisible(false);
    }
  }
}
