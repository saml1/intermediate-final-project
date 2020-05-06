#include "astarchasehero.h"


AStarChaseHero::AStarChaseHero() {}

AStarChaseHero::~AStarChaseHero() {}


Direction AStarChaseHero::getMoveDirection(Game *game, Entity *entity) {

  // The section below determines which hero to chase

  Position start = entity->getPosition();
  
  std::vector<Entity *> heroVector = game->getEntitiesWithProperty('h');
  
  if (heroVector.empty()) return Direction::NONE;
  
  Entity * hero = heroVector.front();
  
  for (std::vector<Entity *>::const_iterator it = heroVector.begin(); it != heroVector.end(); ++it) {
    if ((*it)->getPosition().distanceFrom(start) < hero->getPosition().distanceFrom(start))
      hero = (*it);
  }

  // The section below sets up the necessary containers for the algorithm

  Position goal = hero->getPosition();

  Maze * maze = game->getMaze();
  
  std::vector<Position> openSet;
  openSet.push_back(start);
  
  std::map<Position, Position> cameFrom;

  std::map<Position, int> gScore;
  std::map<Position, bool> in_gScore;

  in_gScore[start] = true;
  gScore[start] = 0;
  
  std::map<Position, int> fScore;
  //std::map<Position, bool> in_fScore; // Not needed, as fScore and gScore will always have the same entries
  
  //in_fScore[start] = true;
  fScore[start] = start.distanceFrom(goal);

  // Loops until an optimal path is found or no feasible path is found

  const std::vector<Direction> directions {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
  
  while(!(openSet.empty())) {

    std::sort(openSet.begin(), openSet.end(), [&fScore](Position & a, Position & b) {return fScore[a] > fScore[b];});
    Position current = openSet.back();
    openSet.pop_back();

    // The if statement handles if the goal is reached by a path
    
    if (current == goal) {

      while (cameFrom[current] != start) current = cameFrom[current];

      if (current == start.displace(Direction::UP)) return Direction::UP;
      if (current == start.displace(Direction::DOWN)) return Direction::DOWN;
      if (current == start.displace(Direction::LEFT)) return Direction::LEFT;
      if (current == start.displace(Direction::RIGHT)) return Direction::RIGHT;
      return Direction::NONE; // should never be reached
    }
    
    // Considers all possible steps from current

    for (std::vector<Direction>::const_iterator it = directions.begin(); it != directions.end(); ++it) {

      Position neighbor = current.displace(*it);
      if (!(maze->inBounds(neighbor) && (maze->getTile(neighbor)->checkMoveOnto(entity, current, neighbor) == MoveResult::ALLOW))) continue;
      
      int tentative_gScore = gScore[current] + 1;

      // Handles if a new or better step is found
      
      if (!(in_gScore[neighbor]) || tentative_gScore < gScore[neighbor]) {
	cameFrom[neighbor] = current;
	gScore[neighbor] = tentative_gScore;
	fScore[neighbor] = gScore[neighbor] + neighbor.distanceFrom(goal);
	in_gScore[neighbor] = true;

	if (std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) openSet.push_back(neighbor);
      }
    }
  }

  // Returns if no path to the goal is found
  
  return Direction::NONE;
}

bool AStarChaseHero::isUser() const {
  return false;
}

