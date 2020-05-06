#include "inanimate.h"
#include "entitycontroller.h"

Inanimate::Inanimate() {}

Inanimate::~Inanimate() {}

Direction Inanimate::getMoveDirection(Game *, Entity *) { // saw on SO that apparently this works to remove unused parameter warnings, guess we'll find out
  return Direction::NONE; // yep it does, that's pretty cool. I'll remember that
}

bool Inanimate::isUser() const {
  return false;
}
