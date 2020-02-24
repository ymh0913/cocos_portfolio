#include "Tutorial.h"

Tutorial::Tutorial(Scene * pScene) {
  _scene = pScene;
  log("_pScene = %d\n", pScene);
  log("_scene = %d\n", _scene);

  // 멤버변수 초기화
  _room = kRoomName_Trap;
  _continue = 0;
  _isTrap = false;
  _isCombat = false;

  // 레이어 생성
  for (byte i = 0; i < sizeof(_bgLayer) / sizeof(Layer*); i++) { 
    _bgLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_uiLayer) / sizeof(Layer*); i++) {
    _uiLayer[i] = Layer::create();
  }
  for (byte i = 0; i < sizeof(_labelLayer) / sizeof(Layer*); i++) {
    _labelLayer[i] = Layer::create();
  }

  // 동적할당
  _tutorialBg = new TutorialBg;
  _tutorialUI = new TutorialUI;
  _tutorialLabel = new TutorialLabel;
  _tutorialHero = new TutorialHero;
  _tutorialTrap = new TutorialTrap;
  _tutorialMonster = new TutorialMonster;
  _tutorialMaster = new TutorialMaster;

  // 공통 UI
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option버튼기본");
      _scene->addChild(_tutorialUI->getConfirm(i), 1, "confirm버튼기본");
      _scene->getChildByName("confirm버튼기본")->setVisible(false);
    } else if (i == 1) {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option버튼오버");
      _scene->getChildByName("option버튼오버")->setVisible(false);
      _scene->addChild(_tutorialUI->getConfirm(i), 1, "confirm버튼오버");
      _scene->getChildByName("confirm버튼오버")->setVisible(false);
    } else {
      _scene->addChild(_tutorialUI->getBtnOptions(i), 1, "option버튼클릭");
      _scene->getChildByName("option버튼클릭")->setVisible(false);
      _scene->addChild(_tutorialUI->getConfirm(i), 1, "confirm버튼클릭");
      _scene->getChildByName("confirm버튼클릭")->setVisible(false);
    }
  }
  _scene->addChild(_tutorialUI->getRoomIconTraps(), 1, "roomIconTraps");
  _scene->addChild(_tutorialUI->getRoomIconSpell(), 1, "roomIconSpell");
  _scene->addChild(_tutorialUI->getRoomIconMonster3(), 1, "roomIconMoster3");
  _scene->addChild(_tutorialUI->getRoomIconBoss(), 1, "roomIconBoss");
  // 공통 Label
  _scene->addChild(_tutorialLabel->getConfirm(), 1, "confirm");
  _scene->getChildByName("confirm")->setVisible(false);

  // DRH
  _bgLayerDRH = Layer::create();
  _uiLayerDRH = Layer::create();
  _labelLayerDRH = Layer::create();
  _bgLayerDRH->addChild(_tutorialBg->getDRH(), 0, "DRH");
  _bgLayerDRH->addChild(_tutorialBg->getDRHSpeak(), 0, "DRH입");
  _bgLayerDRH->getChildByName("DRH입")->runAction(_tutorialBg->getDRHSpeakAction());
  _bgLayerDRH->addChild(_tutorialBg->getDRHSpeakEye(), 0, "DRH눈");
  _bgLayerDRH->getChildByName("DRH눈")->runAction(_tutorialBg->getDRHSpeakEyeAction());
  _bgLayerDRH->addChild(_tutorialBg->getBorderScreen(), 0, "borderScreen");
  _scene->addChild(_bgLayerDRH, 2);
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼기본");
    } else if (i == 1) {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼오버");
      _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(false);
    } else {
      _uiLayerDRH->addChild(_tutorialUI->getBtnContinue(i), 0, "continue버튼클릭");
      _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
    }    
  }
  _scene->addChild(_uiLayerDRH, 2);
  _labelLayerDRH->addChild(_tutorialLabel->getContinue(), 0, "continue");
  _labelLayerDRH->addChild(_tutorialLabel->getCongratulations(), 0, "congratulations");
  _labelLayerDRH->addChild(_tutorialLabel->getHeroes(), 0, "heroes");
  _labelLayerDRH->getChildByName("heroes")->setVisible(false);
  _scene->addChild(_labelLayerDRH, 2);
  
  // 배경 중복없이 무작위 선택
  srand(time(NULL));
  for (byte i = 0; i < 4; i++) {
    _randBg[i] = rand() % 5;
  }
  log("%d %d %d %d\n", _randBg[0], _randBg[1], _randBg[2], _randBg[3]);
  for (byte i = 0; i < 4; i++) {
    for (byte j = 0; j < 4; j++) {
      if (i == j) {
        continue;
      }
      while (_randBg[i] == _randBg[j]) {
        _randBg[j] = rand() % 5;
      }
    }
  }
  log("%d %d %d %d", _randBg[0], _randBg[1], _randBg[2], _randBg[3]);

  /* RoomName_Trap */
  // 배경
  _bgLayer[kRoomName_Trap]->addChild(_tutorialBg->getBgDungeonRoom(_randBg[kRoomName_Trap]), 0, "튜토리얼배경");
  _bgLayer[kRoomName_Trap]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Trap), 0, "튜토리얼땅배경");
  _scene->addChild(_bgLayer[kRoomName_Trap]);
  // UI
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼기본");
    } else if (i == 1) {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼오버");
      _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼오버")->setVisible(false);
    } else {
      _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getBoneCatapult(i), 0, "boneCatapult버튼클릭");
      _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
    }
  }
  _uiLayer[kRoomName_Trap]->addChild(_tutorialUI->getTrapRemove(), 0, "trapRemove");
  _uiLayer[kRoomName_Trap]->getChildByName("trapRemove")->setVisible(false);
  _uiLayer[kRoomName_Trap]->setVisible(false);
  _scene->addChild(_uiLayer[kRoomName_Trap], 1);
  // Label
  _labelLayer[kRoomName_Trap]->addChild(_tutorialLabel->getPlaceATrap(), 0, "placeATrap");
  _labelLayer[kRoomName_Trap]->addChild(_tutorialLabel->getBoneCatapult(), 0, "boneCatapult");
  _labelLayer[kRoomName_Trap]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Trap], 2);
  // hero
  _heroLayer = Layer::create();
  _heroLayer->addChild(_tutorialHero->getScout(), 0, "scoutIdle");
  _heroLayer->getChildByName("scoutIdle")->runAction(_tutorialHero->getScoutIdleAction());
  _heroLayer->addChild(_tutorialHero->getThug(), 0, "thugIdle");
  _heroLayer->getChildByName("thugIdle")->runAction(_tutorialHero->getThugIdleAction());
  _heroLayer->addChild(_tutorialHero->getBarbarian(), 0, "barbarianIdle");
  _heroLayer->getChildByName("barbarianIdle")->runAction(_tutorialHero->getBarbarianIdleAction());
  _heroLayer->setOpacity(7);
  _scene->addChild(_heroLayer, 1);
  // 트랩
  _trapLayer = Layer::create();  
  _trapLayer->addChild(_tutorialTrap->getBoneCatapultPortrait(), 0, "boneCatapultPortrait");
  _trapLayer->addChild(_tutorialTrap->getBoneCatapult(), 0, "boneCatapult");
  _trapLayer->getChildByName("boneCatapult")->setVisible(false);
  _trapLayer->setVisible(false);
  _scene->addChild(_trapLayer);

  /* RoomName_Spell */
  // 배경
  _bgLayer[kRoomName_Spell]->addChild(_tutorialBg->getBgDungeonRoom(_randBg[kRoomName_Spell]), 0, "튜토리얼배경");
  _bgLayer[kRoomName_Spell]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Spell), 0, "튜토리얼땅배경");
  _bgLayer[kRoomName_Spell]->setVisible(false);
  _scene->addChild(_bgLayer[kRoomName_Spell]);
  // Label
  _labelLayer[kRoomName_Spell]->addChild(_tutorialLabel->getWe(), 0, "we");  
  _labelLayer[kRoomName_Spell]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Spell], 2);

  /* RoomName_Monster */
  // 배경
  _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getBgDungeonRoom(_randBg[kRoomName_Monster]), 0, "튜토리얼배경");
  _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Monster), 0, "튜토리얼땅배경");
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getPlace(i), 0, "placeFront");
      _bgLayer[kRoomName_Monster]->getChildByName("placeFront")->setVisible(false);
    } else if (i == 1) {
      _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getPlace(i), 0, "placeMiddle");
      _bgLayer[kRoomName_Monster]->getChildByName("placeMiddle")->setVisible(false);
    } else {
      _bgLayer[kRoomName_Monster]->addChild(_tutorialBg->getPlace(i), 0, "placeBack");
      _bgLayer[kRoomName_Monster]->getChildByName("placeBack")->setVisible(false);
    }
  }
  _bgLayer[kRoomName_Monster]->setVisible(false);
  _scene->addChild(_bgLayer[kRoomName_Monster]);
  // UI
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getOrc(i), 0, "orc버튼기본");
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getSkeletonMagus(i), 0, "skeletonMagus버튼기본");
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getGhost(i), 0, "ghost버튼기본");
    } else if (i == 1) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getOrc(i), 0, "orc버튼오버");
      _uiLayer[kRoomName_Monster]->getChildByName("orc버튼오버")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getSkeletonMagus(i), 0, "skeletonMagus버튼오버");
      _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼오버")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getGhost(i), 0, "ghost버튼오버");
      _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼오버")->setVisible(false);
    } else {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getOrc(i), 0, "orc버튼클릭");
      _uiLayer[kRoomName_Monster]->getChildByName("orc버튼클릭")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getSkeletonMagus(i), 0, "skeletonMagus버튼클릭");
      _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼클릭")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getGhost(i), 0, "ghost버튼클릭");
      _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼클릭")->setVisible(false);
    }
  }
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getMonsterRemove(i), 0, "monsterRemoveOrc");
      _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getClickToPlace(i), 0, "clickToPlaceOrc");
      _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
    } else if (i == 1) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getMonsterRemove(i), 0, "monsterRemoveSkeletonMagus");
      _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getClickToPlace(i), 0, "clickToPlaceSkeletonMagus");
      _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
    } else {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getMonsterRemove(i), 0, "monsterRemoveGhost");
      _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(false);
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getClickToPlace(i), 0, "clickToPlaceGhost");
      _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
    }
  }
  for (byte i = 0; i < 3; i++) {
    if (i == 0) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getTransparencyPlace(i), 0, "transparencyPlaceFront");
    } else if (i == 1) {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getTransparencyPlace(i), 0, "transparencyPlaceMiddle");
    } else {
      _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getTransparencyPlace(i), 0, "transparencyPlaceBack");
    }
  }
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getPrevious(0), 0, "previous버튼기본");
  _uiLayer[kRoomName_Monster]->getChildByName("previous버튼기본")->setVisible(false);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getPrevious(1), 0, "previous버튼오버");
  _uiLayer[kRoomName_Monster]->getChildByName("previous버튼오버")->setVisible(false);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getPrevious(2), 0, "previous버튼클릭");
  _uiLayer[kRoomName_Monster]->getChildByName("previous버튼클릭")->setVisible(false);
  _turnPosition[0] = Vec2(60, 600), _turnPosition[1] = Vec2(60, 550), _turnPosition[2] = Vec2(60, 500);
  _turnPosition[3] = Vec2(60, 450), _turnPosition[4] = Vec2(60, 400), _turnPosition[5] = Vec2(60, 350);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getThugTurn(), 0, "thugTurn");
  _uiLayer[kRoomName_Monster]->getChildByName("thugTurn")->setPosition(_turnPosition[0]);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getScoutTurn(), 0, "scoutTurn");
  _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[1]);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getBarbarianTurn(), 0, "barbarianTurn");
  _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[2]);
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getOrcTurn(), 0, "orcTurn");
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getSkeletonMagusTurn(), 0, "skeletonMagusTurn");
  _uiLayer[kRoomName_Monster]->addChild(_tutorialUI->getGhostTurn(), 0, "ghostTurn");
  _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[3]);
  _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[4]);
  _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(_turnPosition[5]);
  _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(false);
  _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(false);
  _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(false);
  _uiLayer[kRoomName_Monster]->setVisible(false);
  _scene->addChild(_uiLayer[kRoomName_Monster], 2);
  // Label
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getSome(), 0, "some");
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getGrogmar(), 0, "grogmar");
  _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setVisible(false);
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getKhidus(), 0, "khidus");
  _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setVisible(false);
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getAurora(), 0, "aurora");
  _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setVisible(false);
  _labelLayer[kRoomName_Monster]->addChild(_tutorialLabel->getPrevious(), 0, "previous");
  _labelLayer[kRoomName_Monster]->getChildByName("previous")->setVisible(false);
  _labelLayer[kRoomName_Monster]->setVisible(false);
  _scene->addChild(_labelLayer[kRoomName_Monster], 2);
  // Monster
  _monsterLayer = Layer::create();
  _areaPosition[kArea_Front] = Vec2(VISIBLESIZE.width / 2 + 150, 300);
  _areaPosition[kArea_Middle] = Vec2(VISIBLESIZE.width / 2 + 300, 300);
  _areaPosition[kArea_Back] = Vec2(VISIBLESIZE.width / 2 + 450, 300);
  _clickToPlace = -1;
  _selectedMonster = kSelectedMonster_None;
  _selectedMonsterArea[0] = Vec2::ZERO;
  _selectedMonsterArea[1] = Vec2::ZERO;
  _selectedMonsterArea[2] = Vec2::ZERO;
  _isDecidedMonster[kSelectedMonster_Orc] = false;
  _isDecidedMonster[kSelectedMonster_SkeletonMagus] = false;
  _isDecidedMonster[kSelectedMonster_Ghost] = false;
  _decideMonster[0] = kSelectedMonster_None;
  _decideMonster[1] = kSelectedMonster_None;
  _decideMonster[2] = kSelectedMonster_None;
  _monsterLayer->addChild(_tutorialMonster->getOrcPortrait(0), 0, "orcPortrait");
  _monsterLayer->addChild(_tutorialMonster->getOrcPortrait(1), 0, "orcPortraitDisable");
  _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(false);
  _monsterLayer->addChild(_tutorialMonster->getOrc(), 0, "orc");
  _monsterLayer->getChildByName("orc")->runAction(_tutorialMonster->getOrcIdleAction());
  _monsterLayer->getChildByName("orc")->setVisible(false);
  _monsterLayer->addChild(_tutorialMonster->getSkeletonMagusPortrait(0), 0, "skeletonMagusPortrait");
  _monsterLayer->addChild(_tutorialMonster->getSkeletonMagusPortrait(1), 0, "skeletonMagusPortraitDisable");
  _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(false);
  _monsterLayer->addChild(_tutorialMonster->getSkeletonMagus(), 0, "skeletonMagus");
  _monsterLayer->getChildByName("skeletonMagus")->runAction(_tutorialMonster->getSkeletonMagusIdleAction());
  _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
  _monsterLayer->addChild(_tutorialMonster->getGhostPortrait(0), 0, "ghostPortrait");
  _monsterLayer->addChild(_tutorialMonster->getGhostPortrait(1), 0, "ghostPortraitDisable");
  _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(false);
  _monsterLayer->addChild(_tutorialMonster->getGhost(), 0, "ghost");
  _monsterLayer->getChildByName("ghost")->runAction(_tutorialMonster->getGhostIdleAction());
  _monsterLayer->getChildByName("ghost")->setVisible(false);
  _monsterLayer->setVisible(false);
  _scene->addChild(_monsterLayer, 1);

  /* RoomName_Master */
  _bgLayer[kRoomName_Master]->addChild(_tutorialBg->getBgDungeonRoom(_randBg[kRoomName_Master]), 0, "튜토리얼배경");
  _bgLayer[kRoomName_Master]->addChild(_tutorialBg->getBgDungeonGround(kRoomName_Master), 0, "튜토리얼땅배경");
  _bgLayer[kRoomName_Master]->setVisible(false);
  _scene->addChild(_bgLayer[kRoomName_Master]);
  // Master
  _masterLayer = Layer::create();
  _masterLayer->addChild(_tutorialMaster->getSlaveholder(), 0, "slaveholder");
  _masterLayer->getChildByName("slaveholder")->runAction(_tutorialMaster->getSlaveholderIdleAction());
  _masterLayer->setVisible(false);
  _scene->addChild(_masterLayer);

  // Schedule
  _scene->schedule(schedule_selector(Tutorial::callPerFrame));

  // 터치 이벤트 등록
  _touchListener = EventListenerTouchOneByOne::create();
  _touchListener->setSwallowTouches(true);
  _touchListener->onTouchBegan = CC_CALLBACK_2(Tutorial::onTouchBegan, this);
  _touchListener->onTouchEnded = CC_CALLBACK_2(Tutorial::onTouchEnded, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, _scene);

  // 마우스 이벤트 등록
  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(Tutorial::onMouseMove, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, _scene);
}

