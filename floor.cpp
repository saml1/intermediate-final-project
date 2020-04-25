#include "floor.h"

Floor::Floor(){}

Floor::~Floor(){}

MoveResult Floor::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const{
  return MoveResult::ALLOW;
}

bool Floor::isGoal() const{
  return false;
}

std::string Floor::getGlyph() const{
  return ".";
}
