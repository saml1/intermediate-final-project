#include "basicgamerules.h"
#include "gamerules.h"

BasicGameRules::BasicGameRules() {}

BasicGameRules::~BasicGameRules() {}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) {
  return false;
}

void BasicGameRules::enactMove(Gmae *game, Entity *actor, const Position &dest) {
  return false;
}

GameResult BasicGameRules::checkGameResult(Game *game) {
  
}
