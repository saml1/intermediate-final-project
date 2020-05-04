#include "inanimate.h"
#include "entitycontroller.h"

Inanimate::Inanimate() {}

Inanimate::~Inanimate() {}

Direction Inanimate::getMoveDirection(Game *game, Entity *entity) {
  return Direction::NONE; //Stub
}

bool Inanimate::isUser() const {
  return false;
}
