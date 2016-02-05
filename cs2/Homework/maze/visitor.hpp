
#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "maze.hpp"
#include "search.hpp"


// A render visitor is used to render the maze or
// the search state during processing.
struct Visitor
{
  virtual void draw(Maze const&) = 0;
  virtual void draw(Maze const&, Color_table const&) = 0;
};


// The headless render visitor does not draw the maze
// or search states.
struct Headless_visitor : Visitor
{
  void draw(Maze const&) override { }
  void draw(Maze const&, Color_table const&) override { }
};

#endif