Tutorial::~Tutorial() {
  // 동적할당 해제
  CC_SAFE_DELETE(_tutorialBg);
  CC_SAFE_DELETE(_tutorialUI);
  CC_SAFE_DELETE(_tutorialLabel);
  CC_SAFE_DELETE(_tutorialHero);
  CC_SAFE_DELETE(_tutorialTrap);
  CC_SAFE_DELETE(_tutorialMonster);
  CC_SAFE_DELETE(_tutorialMaster);
}

bool Tutorial::onTouchBegan(Touch * touch, Event * event) {
  auto touchPoint = touch->getLocation();

  bool touchOption = _scene->getChildByName("option버튼오버")->
    getBoundingBox().containsPoint(touchPoint);
  if (touchOption) {
    _scene->getChildByName("option버튼클릭")->setVisible(true);
  } else {
    _scene->getChildByName("option버튼클릭")->setVisible(false);
  }
  
  if (!_isCombat) {
    if (_room == kRoomName_Trap) {
      if (_continue < 2) {
        bool touchContinue = _uiLayerDRH->getChildByName("continue버튼오버")->getBoundingBox().containsPoint(touchPoint);
        if (touchContinue) {
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(true);
        } else {
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
        }
      } else {
        bool touchBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼오버")->getBoundingBox().containsPoint(touchPoint);
        if (touchBoneCatapult) {
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->setVisible(true);
        } else {
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
        }
        if (_isTrap) {
          bool touchConfirm = _scene->getChildByName("confirm버튼오버")->getBoundingBox().containsPoint(touchPoint);
          if (touchConfirm) {
            _scene->getChildByName("confirm버튼클릭")->setVisible(true);
          } else {
            _scene->getChildByName("confirm버튼클릭")->setVisible(false);
          }
        }
      }

    } else if (_room == kRoomName_Spell) {
      bool touchContinue = _uiLayerDRH->getChildByName("continue버튼오버")->getBoundingBox().containsPoint(touchPoint);
      if (touchContinue) {
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(true);
      } else {
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
      }

    } else if (_room == kRoomName_Monster) {
      bool touchContinue = _uiLayerDRH->getChildByName("continue버튼오버")->getBoundingBox().containsPoint(touchPoint);
      if (touchContinue) {
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(true);
      } else {
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
      }
    }
  } else if (_isCombat) {

  }

  return true;
}

