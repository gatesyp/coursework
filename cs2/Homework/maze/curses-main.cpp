
#include "maze.hpp"
#include "generate.hpp"
#include "search.hpp"
#include "bfs.hpp"
#include "dfs.hpp"
#include "curses.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include <ncurses.h>  // FIXME: Remove me.


constexpr auto E = Tile::Empty;
constexpr auto W = Tile::Wall;
constexpr auto X = Tile::Exit;


// Control flags.
enum Flags
{
  Exec_bfs = 0x01,
  Exec_dfs = 0x02,
  Exec_both = Exec_bfs | Exec_dfs
};


int 
main(int argc, char** argv)
{
  std::srand(std::time(0));

  Flags exec = Exec_both;
  if (argc == 2) {
    std::string a = argv[1];
    if (a == "bfs")
      exec = Exec_bfs; 
    if (a == "dfs")
      exec = Exec_dfs; 
  }

  // Curses resources.
  Curses curses;

  // Visitor config.
  Curses_visitor cvis;
  Headless_visitor hvis;
  Visitor& vis = cvis;


  // Maze m(10, 10);
  Maze m(40, 80);
  generate(m, vis);
  vis.draw(m);

  // FIXME: This is curses only.
  printw("\n\npress any key to start");
  getch();
  clear();

  /*
  Maze m {
    {E,E,E,E,E,E,E,E,E},
    {W,W,W,E,E,E,E,E,E},
    {E,E,E,W,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,E},
    {E,E,E,E,E,E,E,E,X},
  };
  */

  if (exec & Exec_bfs) {
    if (bfs(m, vis))
      printw("\n\nsolved!");
    else
      printw("\n\nno solution");
    getch();
  }

  if (exec & Exec_dfs) {
    if (dfs(m, vis))
      printw("\n\nsolved!");
    else
      printw("\n\nno solution");
    getch();
  }
}
