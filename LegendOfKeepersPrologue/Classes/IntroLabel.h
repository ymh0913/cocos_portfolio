#ifndef __INTRO_LABEL_H__
#define __INTRO_LABEL_H__

#include "framework.h"

class IntroLabel
{
 public:
  IntroLabel();
  Label* getPlay() { return _play; }
  Label* getSettings() { return _settings; }
  Label* getModding() { return _modding; }
  Label* getCredits() { return _credits; }
  Label* getQuit() { return _quit; }
  Label* getV0602() { return _v0602; }
  Label* getBack() { return _back; }
  Label* getDelete() { return _delete; }
  Label* getCreate() { return _create; }
  Label* getTitleSaveTop() { return _titleSaveTop; }
  Label* getTitleSaveMiddle() { return _titleSaveMiddle; }
  Label* getTitleSaveBottom() { return _titleSaveBottom; }
  void setSaveName(const String* tmp) { _saveName = tmp; }
  const String* getSaveName() { return _saveName; }
  Label* getTutorial() { return _tutorial; }
  Label* getNo() { return _no; }
  Label* getYes() { return _yes; }
 private:
  Label* _play;
  Label* _settings;
  Label* _modding;
  Label* _credits;
  Label* _quit;
  Label* _v0602;
  Label* _back;
  Label* _delete;
  Label* _create;
  Label* _titleSaveTop;
  Label* _titleSaveMiddle;
  Label* _titleSaveBottom;
  const String* _saveName;
  Label* _tutorial;
  Label* _no;
  Label* _yes;
};

#endif // __INTRO_LABEL_H__
