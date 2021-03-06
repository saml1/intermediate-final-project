#include "basicgamerules.h"
#include "gamerules.h"
#include "maze.h"
#include "game.h"
#include "entity.h"

BasicGameRules::BasicGameRules() {

}

BasicGameRules::~BasicGameRules() {

}


bool BasicGameRules::allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const {
  if(source.distanceFrom(dest) > 1) { //Make sure move isnt more than 1 position
    return false;
  }
  /*
  if(actor->hasProperty('v')) {//Test if method is trying to push multiple entities at once
    if(game->getEntityAt(dest) == NULL) {
      return true;
    }
    else {
      return false;
    }
  }
  */
  Maze * maze = game->getMaze();
  const int width = maze->getWidth();
  const int height = maze->getHeight();
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
    
    if(!(eAtD->hasProperty('v') || (eAtD->hasProperty('h') && actor->hasProperty('m')) || (eAtD->hasProperty('m') && actor->hasProperty('h')))) {
      return false;
    }
    if(eAtD->hasProperty('v') && !allowMove(game, eAtD, dest, dest.displace(direct))) {
      return false;  
    }
    if(tileD->checkMoveOnto(actor, source, dest) == MoveResult::BLOCK) {
      return false;
    }
  }
  if(actor->hasProperty('v') && eAtD != NULL) {
    return false;
  }
  return true;
}

void BasicGameRules::enactMove(Game *game, Entity *actor, const Position &dest) const {
  
  const Position source = actor->getPosition();
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

  Entity * eAtD = game->getEntityAt(dest);
  EntityController * ec = actor->getController(); 
  if(eAtD == NULL) {
    actor->setPosition(dest);
  }
  else if(ec->isUser()){
    eAtD->setPosition(dest.displace(direct));
    actor->setPosition(dest);
  }
  else if(eAtD->hasProperty('v')) {
    eAtD->setPosition(dest.displace(direct));
    actor->setPosition(dest); 
  }
  else {
    actor->setPosition(dest);
  }
  
  // actor->setPosition(dest);
}

GameResult BasicGameRules::checkGameResult(Game *game) const {
  Maze * maze = game->getMaze();
  const std::vector<Entity *> heros = game->getEntitiesWithProperty('h');
  const std::vector<Entity *> evils = game->getEntitiesWithProperty('m');
  for(int i = 0; i < (int)heros.size(); i++) {
    const Position pos = heros[i]->getPosition();
    const Tile * tile = maze->getTile(pos);
    if(tile->isGoal()) {
      return GameResult::HERO_WINS;
    }
    for(int j = 0; j < (int)evils.size(); j++) {
      const Position temppos = evils[j]->getPosition();
      if(temppos == pos) {
	return GameResult::HERO_LOSES;
      }
    }
  }
  return GameResult::UNKNOWN;
}
