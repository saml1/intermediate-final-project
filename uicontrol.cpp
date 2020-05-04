#include "entitycontroller.h"
#include "uicontrol.h"
#include "ui.h"

UIControl::UIControl() {}

UIControl::~UIControl() {}

Direction UIControl::getMoveDirection(Game *game, Entity *entity) {
  UI *ui = UI::getInstance();
  if(game && entity) {
    return ui->getMoveDirection();
  }
  else {
    return ui->getMoveDirection();
  }
  
}

bool UIControl::isUser() const {
  return true;
}
