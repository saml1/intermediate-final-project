#include "entitycontroller.h"
#include "uicontrol.h"

UIControl::UIControl() {}

UIControl::~UIControl() {}

Direction UIControl::getMoveDirection(Game *game, Entity *entity) {
  return Direction::NONE; //Stub
}

bool UIControl::isUser() const {
  return true;
}
