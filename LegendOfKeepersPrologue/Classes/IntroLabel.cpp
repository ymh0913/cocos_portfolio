#include "IntroLabel.h"

IntroLabel::IntroLabel() {
  TTFConfig mainfontBold("FONT/Mainfont-Bold.ttf", 36);
  TTFConfig mainfontLight("FONT/Mainfont-Light.ttf", 36);
  TTFConfig mainfontRegular("FONT/Mainfont-Regular.ttf", 36);
  TTFConfig mainfontSemibold("FONT/Mainfont-Semibold.ttf", 36);
  TTFConfig RobotoRegular("FONT/Roboto-Regular.ttf", 36);

  _play = Label::createWithTTF(mainfontBold, "Play");
  _play->setPosition(Vec2(960, 540));

  _settings = Label::createWithTTF(mainfontRegular, "Settings");
  _settings->setPosition(Vec2(960, 450));

  _modding = Label::createWithTTF(mainfontLight, "Modding");
  _modding->setPosition(Vec2(960, 360));

  _credits= Label::createWithTTF(mainfontSemibold, "Credits");
  _credits->setPosition(Vec2(960, 270));

  _quit= Label::createWithTTF(RobotoRegular, "Quit");
  _quit->setPosition(Vec2(960, 180));

  mainfontBold.fontSize = 18;
  _v0602 = Label::createWithTTF(mainfontBold, "v0.6.0.2");
  _v0602->setPosition(Vec2(50, 100));
}
