#include "TutorialLabel.h"

TutorialLabel::TutorialLabel() {
  TTFConfig mainfontBold("FONT/Mainfont-Bold.ttf", 15);
  TTFConfig mainfontLight("FONT/Mainfont-Light.ttf", 18);
  TTFConfig mainfontRegular("FONT/Mainfont-Regular.ttf", 18);
  TTFConfig mainfontSemibold("FONT/Mainfont-Semibold.ttf", 18);
  TTFConfig RobotoRegular("FONT/Roboto-Regular.ttf", 18);

  _congratulations = Label::createWithTTF(
    mainfontBold,
    "Congratulations and welcome to the Dungeons Company!\n\n"
    "As you saw on the job posting, your main task is to project the treasures\n"
    "we keep in our dungeons. We don't have much time to spend training\n"
    "you, so please keep up!");
  _congratulations->setPosition(Vec2(VISIBLESIZE.width / 2 + 195,
                                     VISIBLESIZE.height / 2 + 105));

  _continue = Label::createWithTTF(mainfontBold, "Continue");
  _continue->setPosition(Vec2(900, 300));

  _heroes = Label::createWithTTF(
    mainfontBold,
    "Heroes keep coming to try and take our treasures. The marketing team\n"
    "has worked hard to promise gold and glory to these idiotic villagers.\n\n"
    "We have a little time before they get here, so let's place our traps and our\n"
    "employees to prepare a defense.");
  _heroes->setPosition(Vec2(VISIBLESIZE.width / 2 + 195,
                            VISIBLESIZE.height / 2 + 105));
}
