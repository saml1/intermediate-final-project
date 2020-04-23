#ifndef CHASEHERO_H
#define CHASEHERO_H

#include "entitycontroller.h"

class ChaseHero : public EntityController {
private:
  // disallow copy constructor and assignment operator
  ChaseHero(const ChaseHero &);
  ChaseHero &operator=(const ChaseHero &);

public:
  ChaseHero();
  virtual ~ChaseHero();

  virtual Direction getMoveDirection(Game *game, Entity *entity);
  virtual bool isUser() const;

private:
  // Add your own private member functions...
};

#endif // CHASEHERO_H
