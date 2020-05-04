#include "entitycontroller.h"
#include "chasehero.h"

ChaseHero::ChaseHero() {}

ChaseHero::~ChaseHero() {}

Direction ChaseHero::getMoveDirection(Game *game, Entity *entity) {
  return Direction::NONE; //Stub
}

bool ChaseHero::isUser() const {
  return false;
}
