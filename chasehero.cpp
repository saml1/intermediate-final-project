#include "entitycontroller.h"
#include "chasehero.h"

ChaseHero::ChaseHero() {}

ChaseHero::~ChaseHero() {}

Direction ChaseHero::getMoveDirection(Game *game, Entity *entity) {

  // The section below determines which hero to chase
  // It is unfortunately reused code from AStarChaseHero
  // but I couldn't think of a simpler way to implement it

  std::vector<Entity *> heroVector = game->getEntitiesWithProperty('h');

  if (heroVector.empty()) return Direction::NONE;

  Entity * hero = heroVector.front();

  for (std::vector<Entity *>::iterator it = heroVector.begin(); it != heroVector.end(); ++it) {
    if ((*it)->getPosition().distanceFrom(start) < hero->getPosition().distanceFrom(start))
      hero = (*it);
  }

  // Determining which direction to move in

  Position start = entity->getPosition();

  Position goal = hero->getPosition();

  int horizontal = start.getX() - goal.getX();
  Direction hor = Direction::LEFT;
  if (horizontal < 0) {
    horizontal *= -1;
    hor = Direction::RIGHT;
  }
  
  int vertical = start.getY() - goal.getY();
  Direction ver = Direction::DOWN;
  if (vertical < 0) {
    vertical *= -1;
    ver = Direction::UP;
  }

  if (horizontal >= vertical) {
    step = start.displace(hor);
    if (maze.inBounds(step) && maze.getTile(step)->checkMoveOnto(entity, start, step))
      return hor;
    step = start.displace(ver);
    if (maze.inBounds(step) && maze.getTile(step)->checkMoveOnto(entity, start, step))
      return ver;
  }
  else {
    step = start.displace(ver);
    if (maze.inBounds(step) && maze.getTile(step)->checkMoveOnto(entity, start, step))
      return ver;
    step = start.displace(hor);
    if (maze.inBounds(step) && maze.getTile(step)->checkMoveOnto(entity, start, step))
      return hor;
  }

  return Direction::NONE;
}

bool ChaseHero::isUser() const {
  return false;
}
