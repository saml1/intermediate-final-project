#include "entity.h"
#include "entitycontroller.h"

Entity::Entity(){}

Entity::~Entity(){
  delete(m_pos);
  delete(m_controller);
  delete(m_glyph);
  delete(m_properties);
}

// Set the glyph that will represent this Entity.
// Should consist of a single character.
void Entity::setGlyph(const std::string &glyph){
  m_glyph = glyph;
}

// Set the properties of this Entity.  Each character in the
// string represents a single property. 
void Entity::setProperties(const std::string &props){
  m_properties = props;
}

// Get the glyph representing this Entity.
std::string Entity::getGlyph() const{
  return m_glyph;
}

// Get the string containing this Entity's properties.
std::string Entity::getProperties() const{
  return m_properties;
}

// Return true if the Entity's properties contain the specified  
// character, false otherwise. 
bool Entity::hasProperty(char prop) const{
  for(int i = 0; i < (int)getProperties().length(); i++){
    if(getProperties()[i] == prop){
      return true;
    }
  }
  return false;
}

// Set this Entity's EntityController, which will determine how it moves.
// The Entity assumes responsibility for deleting it.
void Entity::setController(EntityController *controller){
  m_controller = controller;
}

// Get this Entity's EntityController.  
EntityController * Entity::getController(){
  return m_controller;
}

// Set this Entity's Position.     
void Entity::setPosition(const Position &pos){
  m_pos = pos;
}

// Return this Entity's Position.   
Position Entity::getPosition() const{
  return m_pos;
}
