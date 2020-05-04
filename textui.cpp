#include "textui.h"
#include <iostream>


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
  if(endgame) {
    m_msg = msg;
  }
  else {
    m_msg = msg;
  }
}

void TextUI::render(Game *game) {
  
}
