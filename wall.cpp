#include "wall.h"

Wall::Wall(){
  
}

Wall::~Wall(){

}

MoveResult Wall::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const{
  return MoveResult::BLOCK;
}

bool Wall::isGoal() const{
  return false;
}

std::string Wall::getGlyph() const{
  return "#";
}