void Tutorial::onTouchEnded(Touch * touch, Event * event) {
  auto clickPoint = touch->getLocation();

  bool clickOption = _scene->getChildByName("option버튼클릭")->getBoundingBox().containsPoint(clickPoint);
  if (clickOption) {
  } else {
  }

  if (!_isCombat) {
    if (_room == kRoomName_Trap) {
      if (_continue == 0) {
        bool clickContinue = _uiLayerDRH->getChildByName("continue버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        if (clickContinue) {
          _continue++;
          _labelLayerDRH->getChildByName("heroes")->setVisible(true);
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
          _labelLayerDRH->getChildByName("congratulations")->setVisible(false);
        } else {
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
        }
      } else if (_continue == 1) {
        bool clickContinue = _uiLayerDRH->getChildByName("continue버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        if (clickContinue) {
          _continue++;
          _uiLayer[kRoomName_Trap]->setVisible(true);
          _labelLayer[kRoomName_Trap]->setVisible(true);
          _heroLayer->setOpacity(255);
          _trapLayer->setVisible(true);
          _bgLayerDRH->setVisible(false);
          _uiLayerDRH->setVisible(false);
          _labelLayerDRH->setVisible(false);
          _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(false);
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
          _labelLayerDRH->getChildByName("heroes")->setVisible(false);
        } else {
          _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
        }
      } else {
        bool clickBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        bool clickTrapRemove = _uiLayer[kRoomName_Trap]->getChildByName("trapRemove")->getBoundingBox().containsPoint(clickPoint);
        if (clickBoneCatapult) {
          _isTrap = true;
          _scene->getChildByName("confirm버튼기본")->setVisible(true);
          _scene->getChildByName("confirm")->setVisible(true);
          _uiLayer[kRoomName_Trap]->getChildByName("trapRemove")->setVisible(true);
          _trapLayer->getChildByName("boneCatapult")->setVisible(true);
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼오버")->setVisible(false);
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
        } else if (clickTrapRemove) {
          _isTrap = false;
          _scene->getChildByName("confirm버튼기본")->setVisible(false);
          _scene->getChildByName("confirm")->setVisible(false);
          _uiLayer[kRoomName_Trap]->getChildByName("trapRemove")->setVisible(false);
          _trapLayer->getChildByName("boneCatapult")->setVisible(false);
        } else {
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼클릭")->setVisible(false);
        }
        if (_isTrap) {
          bool clickConfirm = _scene->getChildByName("confirm버튼클릭")->getBoundingBox().containsPoint(clickPoint);
          if (clickConfirm) {
            _room = kRoomName_Spell;
            _bgLayer[kRoomName_Spell]->setVisible(true);
            _bgLayerDRH->setVisible(true);
            _uiLayerDRH->setVisible(true);
            _labelLayerDRH->setVisible(true);
            _labelLayer[kRoomName_Spell]->setVisible(true);
            _scene->getChildByName("confirm버튼기본")->setVisible(false);
            _scene->getChildByName("confirm버튼오버")->setVisible(false);
            _scene->getChildByName("confirm버튼클릭")->setVisible(false);
            _scene->getChildByName("confirm")->setVisible(false);
            _bgLayer[kRoomName_Trap]->setVisible(false);
            _uiLayer[kRoomName_Trap]->setVisible(false);
            _labelLayer[kRoomName_Trap]->setVisible(false);
            _trapLayer->setVisible(false);
          }
        }
      }

    } else if (_room == kRoomName_Spell) {
      bool clickContinue = _uiLayerDRH->getChildByName("continue버튼클릭")->getBoundingBox().containsPoint(clickPoint);
      if (clickContinue) {
        _room = kRoomName_Monster;
        _bgLayer[kRoomName_Monster]->setVisible(true);
        _bgLayerDRH->setVisible(true);
        _uiLayerDRH->setVisible(true);
        _labelLayerDRH->setVisible(true);
        _labelLayer[kRoomName_Monster]->setVisible(true);
        _bgLayer[kRoomName_Spell]->setVisible(false);
        _labelLayer[kRoomName_Spell]->setVisible(false);
        _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(false);
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
      } else {
        _uiLayerDRH->getChildByName("continue버튼클릭")->setVisible(false);
      }

    } else if (_room == kRoomName_Monster) {
      bool clickConfirm = _scene->getChildByName("confirm버튼클릭")->getBoundingBox().containsPoint(clickPoint);
      bool clickPrevious = _uiLayer[kRoomName_Monster]->getChildByName("previous버튼클릭")->getBoundingBox().containsPoint(clickPoint);
      if (clickConfirm) {
        if (_clickToPlace == 0) {

        } else {
          _room = kRoomName_Master;
          _isCombat = true;
          _bgLayer[kRoomName_Master]->setVisible(true);
          _masterLayer->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("previous버튼기본")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("previous버튼오버")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("previous버튼클릭")->setVisible(false);
          _scene->getChildByName("confirm버튼기본")->setVisible(false);
          _scene->getChildByName("confirm버튼오버")->setVisible(false);
          _scene->getChildByName("confirm버튼클릭")->setVisible(false);
          _scene->getChildByName("confirm")->setVisible(false);
          _uiLayer[kRoomName_Monster]->setVisible(false);
          _labelLayer[kRoomName_Monster]->setVisible(false);
          _monsterLayer->setVisible(false);
          _bgLayerDRH->setVisible(false);
          _uiLayerDRH->setVisible(false);
          _labelLayerDRH->setVisible(false);
          _heroLayer->setVisible(false);
          _scene->scheduleOnce(schedule_selector(Tutorial::callOnce), 0);
        }
      } else if (clickPrevious) {
        _room = kRoomName_Trap;
      }

      if (_clickToPlace == -1) {
        bool clickContinue = _uiLayerDRH->getChildByName("continue버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        if (clickContinue) {
          _scene->getChildByName("confirm버튼기본")->setVisible(true);
          _scene->getChildByName("confirm")->setVisible(true);
          _clickToPlace++;
          _bgLayer[kRoomName_Monster]->getChildByName("placeFront")->setVisible(true);
          _bgLayer[kRoomName_Monster]->getChildByName("placeMiddle")->setVisible(true);
          _bgLayer[kRoomName_Monster]->getChildByName("placeBack")->setVisible(true);
          _uiLayer[kRoomName_Monster]->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceFront")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceMiddle")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceBack")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("previous버튼기본")->setVisible(true);
          _labelLayer[kRoomName_Monster]->setVisible(true);
          _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setVisible(true);
          _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setVisible(true);
          _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setVisible(true);
          _labelLayer[kRoomName_Monster]->getChildByName("previous")->setVisible(true);
          _monsterLayer->setVisible(true);
          _monsterLayer->getChildByName("orcPortrait")->setVisible(true);
          _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(true);
          _monsterLayer->getChildByName("ghostPortrait")->setVisible(true);
          _bgLayerDRH->setVisible(false);
          _uiLayerDRH->setVisible(false);
          _labelLayerDRH->setVisible(false);
          _labelLayer[kRoomName_Monster]->getChildByName("some")->setVisible(false);
        }
      } else if (_clickToPlace == 0) {
        bool clickOrcBtn = _uiLayer[kRoomName_Monster]->getChildByName("orc버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        bool clickOrcPortrait = _monsterLayer->getChildByName("orcPortrait")->getBoundingBox().containsPoint(clickPoint);
        bool clickSkeletonMagusBtn = _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        bool clickSkeletonMagusPortrait = _monsterLayer->getChildByName("skeletonMagusPortrait")->getBoundingBox().containsPoint(clickPoint);
        bool clickGhostBtn = _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼클릭")->getBoundingBox().containsPoint(clickPoint);
        bool clickGhostPortrait = _monsterLayer->getChildByName("ghostPortrait")->getBoundingBox().containsPoint(clickPoint);
        if ((clickOrcBtn || clickOrcPortrait) && (!_isDecidedMonster[kSelectedMonster_Orc])) {
          _selectedMonster = kSelectedMonster_Orc;
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_areaPosition[kArea_Front].x - 100, _areaPosition[kArea_Front].y);
          _monsterLayer->getChildByName("orc")->setVisible(true);
          _monsterLayer->getChildByName("orc")->setPosition(_areaPosition[kArea_Front]);
          // 중복 클릭 방지
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
          _monsterLayer->getChildByName("ghost")->setVisible(false);
        } else if ((clickSkeletonMagusBtn || clickSkeletonMagusPortrait) && (!_isDecidedMonster[kSelectedMonster_SkeletonMagus])) {
          _selectedMonster = kSelectedMonster_SkeletonMagus;
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_areaPosition[kArea_Front].x - 100, _areaPosition[kArea_Front].y);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(true);
          _monsterLayer->getChildByName("skeletonMagus")->setPosition(_areaPosition[kArea_Front]);
          // 중복 클릭 방지
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
          _monsterLayer->getChildByName("orc")->setVisible(false);
          _monsterLayer->getChildByName("ghost")->setVisible(false);
        } else if ((clickGhostBtn || clickGhostPortrait) && (!_isDecidedMonster[kSelectedMonster_Ghost])) {
          _selectedMonster = kSelectedMonster_Ghost;
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_areaPosition[kArea_Front].x - 100, _areaPosition[kArea_Front].y);
          _monsterLayer->getChildByName("ghost")->setVisible(true);
          _monsterLayer->getChildByName("ghost")->setPosition(_areaPosition[kArea_Front]);
          // 중복 클릭 방지
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
          _monsterLayer->getChildByName("orc")->setVisible(false);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
        }

        if (_selectedMonster == kSelectedMonster_Orc) {
          bool clickOrc = _monsterLayer->getChildByName("orc")->getBoundingBox().containsPoint(clickPoint);
          if (clickOrc) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_Orc] = true;
            _decideMonster[0] = kSelectedMonster_Orc;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
            _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(127);
            _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("orcPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("orcPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
            _monsterLayer->getChildByName("orcPortrait")->setVisible(false);
          }
        } else if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
          bool clickSkeletonMagus = _monsterLayer->getChildByName("skeletonMagus")->getBoundingBox().containsPoint(clickPoint);
          if (clickSkeletonMagus) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_SkeletonMagus] = true;
            _decideMonster[0] = kSelectedMonster_SkeletonMagus;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
            _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(127);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
            _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(false);
          }
        } else if (_selectedMonster == kSelectedMonster_Ghost) {
          bool clickGhost = _monsterLayer->getChildByName("ghost")->getBoundingBox().containsPoint(clickPoint);
          if (clickGhost) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_Ghost] = true;
            _decideMonster[0] = kSelectedMonster_Ghost;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(_turnPosition[1]);
            _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
            _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(127);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
            _monsterLayer->getChildByName("ghostPortrait")->setVisible(false);
          }
        }
      } else if (_clickToPlace == 1) {
        bool clickRemoveOrc = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveSkeletonMagus = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveGhost = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->getBoundingBox().containsPoint(clickPoint);
        if (clickRemoveOrc && _isDecidedMonster[kSelectedMonster_Orc] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          _selectedMonsterArea[0] = Vec2::ZERO;
          _decideMonster[0] = kSelectedMonster_None;
          _isDecidedMonster[kSelectedMonster_Orc] = false;
          _monsterLayer->getChildByName("orcPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[2]);
          _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(255);
          _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("orc")->setVisible(false);
        } else if (clickRemoveSkeletonMagus && _isDecidedMonster[kSelectedMonster_SkeletonMagus] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          _selectedMonsterArea[0] = Vec2::ZERO;
          _decideMonster[0] = kSelectedMonster_None;
          _isDecidedMonster[kSelectedMonster_SkeletonMagus] = false;
          _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[2]);
          _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(255);
          _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
        } else if (clickRemoveGhost && _isDecidedMonster[kSelectedMonster_Ghost] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          _selectedMonsterArea[0] = Vec2::ZERO;
          _decideMonster[0] = kSelectedMonster_None;
          _isDecidedMonster[kSelectedMonster_Ghost] = false;
          _monsterLayer->getChildByName("ghostPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[1]);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[2]);
          _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(255);
          _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("ghost")->setVisible(false);
        }

        if (_decideMonster[0] == kSelectedMonster_Orc) {
          bool clickSkeletonMagusBtn = _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickSkeletonMagusPortrait = _monsterLayer->getChildByName("skeletonMagusPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhostBtn = _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhostPortrait = _monsterLayer->getChildByName("ghostPortrait")->getBoundingBox().containsPoint(clickPoint);
          if ((clickSkeletonMagusBtn || clickSkeletonMagusPortrait) && (!_isDecidedMonster[kSelectedMonster_SkeletonMagus])) {
            _selectedMonster = kSelectedMonster_SkeletonMagus;
            _monsterLayer->getChildByName("skeletonMagus")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
            _monsterLayer->getChildByName("ghost")->setVisible(false);
          } else if ((clickGhostBtn || clickGhostPortrait) && (!_isDecidedMonster[kSelectedMonster_Ghost])) {
            _selectedMonster = kSelectedMonster_Ghost;
            _monsterLayer->getChildByName("ghost")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
            _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
          }

          if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
            bool clickSkeletonMagus = _monsterLayer->getChildByName("skeletonMagus")->getBoundingBox().containsPoint(clickPoint);
            if (clickSkeletonMagus) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_SkeletonMagus] = true;
              _decideMonster[1] = kSelectedMonster_SkeletonMagus;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[2]);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(127);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
              _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(false);
            }
          } else if (_selectedMonster == kSelectedMonster_Ghost) {
            bool clickGhost = _monsterLayer->getChildByName("ghost")->getBoundingBox().containsPoint(clickPoint);
            if (clickGhost) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_Ghost] = true;
              _decideMonster[1] = kSelectedMonster_Ghost;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(_turnPosition[1]);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[2]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(127);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
              _monsterLayer->getChildByName("ghostPortrait")->setVisible(false);
            }
          }
        } else if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
          bool clickOrcBtn = _uiLayer[kRoomName_Monster]->getChildByName("orc버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickOrcPortrait = _monsterLayer->getChildByName("orcPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhostBtn = _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhostPortrait = _monsterLayer->getChildByName("ghostPortrait")->getBoundingBox().containsPoint(clickPoint);
          if ((clickOrcBtn || clickOrcPortrait) && (!_isDecidedMonster[kSelectedMonster_Orc])) {
            _selectedMonster = kSelectedMonster_Orc;
            _monsterLayer->getChildByName("orc")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
            _monsterLayer->getChildByName("ghost")->setVisible(false);
          } else if ((clickGhostBtn || clickGhostPortrait) && (!_isDecidedMonster[kSelectedMonster_Ghost])) {
            _selectedMonster = kSelectedMonster_Ghost;
            _monsterLayer->getChildByName("ghost")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
            _monsterLayer->getChildByName("orc")->setVisible(false);
          }
          if (_selectedMonster == kSelectedMonster_Orc) {
            bool clickOrc = _monsterLayer->getChildByName("orc")->getBoundingBox().containsPoint(clickPoint);
            if (clickOrc) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_Orc] = true;
              _decideMonster[1] = kSelectedMonster_Orc;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[2]);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(127);
              _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("orcPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("orcPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
              _monsterLayer->getChildByName("orcPortrait")->setVisible(false);
            }
          } else if (_selectedMonster == kSelectedMonster_Ghost) {
            bool clickGhost = _monsterLayer->getChildByName("ghost")->getBoundingBox().containsPoint(clickPoint);
            if (clickGhost) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_Ghost] = true;
              _decideMonster[1] = kSelectedMonster_Ghost;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(_turnPosition[1]);
              _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[2]);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(127);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("ghostPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
              _monsterLayer->getChildByName("ghostPortrait")->setVisible(false);
            }
          }
        } else if (_decideMonster[0] == kSelectedMonster_Ghost) {
          bool clickOrcBtn = _uiLayer[kRoomName_Monster]->getChildByName("orc버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickOrcPortrait = _monsterLayer->getChildByName("orcPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickSkeletonMagusBtn = _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickSkeletonMagusPortrait = _monsterLayer->getChildByName("skeletonMagusPortrait")->getBoundingBox().containsPoint(clickPoint);
          if ((clickOrcBtn || clickOrcPortrait) && (!_isDecidedMonster[kSelectedMonster_Orc])) {
            _selectedMonster = kSelectedMonster_Orc;
            _monsterLayer->getChildByName("orc")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
            _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);
          } else if ((clickSkeletonMagusBtn || clickSkeletonMagusPortrait) && (!_isDecidedMonster[kSelectedMonster_SkeletonMagus])) {
            _selectedMonster = kSelectedMonster_SkeletonMagus;
            _monsterLayer->getChildByName("skeletonMagus")->setVisible(true);
            if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
              _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
            } else {
              _selectedMonsterArea[1] = _areaPosition[kArea_Front];
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
            }
            // 중복 클릭 방지
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
            _monsterLayer->getChildByName("orc")->setVisible(false);
          }
          if (_selectedMonster == kSelectedMonster_Orc) {
            bool clickOrc = _monsterLayer->getChildByName("orc")->getBoundingBox().containsPoint(clickPoint);
            if (clickOrc) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_Orc] = true;
              _decideMonster[1] = kSelectedMonster_Orc;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(127);
              _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("orcPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("orcPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
              _monsterLayer->getChildByName("orcPortrait")->setVisible(false);
            }
          } else if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
            bool clickGhost = _monsterLayer->getChildByName("skeletonMagus")->getBoundingBox().containsPoint(clickPoint);
            if (clickGhost) {
              _clickToPlace++;
              _isDecidedMonster[kSelectedMonster_SkeletonMagus] = true;
              _decideMonster[1] = kSelectedMonster_SkeletonMagus;
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(true);
              _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
              _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
              _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(127);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(true);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setOpacity(127);
              _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setColor(Color3B(127, 127, 127));
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
              _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(false);
            }
          }
        }

      } else if (_clickToPlace == 2) {
        bool clickRemoveOrc = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveSkeletonMagus = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveGhost = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->getBoundingBox().containsPoint(clickPoint);
        if (clickRemoveOrc && _isDecidedMonster[kSelectedMonster_Orc] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_Orc) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_Orc) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_Orc] = false;
          _monsterLayer->getChildByName("orcPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(Vec2::ZERO);
          if (_isDecidedMonster[kSelectedMonster_SkeletonMagus]) {
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          } else if (_isDecidedMonster[kSelectedMonster_Ghost]) {
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          }
          _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(255);
          _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("orc")->setVisible(false);

        } else if (clickRemoveSkeletonMagus && _isDecidedMonster[kSelectedMonster_SkeletonMagus] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_SkeletonMagus] = false;
          _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(Vec2::ZERO);
          if (_isDecidedMonster[kSelectedMonster_Orc]) {
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          } else if (_isDecidedMonster[kSelectedMonster_Ghost]) {
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          }
          _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(255);
          _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);

        } else if (clickRemoveGhost && _isDecidedMonster[kSelectedMonster_Ghost] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_Ghost) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_Ghost] = false;
          _monsterLayer->getChildByName("ghostPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(Vec2::ZERO);
          if (_isDecidedMonster[kSelectedMonster_Orc]) {
            _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[1]);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          } else if (_isDecidedMonster[kSelectedMonster_SkeletonMagus]) {
            _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[1]);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[3]);
          }
          _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(255);
          _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("ghost")->setVisible(false);
        }

        // 남은 위치 탐색
        if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
          if (_selectedMonsterArea[1] == _areaPosition[kArea_Middle]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Back];
          } else if (_selectedMonsterArea[1] == _areaPosition[kArea_Back]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Middle];
          }
        } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Middle]) {
          if (_selectedMonsterArea[1] == _areaPosition[kArea_Front]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Back];
          } else if (_selectedMonsterArea[1] == _areaPosition[kArea_Back]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Front];
          }
        } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Back]) {
          if (_selectedMonsterArea[1] == _areaPosition[kArea_Front]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Middle];
          } else if (_selectedMonsterArea[1] == _areaPosition[kArea_Middle]) {
            _selectedMonsterArea[2] = _areaPosition[kArea_Front];
          }
        }
        // 남은 몬스터 탐색
        if (_selectedMonsterArea[2] == _areaPosition[kArea_Back]) {
          if (_decideMonster[0] == kSelectedMonster_Orc) {
            if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            }
          } else if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          } else if (_decideMonster[0] == kSelectedMonster_Ghost) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            } else if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          }
        } else if (_selectedMonsterArea[2] == _areaPosition[kArea_Middle]) {
          if (_decideMonster[0] == kSelectedMonster_Orc) {
            if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            }
          } else if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          } else if (_decideMonster[0] == kSelectedMonster_Ghost) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            } else if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          }
        } else if (_selectedMonsterArea[2] == _areaPosition[kArea_Front]) {
          if (_decideMonster[0] == kSelectedMonster_Orc) {
            if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            }
          } else if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_Ghost;
            } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          } else if (_decideMonster[0] == kSelectedMonster_Ghost) {
            if (_decideMonster[1] == kSelectedMonster_Orc) {
              _selectedMonster = kSelectedMonster_SkeletonMagus;
            } else if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
              _selectedMonster = kSelectedMonster_Orc;
            }
          }
        }

        if (_selectedMonster == kSelectedMonster_Ghost) {
          bool clickGhostBtn = _uiLayer[kRoomName_Monster]->getChildByName("ghost버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhostPortrait = _monsterLayer->getChildByName("ghostPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickGhost = _monsterLayer->getChildByName("ghost")->getBoundingBox().containsPoint(clickPoint);
          if ((clickGhostBtn || clickGhostPortrait) && (!_isDecidedMonster[kSelectedMonster_Ghost])) {
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _monsterLayer->getChildByName("ghost")->setVisible(true);
            _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[2]);
          } else if (clickGhost) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_Ghost] = true;
            _decideMonster[2] = kSelectedMonster_Ghost;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(_turnPosition[1]);
            _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[2]);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[3]);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[4]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[5]);
            _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(127);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("ghostPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(false);
            _monsterLayer->getChildByName("ghostPortrait")->setVisible(false);
          }
        } else if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
          bool clickSkeletonMagusBtn = _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagus버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickSkeletonMagusPortrait = _monsterLayer->getChildByName("skeletonMagusPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickSkeletonMagus = _monsterLayer->getChildByName("skeletonMagus")->getBoundingBox().containsPoint(clickPoint);
          if ((clickSkeletonMagusBtn || clickSkeletonMagusPortrait) && (!_isDecidedMonster[kSelectedMonster_SkeletonMagus])) {
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _monsterLayer->getChildByName("skeletonMagus")->setVisible(true);
            _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[2]);
          } else if (clickSkeletonMagus) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_SkeletonMagus] = true;
            _decideMonster[2] = kSelectedMonster_SkeletonMagus;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[4]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[5]);
            _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(127);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(false);
            _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(false);
          }
        } else if (_selectedMonster == kSelectedMonster_Orc) {
          bool clickOrcBtn = _uiLayer[kRoomName_Monster]->getChildByName("orc버튼오버")->getBoundingBox().containsPoint(clickPoint);
          bool clickOrcPortrait = _monsterLayer->getChildByName("orcPortrait")->getBoundingBox().containsPoint(clickPoint);
          bool clickOrc = _monsterLayer->getChildByName("orc")->getBoundingBox().containsPoint(clickPoint);
          if ((clickOrcBtn || clickOrcPortrait) && (!_isDecidedMonster[kSelectedMonster_Orc])) {
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _monsterLayer->getChildByName("orc")->setVisible(true);
            _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[2]);
          } else if (clickOrc) {
            _clickToPlace++;
            _isDecidedMonster[kSelectedMonster_Orc] = true;
            _decideMonster[2] = kSelectedMonster_Orc;
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setPosition(_selectedMonsterArea[2].x - 100, _selectedMonsterArea[2].y);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(true);
            _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[4]);
            _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
            _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[5]);
            _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(127);
            _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(true);
            _monsterLayer->getChildByName("orcPortraitDisable")->setOpacity(127);
            _monsterLayer->getChildByName("orcPortraitDisable")->setColor(Color3B(127, 127, 127));
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(false);
            _monsterLayer->getChildByName("orcPortrait")->setVisible(false);
          }
        }

      } else if (_clickToPlace == 3) {
        bool clickRemoveOrc = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveSkeletonMagus = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->getBoundingBox().containsPoint(clickPoint);
        bool clickRemoveGhost = _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->getBoundingBox().containsPoint(clickPoint);
        if (clickRemoveOrc && _isDecidedMonster[kSelectedMonster_Orc] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_Orc) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_Orc) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          } else if (_decideMonster[2] == kSelectedMonster_Orc) {
            _decideMonster[2] = kSelectedMonster_None;
            _selectedMonsterArea[2] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_Orc] = false;
          _monsterLayer->getChildByName("orcPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveOrc")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
          _labelLayer[kRoomName_Monster]->getChildByName("grogmar")->setOpacity(255);
          _monsterLayer->getChildByName("orcPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("orc")->setVisible(false);

        } else if (clickRemoveSkeletonMagus && _isDecidedMonster[kSelectedMonster_SkeletonMagus] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_SkeletonMagus) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          } else if (_decideMonster[2] == kSelectedMonster_SkeletonMagus) {
            _decideMonster[2] = kSelectedMonster_None;
            _selectedMonsterArea[2] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_SkeletonMagus] = false;
          _monsterLayer->getChildByName("skeletonMagusPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveSkeletonMagus")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
          _labelLayer[kRoomName_Monster]->getChildByName("khidus")->setOpacity(255);
          _monsterLayer->getChildByName("skeletonMagusPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("skeletonMagus")->setVisible(false);

        } else if (clickRemoveGhost && _isDecidedMonster[kSelectedMonster_Ghost] == true) {
          _selectedMonster = kSelectedMonster_None;
          _clickToPlace--;
          if (_decideMonster[0] == kSelectedMonster_Ghost) {
            _decideMonster[0] = kSelectedMonster_None;
            _selectedMonsterArea[0] = Vec2::ZERO;
          } else if (_decideMonster[1] == kSelectedMonster_Ghost) {
            _decideMonster[1] = kSelectedMonster_None;
            _selectedMonsterArea[1] = Vec2::ZERO;
          } else if (_decideMonster[2] == kSelectedMonster_Ghost) {
            _decideMonster[2] = kSelectedMonster_None;
            _selectedMonsterArea[2] = Vec2::ZERO;
          }
          _isDecidedMonster[kSelectedMonster_Ghost] = false;
          _monsterLayer->getChildByName("ghostPortrait")->setVisible(true);
          _uiLayer[kRoomName_Monster]->getChildByName("monsterRemoveGhost")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setVisible(false);
          _uiLayer[kRoomName_Monster]->getChildByName("ghostTurn")->setPosition(Vec2::ZERO);
          _uiLayer[kRoomName_Monster]->getChildByName("scoutTurn")->setPosition(_turnPosition[1]);
          _uiLayer[kRoomName_Monster]->getChildByName("orcTurn")->setPosition(_turnPosition[2]);
          _uiLayer[kRoomName_Monster]->getChildByName("skeletonMagusTurn")->setPosition(_turnPosition[3]);
          _uiLayer[kRoomName_Monster]->getChildByName("barbarianTurn")->setPosition(_turnPosition[4]);
          _labelLayer[kRoomName_Monster]->getChildByName("aurora")->setOpacity(255);
          _monsterLayer->getChildByName("ghostPortraitDisable")->setVisible(false);
          _monsterLayer->getChildByName("ghost")->setVisible(false);
        }
      }
    } else if (_room == kRoomName_Master) {
    }
  } else if (_isCombat) {

  }
}

