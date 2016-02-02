
#ifndef IOSTREAM_HPP
#define IOSTREAM_HPP

#include "visitor.hpp"


struct Ostream_visitor : Visitor
{
  void         draw(Tile);
  virtual void draw(Maze const&);
  virtual void draw(Maze const&, Color_table const&);
};


#endif
