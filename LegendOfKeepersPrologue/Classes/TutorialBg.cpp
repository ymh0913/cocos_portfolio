#include "TutorialBg.h"

TutorialBg::TutorialBg() {
  _bgDungeonRoom = Sprite::create(
    "TutorialScene/Bg/bg_dungeon_room0_1.png");
  _bgDungeonRoom->setAnchorPoint(Vec2(0, 0));
  _bgDungeonRoom->setScale(1.5f);
  _bgDungeonRoom->setPosition(Vec2(-160, 150));
}
