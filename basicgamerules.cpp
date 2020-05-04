#include "basicgamerules.h"
#include "gamerules.h"
#include "maze.h"

BasicGameRules::BasicGameRules() {}

BasicGameRules::~BasicGameRules() {}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  if(source.distanceFrom(dest) > 1) { //Make sure move isnt more than 1 position
    return false;
  }
  Maze * maze = game->getMaze();
  int width = maze->getWidth();
  int height = maze->getHeight();
  if(!dest.inBounds(width, height)) {
    return false;
  }
  
  Entity * eAtD = game->getEntityAt(dest);
  const Tile * tileD = maze->getTile(dest);
  if(eAtD == NULL) { //Check is there is an entity
    if(tileD->checkMoveOnto(actor, source, dest) == MoveResult::BLOCK) {
      return false;
    }
  }
  else {
    Direction direct;
    if(source.displace(Direction::UP) == dest) {
      direct = Direction::UP;
    }
    if(source.displace(Direction::DOWN) == dest) {
      direct = Direction::DOWN;
    }
    if(source.displace(Direction::LEFT) == dest) {
      direct = Direction::LEFT;
    }
    if(source.displace(Direction::RIGHT) == dest) {
      direct = Direction::RIGHT;
    }
    
    if(!eAtD->hasProperty('v')) {
      return false;
    }
    if(!allowMove(game, eAtD, dest, dest.displace(direct))) {
      return false;  
    }
  }
  return true;
}

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  
}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  return GameResult::UNKNOWN; //Stub
}
