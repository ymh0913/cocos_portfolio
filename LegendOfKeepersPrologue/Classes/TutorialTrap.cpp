#include "TutorialTrap.h"

TutorialTrap::TutorialTrap() {
  _boneCatapultPortrait = Sprite::create("TutorialScene/Trap/traps_catapult.png");
  _boneCatapultPortrait->setPosition(Vec2(VISIBLESIZE.width / 2,
                                  VISIBLESIZE.height / 2 + 100));

  _boneCatapult = Sprite::create("TutorialScene/Trap/traps_catapult.png");
  _boneCatapult->setPosition(Vec2(VISIBLESIZE.width / 2 + 200,
                                       VISIBLESIZE.height / 2));
}
