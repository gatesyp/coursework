
#ifndef CURSES_HPP
#define CURSES_HPP

#include "visitor.hpp"


struct Curses
{
  Curses();
  ~Curses();
};


struct Curses_visitor : Visitor
{
  void         draw(Tile, int, int);
  virtual void draw(Maze const&);
  virtual void draw(Maze const&, Color_table const&);
};


#endif
