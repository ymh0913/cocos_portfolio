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
  _congratulations->setPosition(Vec2(VISIBLESIZE.width / 2 + 195, VISIBLESIZE.height / 2 + 105));

  _continue = Label::createWithTTF(mainfontBold, "Continue");
  _continue->setPosition(Vec2(900, 300));

  _heroes = Label::createWithTTF(
    mainfontBold,
    "Heroes keep coming to try and take our treasures. The marketing team\n"
    "has worked hard to promise gold and glory to these idiotic villagers.\n\n"
    "We have a little time before they get here, so let's place our traps and our\n"
    "employees to prepare a defense.");
  _heroes->setPosition(Vec2(VISIBLESIZE.width / 2 + 195, VISIBLESIZE.height / 2 + 105));

  mainfontBold.fontSize = 12;
  _placeATrap = Label::createWithTTF(mainfontBold, "Place a trap");
  _placeATrap->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height - 150));

  mainfontBold.fontSize = 9;
  _boneCatapult = Label::createWithTTF(mainfontBold, "BONE CATAPULT");
  _boneCatapult->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 100));

  mainfontBold.fontSize = 12;
  _confirm = Label::createWithTTF(mainfontBold, "Confirm");
  _confirm->setPosition(Vec2(VISIBLESIZE.width - 100, 100));

  mainfontBold.fontSize = 15;
  _we = Label::createWithTTF(
    mainfontBold,
    "We always leave an empty room in every dungeon.\n\n"
    "You can use it to ambush the adventures with one of your favourite\n"
    "spells!");
  _we->setPosition(Vec2(VISIBLESIZE.width / 2 + 195, VISIBLESIZE.height / 2 + 105));

  _some = Label::createWithTTF(
    mainfontBold,
    "Some rooms are dedicated to combat. That is my favourite bit!\n\n"
    "Make sure you analyse each group of adventures. Your employees are\n"
    "counting on you to prepare an effective strategy.\n\n"
    "Pay attention to your monster's Registances and Armor, so you don't have\n"
    "to send them to the infirmary.");
  _some->setPosition(Vec2(VISIBLESIZE.width / 2 + 195, VISIBLESIZE.height / 2 + 90));

  mainfontBold.fontSize = 12;
  _placeATrap = Label::createWithTTF(mainfontBold, "PLACE YOUR MONSTERS");
  _placeATrap->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height - 150));

  mainfontBold.fontSize = 9;
  _grogmar = Label::createWithTTF(mainfontBold, "GROGMAR");
  _grogmar->setPosition(Vec2(VISIBLESIZE.width / 2 - 200, VISIBLESIZE.height / 2 + 100));

  _khidus = Label::createWithTTF(mainfontBold, "KHIDUS");
  _khidus->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 100));

  _aurora = Label::createWithTTF(mainfontBold, "AURORA");
  _aurora->setPosition(Vec2(VISIBLESIZE.width / 2 + 200, VISIBLESIZE.height / 2 + 100));

  mainfontBold.fontSize = 12;
  _previous = Label::createWithTTF(mainfontBold, "Previous");
  _previous->setPosition(Vec2(100, 100));
}
