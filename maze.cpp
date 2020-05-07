#include "maze.h"
#include "position.h"
#include <string>
#include <stdio.h>
#include <vector>
#include "tile.h"
#include "tilefactory.h"
Maze::Maze(int width, int height) : m_width(width), m_height(height){}

Maze::~Maze(){
  delete(m_width);
  delete(m_height);
  delete(&m_tiles);
}

// Get the width of the Maze
int Maze:: getWidth() const{
  return m_width;
}

// Get the height of the Maze
int Maze:: getHeight() const{
  return m_height;
}

// Return true if the specified position is in position
// according to the Maze's width and height.
bool Maze:: inBounds(const Position &pos) const{
  return pos.inBounds(getWidth(), getHeight());
}

// Set a Tile at the specified Position.  The Maze assumes responsibility
// for deleting the tile.
void Maze:: setTile(const Position &pos, Tile *tile){
  //m_tiles[pos.getY()*getWidth() + pos.getX()]= tile;
  //m_tiles[0] = tile;
  m_tiles.push_back(nullptr);
  m_tiles[pos.getY()*getWidth() + pos.getX()] = tile;
}

// Get the Tile at the specified Position
const Tile* Maze:: getTile(const Position &pos)const{
  return m_tiles[pos.getY()*getWidth() + pos.getX()];
}

// Read a description of a Maze from specified istream, and return it.
Maze* Maze:: read(std::istream &in){
  /*std::string temp;
  int w;
  int h;
  std::getline(in, temp);
  sscanf(temp, "%d%d", &w, &h);*/
  int width;
  int height;
  if (!(in >> width)) return nullptr;
  if (!(in >> height)) return nullptr;
  Maze * newMaze = new Maze(width,height);
  char ch;
  //in >> ch;
  TileFactory * tf = TileFactory::getInstance();
  int count = 0;
  while(in >> ch){
    Tile* temp = tf->createFromChar(ch);
    if(temp == nullptr){
      return nullptr;
    }
    (newMaze->m_tiles).push_back(temp);
    //(newMaze->m_tiles)[count] = temp;
    count++;
    if(count == width * height) {
      char test = in.peek();
      Tile * tile = tf->createFromChar(test);
      if(tile != nullptr) {
	return nullptr;
      }
      break;
    }
  }
  if(count != width*height){
    return nullptr;
  }
  return newMaze;
  
}

int Maze::posToIndex(const Position &pos){
  return pos.getY()*getWidth() + pos.getX();
}
