#include "entitycontroller.h"
#include "astarchasehero.h"

AStarChaseHero::AStarChaseHero() {}

AStarChaseHero::~AStarChaseHero() {}


Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {
  return Direction::NONE; //Stub
}

bool AStarChaseHero::isUser() const {
  return false;
}
