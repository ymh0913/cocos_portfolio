#include "TutorialTrap.h"

TutorialTrap::TutorialTrap() {
  _boneCatapult = Sprite::create("TutorialScene/Trap/traps_catapult.png");
  _boneCatapult->setPosition(Vec2(VISIBLESIZE.width / 2,
                                  VISIBLESIZE.height / 2 + 100));
}
