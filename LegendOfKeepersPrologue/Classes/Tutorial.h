#ifndef __TUTORIAL_H__
#define __TUTORIAL_H__

#include "framework.h"
#include "TutorialBg.h"
#include "TutorialUI.h"
#include "TutorialLabel.h"
#include "TutorialHero.h"
#include "TutorialTrap.h"
#include "TutorialMonster.h"
#include "TutorialMaster.h"

class Tutorial : Scene
{
 public:
  Tutorial(Scene* pScene);
  ~Tutorial();
 private:
  enum eRoomName
  {
    kRoomName_Trap,
    kRoomName_Spell,
    kRoomName_Monster,
    kRoomName_Master
  };
  enum eSelectedMonster
  {
    kSelectedMonster_None = -1,
    kSelectedMonster_Orc,
    kSelectedMonster_SkeletonMagus,
    kSelectedMonster_Ghost
  };
  enum eArea
  {
    kArea_Front,
    kArea_Middle,
    kArea_Back
  };
 private:
  EventListenerTouchOneByOne* _touchListener;
  bool onTouchBegan(Touch* touch, Event* event);
  void onTouchEnded(Touch* touch, Event* event);
  EventListenerMouse* _mouseListener;
  void onMouseMove(Event* event);
  Scene* _scene;
  byte _room;
  byte _continue;
  bool _isTrap;
  Layer* _bgLayerDRH, *_uiLayerDRH, *_labelLayerDRH;
  TutorialBg* _tutorialBg;
  byte _randBg[4];
  Layer* _bgLayer[4];
  TutorialUI* _tutorialUI;
  Layer* _uiLayer[3];
  TutorialLabel* _tutorialLabel;
  Layer* _labelLayer[3];
  TutorialHero* _tutorialHero;
  Layer* _heroLayer;
  TutorialTrap* _tutorialTrap;
  Layer* _trapLayer;
  TutorialMonster* _tutorialMonster;
  Layer* _monsterLayer;
  Vec2 _areaPosition[3];
  char _clickToPlace;
  char _selectedMonster;
  Vec2 _selectedMonsterArea[3];
  bool _isDecidedMonster[3];
  char _decideMonster[3];
};

#endif // __TUTORIAL_H__