void Tutorial::onMouseMove(Event * event) {
  EventMouse* mousePosition = (EventMouse*)event;

  bool overOption = _scene->getChildByName("option버튼기본")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
  if (overOption) {
    _scene->getChildByName("option버튼오버")->setVisible(true);
  } else {
    _scene->getChildByName("option버튼오버")->setVisible(false);
  }

  if (!_isCombat) {
    if (_room == kRoomName_Trap) {
      if (_continue < 2) {
        bool overContinue = _uiLayerDRH->getChildByName("continue버튼기본")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
        if (overContinue) {
          _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(true);
        } else {
          _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(false);
        }
      } else {
        bool overBoneCatapult = _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼기본")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
        if (overBoneCatapult) {
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼오버")->setVisible(true);
        } else {
          _uiLayer[kRoomName_Trap]->getChildByName("boneCatapult버튼오버")->setVisible(false);
        }
        if (_isTrap) {
          bool overConfirm = _scene->getChildByName("confirm버튼기본")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
          if (overConfirm) {
            _scene->getChildByName("confirm버튼오버")->setVisible(true);
          } else {
            _scene->getChildByName("confirm버튼오버")->setVisible(false);
          }
        }
      }

    } else if (_room == kRoomName_Spell) {
      bool overContinue = _uiLayerDRH->getChildByName("continue버튼기본")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
      if (overContinue) {
        _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(true);
      } else {
        _uiLayerDRH->getChildByName("continue버튼오버")->setVisible(false);
      }

    } else if (_room == kRoomName_Monster) {
      bool overTransparencyPlaceFront = _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceFront")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
      bool overTransparencyPlaceMiddle = _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceMiddle")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
      bool overTransparencyPlaceBack = _uiLayer[kRoomName_Monster]->getChildByName("transparencyPlaceBack")->getBoundingBox().containsPoint(Vec2(mousePosition->getCursorX(), mousePosition->getCursorY()));
      if (_clickToPlace == 0) {
        if (_selectedMonster == kSelectedMonster_Orc) {
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
          if (overTransparencyPlaceFront) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Front];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceMiddle) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Middle];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceBack) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Back];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[0]);
          }
        } else if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
          if (overTransparencyPlaceFront) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Front];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceMiddle) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Middle];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceBack) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Back];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[0]);
          }
        } else if (_selectedMonster == kSelectedMonster_Ghost) {
          _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
          if (overTransparencyPlaceFront) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Front];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceMiddle) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Middle];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[0]);
          } else if (overTransparencyPlaceBack) {
            _selectedMonsterArea[0] = _areaPosition[kArea_Back];
            _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[0].x - 100, _selectedMonsterArea[0].y);
            _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[0]);
          }
        }

      } else if (_clickToPlace == 1) {
        if (_decideMonster[0] == kSelectedMonster_Orc) {
          if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Middle]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Back]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          }
        } else if (_decideMonster[0] == kSelectedMonster_SkeletonMagus) {
          if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
            if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Middle]) {
            if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Back]) {
            if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Ghost) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceGhost")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("ghost")->setPosition(_selectedMonsterArea[1]);
              }
            }
          }
        } else if (_decideMonster[0] == kSelectedMonster_Ghost) {
          if (_selectedMonsterArea[0] == _areaPosition[kArea_Front]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Middle]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceBack) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Back];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            }
          } else if (_selectedMonsterArea[0] == _areaPosition[kArea_Back]) {
            if (_selectedMonster == kSelectedMonster_SkeletonMagus) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceSkeletonMagus")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("skeletonMagus")->setPosition(_selectedMonsterArea[1]);
              }
            } else if (_selectedMonster == kSelectedMonster_Orc) {
              _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setVisible(true);
              if (overTransparencyPlaceFront) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Front];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              } else if (overTransparencyPlaceMiddle) {
                _selectedMonsterArea[1] = _areaPosition[kArea_Middle];
                _uiLayer[kRoomName_Monster]->getChildByName("clickToPlaceOrc")->setPosition(_selectedMonsterArea[1].x - 100, _selectedMonsterArea[1].y);
                _monsterLayer->getChildByName("orc")->setPosition(_selectedMonsterArea[1]);
              }
            }
          }
        }

      } else if (_clickToPlace == 2) {

      }
    }
  } else if (_isCombat) {

  }
}

void Tutorial::callPerFrame(float delta) {
  if (_isCombat) {
    
  }
}

void Tutorial::callOnce(float delta) {
  log("check");
}
