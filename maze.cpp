#include "maze.h"
#include "position.h"
#include <string>
#include <stdio.h>
#include <vector>
#include "tile.h"
#include "tilefactory.h"
Maze::Maze(int width, int height) : m_width(width), m_height(height){}

Maze::~Maze(){
  
}
/*
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
  char t = tile->Tile::getGlyph().at(0);
  //m_tiles[pos.getY()*getWidth() + pos.getX()] = TileFactory::createFromChar(t);
  m_tiles[pos.getY()*getWidth() + pos.getX()] = *tile;
}

// Get the Tile at the specified Position
const Tile Maze::*getTile(const Position &pos) const{
  return m_tiles[pos.getY()*getWidth() + pos.getX()];
}

// Read a description of a Maze from specified istream, and return it.
static Maze* Maze:: read(std::istream &in){
  std::string temp;
  int w;
  int h;
  std::getline(in, temp);
  sscanf(temp, "%d%d", &w, &h);
  Maze * newMaze = new Maze(w,h);
  //TODO: didn't finish this method! still need to add vector<tile> and other stuff
  return newMaze;
  
}
*/
