#include "textui.h"
#include <iostream>
#include "maze.h"
#include "game.h"

TextUI::TextUI() {}

TextUI::~TextUI() {}

Direction TextUI::getMoveDirection() {
  std::cout << "Your move (u/d/l/r): ";
  char move;
  std::cin >> move;
  switch(move) {
  case 'u':
    return Direction::UP;
    
  case 'd':
    return Direction::DOWN;
    
  case 'l':
    return Direction::LEFT;
    
  case 'r':
    return Direction::RIGHT;
    
  default:
    std::cout << "Unknown direction";
    return TextUI::getMoveDirection();
  }
  
}

void TextUI::displayMessage(const std::string &msg, bool endgame) {
  if(endgame) { //TextUI ignores endgame bool so message is recorded either way, if statement to avoid unsed variable warning
    m_msg = msg;
  }
  else {
    m_msg = msg;
  }
}

void TextUI::render(Game *game) {
  Maze * maze = game->getMaze();
  int width = maze->getWidth();
  int height = maze->getHeight();
  for(int i = 0; i < height-1; i++) {
    for(int j = 0; j < width-1; j++) {
      Position * pos = new Position(j, i);
      if(game->getEntityAt(*pos) == NULL) {
	const Tile * tile = maze->getTile(*pos);
	std::cout << tile->getGlyph();
      }
      else {
	Entity * entity = game->getEntityAt(*pos);
	std::cout << entity->getGlyph();
      }
    }
    std::cout << "" << std::endl;
  }
  //Check for outgoing message
  if(m_msg.compare("") != 0) {
    std::cout << m_msg << std::endl;
    m_msg = "";
  }
}
