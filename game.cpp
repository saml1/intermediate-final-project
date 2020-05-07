#include "game.h"
#include "maze.h"
#include "ui.h"
#include "position.h"
#include "entity.h"
#include "gamerules.h"
#include "gamerules.h"
#include "ecfactory.h"
#include "entitycontroller.h"
#include <iostream>


typedef std::vector<Entity *> EntityVec;

Game::Game(){
  //m_ui = nullptr;
  //m_gameRules = nullptr;
}

Game::~Game(){
  /*
  delete(m_maze);
  delete(m_ui);
  delete(m_gameRules);
  delete(&m_entities);
  */
}

// Set the Maze object. The Game object assumes responsibility for deleting it.
void Game::setMaze(Maze *maze){
  m_maze = maze;
}

// Set the UI object. The Game object assumes responsibility for deleting it.
void Game::setUI(UI *ui){
  if(ui != nullptr){m_ui = ui;};
}

// Set the GameRules object. The Game object assumes responsibility for deleting it.
void Game::setGameRules(GameRules *gameRules){
  if(gameRules != nullptr){m_gameRules = gameRules;}
}

// Add an Entity to the sequence of entities. The Game object assumes
// responsibility for deleting it.
void Game::addEntity(Entity *entity){
  m_entities.push_back(entity);
}

// Get the Entity at the specified Position.  Return nullptr if
// there is no Entity at the specified Position.
Entity * Game::getEntityAt(const Position &pos){
  for(int i = 0; i < (int)m_entities.size(); i++){
    if(m_entities[i]->getPosition() == pos){
      return m_entities[i];
    }
  }
  return nullptr;
}

// Get a const reference to the Game object's internal vector
// of pointers to Entity objects
const EntityVec& Game::getEntities() const{
  return m_entities;
}

// Get a vector of pointers to Entity objects that have the                                                
// specified property. The vector could be empty if no Entity objects
// have the specified property.                                                                            
std::vector<Entity *> Game::getEntitiesWithProperty(char prop) const{
  std::vector<Entity*> ev;
  for(int i = 0; i < (int)m_entities.size(); i++){
    if(m_entities[i]->hasProperty(prop)){
      ev.push_back(m_entities[i]);
    }
  }
  return ev;
}

// Get the Maze object.                                                                                    
Maze * Game::getMaze(){
  return m_maze;
}

// Get the UI object.                                                                                      
UI * Game::getUI(){
  return m_ui;
}

// Get the GameRules object.                                                                               
GameRules * Game::getGameRules(){
  return m_gameRules;
}

// Let the Entity objects take turns in round-robin fashion until                                          
// the GameRules object determines that the hero has won or lost.                                          
// Should call the render member function on the UI object just before                                     
// an Entity whose EntityController is controlled by the user takes                                        
// a turn.                                                                                                 
void Game::gameLoop(){
  int size = (int)m_entities.size();
  int cur = 0;
  while(m_gameRules->checkGameResult(this) == GameResult::UNKNOWN){
    if(m_entities[cur]->getController()->isUser()){
      m_ui->render(this);
    }
    takeTurn(m_entities[cur]);
    if(cur + 1 == size){
      cur = 0;
    }
    else {
      cur++;
    }
  }
  if(m_gameRules->checkGameResult(this) == GameResult::HERO_WINS){
    m_ui->displayMessage("Hero wins");
    m_ui->render(this);
  }else{
    m_ui->displayMessage("Hero loses");
    m_ui->render(this);
  }
}

// Let specified actor Entity take a turn.                                                                 
// This is public so that it can be called from                                                            
// unit tests.  It is mainly intended to be called from                                                    
// the gameLoop member function.                                                                           
void Game::takeTurn(Entity *actor){
  EntityController * ec = actor->getController();
  Direction dir = ec->getMoveDirection(this, actor);
  Position dest = (actor->getPosition()).displace(dir);
  if(m_gameRules->allowMove(this, actor, actor->getPosition(),dest)){
    m_gameRules->enactMove(this, actor, dest);
  }
  else if(ec->isUser() && !(m_gameRules->allowMove(this, actor, actor->getPosition(), dest))){
    m_ui->displayMessage("Illegal move");
  }
  /*if(ec->isUser() && !(m_gameRules->allowMove(this, actor, actor->getPosition(), (actor->getPosition()).displace(dir)))){
    m_ui->displayMessage("Illegal Move");
    }
  else if(m_gameRules->allowMove(this, actor, actor->getPosition(), (actor->getPosition()).displace(dir))){
  m_gameRules->enactMove(this, actor, (actor->getPosition()).displace(dir));
    }*/
}

// Read initial Game data from the specified istream, and return                                           
// the resulting Game object.                                                                              
Game * Game::loadGame(std::istream &in){
  /*
  //first set maze data
  Game * g = new Game();
  Maze * m = Maze::read(in);
  g->setMaze(m);
  //then read istream but skip over maze data
  char temp;
  in >> temp;
  while(in >> temp){
    if(temp != '#'){
      break;
    }
  }
  */
  Game * g = new Game();
  Maze * m = Maze::read(in);
  if(m == NULL) {
    return NULL;
  }
  g->setMaze(m);
  //then read istream but skip over maze data
  char temp;
  EntityController * controller;
  Entity * e;
  EntityControllerFactory * ecfactory = EntityControllerFactory::getInstance();
  while(in >> temp){
    if(temp == '#' || temp == '.' || temp == '<'){ //Skip over maze data
      return NULL;
    }
    
    try { //If not maze data process first entity
      e = new Entity();
      char glyph = temp;//Store glpyh for later
      std::string test;
      test.push_back(glyph);
      e->setGlyph(test);
      in >> temp;
      controller = ecfactory->createFromChar(temp); //Create entity from temp char
      std::string properties; //Read the remaining properties and add them to entity
      in >> properties;
      e->setProperties(properties);
      int x = 0;
      int y = 0;
      in >> x;
      in >> y;
      Position *pos = new Position(x, y); //Create position from x and y cords
      e->setPosition(*pos); //Apply remaining attributes to entity
      e->setController(controller);
      g->addEntity(e); //Add entity to the game
    }
    catch (int e) {
      return NULL;
    }
  }

  return g;
}
