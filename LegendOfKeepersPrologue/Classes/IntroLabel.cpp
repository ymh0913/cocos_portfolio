#include "IntroLabel.h"

IntroLabel::IntroLabel() {
  TTFConfig mainfontBold("FONT/Mainfont-Bold.ttf", 18);
  TTFConfig mainfontLight("FONT/Mainfont-Light.ttf", 18);
  TTFConfig mainfontRegular("FONT/Mainfont-Regular.ttf", 18);
  TTFConfig mainfontSemibold("FONT/Mainfont-Semibold.ttf", 18);
  TTFConfig RobotoRegular("FONT/Roboto-Regular.ttf", 18);

  _play = Label::createWithTTF(mainfontBold, "Play");
  _play->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 50));

  _settings = Label::createWithTTF(mainfontRegular, "Settings");
  _settings->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 100));

  _modding = Label::createWithTTF(mainfontLight, "Modding");
  _modding->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 150));

  _credits = Label::createWithTTF(mainfontSemibold, "Credits");
  _credits->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 200));

  _quit = Label::createWithTTF(RobotoRegular, "Quit");
  _quit->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 250));

  mainfontBold.fontSize = 12;
  _v0602 = Label::createWithTTF(mainfontBold, "v0.6.0.2");
  _v0602->setPosition(Vec2(50, 100));

  mainfontBold.fontSize = 18;
  _back = Label::createWithTTF(mainfontBold, "Back");
  _back->setPosition(Vec2(480, 100));

  _delete = Label::createWithTTF(mainfontBold, "Delete");
  _delete->setPosition(Vec2(VISIBLESIZE.width / 2, 100));

  _create = Label::createWithTTF(mainfontBold, "Create");
  _create->setPosition(Vec2(800, 100));

  _saveName = nullptr;
  _titleSaveTop = Label::createWithTTF("New Save", "FONT/Mainfont-Regular.ttf", 20, Size(100, 50));
  _titleSaveTop->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 50));

  _titleSaveMiddle = Label::createWithTTF("New Save", "FONT/Mainfont-Regular.ttf", 20, Size(100, 50));
  _titleSaveMiddle->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 70));

  _titleSaveBottom = Label::createWithTTF("New Save", "FONT/Mainfont-Regular.ttf", 20, Size(100, 50));
  _titleSaveBottom->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 - 190));

  _tutorial = Label::createWithTTF(mainfontBold, "Do you want to launch the tutorial?");
  _tutorial->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 2 + 25));

  _no = Label::createWithTTF(mainfontBold, "No");
  _no->setPosition(Vec2(VISIBLESIZE.width / 2 - 70, VISIBLESIZE.height / 2 - 20));

  _yes = Label::createWithTTF(mainfontBold, "Yes");
  _yes->setPosition(Vec2(VISIBLESIZE.width / 2 + 70, VISIBLESIZE.height / 2 - 20));
}
