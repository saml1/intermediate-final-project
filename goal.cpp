#include "goal.h"

Goal::Goal(){}

Goal::~Goal(){}

MoveResult Goal::checkMoveOnto(Entity *entity, const Position &fromPos, const Position &tilePos) const{
  return MoveResult::ALLOW;
}

bool Goal::isGoal() const{
  return true;
}

std::string Goal::getGlyph() const{
  return "<";
}
