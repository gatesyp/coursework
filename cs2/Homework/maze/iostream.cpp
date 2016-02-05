
#include "iostream.hpp"

#include <iostream>


void
Ostream_visitor::draw(Tile t)
{
  if (t.is_wall())
    std::cout << '#';
  else if (t.is_exit())
    std::cout << '@';
  else
    std::cout << ' ';
}


void
Ostream_visitor::draw(Maze const& maze)
{
  for (int r = 0; r < maze.rows(); ++r) {
    for (int c = 0; c < maze.cols(); ++c)
      draw(maze(r, c));
    std::cout << '\n';
  }
  std::cin.get();
}


void
Ostream_visitor::draw(Maze const& maze, Color_table const& colors)
{
  for (int r = 0; r < maze.rows(); ++r) {
    for (int c = 0; c < maze.cols(); ++c) {
      switch (colors(r, c)) {
        case White: draw(maze(r, c)); break;
        case Gray: std::cout << '?'; break;
        case Black: std::cout << '*'; break;
      }
    }
    std::cout << '\n';
  }
  std::cin.get();
}
