#include "basicgamerules.h"
#include "gamerules.h"

BasicGameRules::BasicGameRules() {}

BasicGameRules::~BasicGameRules() {}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  return false;
}

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  
}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  return GameResult::UNKNOWN; //Stub
}
