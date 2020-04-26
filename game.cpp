#include "game.h"
#include "maze.h"
#include "ui.h"
#include "position.h"
#include "entity.h"
#include "gamerules.h"

Game::Game(){}

Game::~Game(){}

// Set the Maze object. The Game object assumes responsibility for deleting it.
void Game::setMaze(Maze *maze){
  m_maze = maze;
}

// Set the UI object. The Game object assumes responsibility for deleting it.
void setUI(UI *ui){
  m_ui = ui;
}

// Set the GameRules object. The Game object assumes responsibility for deleting it.
void setGameRules(GameRules *gameRules){
  m_gameRules = gameRules;
}

// Add an Entity to the sequence of entities. The Game object assumes
// responsibility for deleting it.
void addEntity(Entity *entity){
  m_entities.push_back(entity);
}

// Get the Entity at the specified Position.  Return nullptr if
// there is no Entity at the specified Position.
Entity *getEntityAt(const Position &pos){
  for(int i = 0; i < m_entities.size(); i++){
    if(m_entities[i]->getPosition() == pos){
      return m_entities[i];
    }
  }
  return nullptr;
}

// Get a const reference to the Game object's internal vector
// of pointers to Entity objects
const EntityVec &getEntities() const{
  return m_entities;
}

// Get a vector of pointers to Entity objects that have the                                                
// specified property. The vector could be empty if no Entity objects
// have the specified property.                                                                            
std::vector<Entity *> getEntitiesWithProperty(char prop) const{
  vector<Entity*> ev;
  for(int i = 0; i < m_entities.size(); i++){
    if(m_entities[i]->hasProperty(prop)){
      ev.push_back(m_entities[i]);
    }
  }
  return ev;
}

// Get the Maze object.                                                                                    
Maze *getMaze(){
  return m_maze;
}

// Get the UI object.                                                                                      
UI *getUI(){
  return m_ui;
}

// Get the GameRules object.                                                                               
GameRules *getGameRules(){
  return m_gameRules;
}

// Let the Entity objects take turns in round-robin fashion until                                          
// the GameRules object determines that the hero has won or lost.                                          
// Should call the render member function on the UI object just before                                     
// an Entity whose EntityController is controlled by the user takes                                        
// a turn.                                                                                                 
void gameLoop(){
  
}

// Let specified actor Entity take a turn.                                                                 
// This is public so that it can be called from                                                            
// unit tests.  It is mainly intended to be called from                                                    
// the gameLoop member function.                                                                           
void takeTurn(Entity *actor);

// Read initial Game data from the specified istream, and return                                           
// the resulting Game object.                                                                              
static Game *loadGame(std::istream &in);
