
#include "curses.hpp"

#include <ncurses.h>


Curses::Curses()
{
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
}


Curses::~Curses()
{
  endwin();
}


void
Curses_visitor::draw(Tile t, int r, int c)
{
  if (t.is_wall())
    mvaddch(r, c, '#' | COLOR_PAIR(1) | A_BOLD);
  else if (t.is_exit())
    mvaddch(r, c, '@' | COLOR_PAIR(3) | A_BOLD);
  else
    mvaddch(r, c, ' ');
}


void
Curses_visitor::draw(Maze const& maze)
{
  for (int r = 0; r < maze.rows(); ++r)
    for (int c = 0; c < maze.cols(); ++c)
      draw(maze(r, c), r, c);
  refresh();
  usleep(sleep_duration);
  // getch();
}


void
Curses_visitor::draw(Maze const& maze, Color_table const& colors)
{
  for (int r = 0; r < maze.rows(); ++r) {
    for (int c = 0; c < maze.cols(); ++c) {
      switch (colors(r, c)) {
        case White: draw(maze(r, c), r, c); break;
        case Gray: mvaddch(r, c, '?' | COLOR_PAIR(2)); break;
        case Black: mvaddch(r, c, '*' | COLOR_PAIR(3)); break;
      }
    }
  }
  refresh();
  usleep(sleep_duration);
  // getch();
}
