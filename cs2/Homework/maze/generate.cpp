
#include "generate.hpp"

#include <cstdlib>


// -------------------------------------------------------------------------- //
// Geometry classes

struct Point
{
  Point(int x, int y)
    : x(x), y(y)
  { }

  int x, y;
};


struct Rect
{
  Rect(Point tl, Point br)
    : tl(tl), br(br)
  {
    assert(width() >= 0);
    assert(height() >= 0);
  }

  int top() const    { return tl.y; }
  int bottom() const { return br.y; }
  int left() const   { return tl.x; }
  int right() const  { return br.x; }

  int height() const { return bottom() - top(); }
  int width() const { return right() - left(); }

  bool is_wider() const { return width() > height(); }
  bool is_taller() const { return height() > width(); }

  Point tl;
  Point br;
};


inline std::ostream&
operator<<(std::ostream& os, Point p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

inline std::ostream&
operator<<(std::ostream& os, Rect r)
{
  return os << '[' << r.tl << ' ' << r.br << ']';
}


// -------------------------------------------------------------------------- //
// Random number generation

// Return a random number in [0, n).
inline int
rand(int n)
{
  return rand() % n;
}


inline bool
flip()
{
  return rand(2) == 0;
}


// -------------------------------------------------------------------------- //
// Recursive division

void divide_vertical(Maze& m, Rect r, Visitor&);
void divide_horizontal(Maze& m, Rect r, Visitor&);


// The minimum size of the room we can generate.
constexpr int min_room = 4;

// The maximum size of gap between rooms.
constexpr int gap_size = 3;


void
divide(Maze& m, Rect r, Visitor& vis)
{
  // Base case.
  if ((r.width() < min_room) || (r.height() < min_room))
    return;

  // Draw the meze in each step.
  vis.draw(m);

  // If the current room is taller or wider,
  // split in the opposite direction.
  //
  // Otherwise, if the dimensions are the same
  // choose randomly.
  if (r.is_wider())
    return divide_vertical(m, r, vis);
  if (r.is_taller())
    return divide_horizontal(m, r, vis);
  if (flip())
    return divide_vertical(m, r, vis);
  else
    return divide_horizontal(m, r, vis);
}


void
divide_vertical(Maze& m, Rect r, Visitor& vis)
{
  // Pick the position of the wall.
  int x = rand(r.width() - 2) + 1 + r.left();

  // Pick the starting point and ending point
  // for the gap in the wall.
  int g1 = rand(r.height() - 1);
  int g2 = g1 + std::min(gap_size, r.height() - g1 - 1);

  // Draw the wall.
  for (int i = 0; i < g1; ++i)
    m(i + r.top(), x) = Tile::Wall;
  for (int i = g2; i < r.height(); ++i)
    m(i + r.top(), x) = Tile::Wall;

  Rect left(r.tl, {x, r.bottom()});
  Rect right({x + 1, r.top()}, r.br);

  divide(m, left, vis);
  divide(m, right, vis);
}


void
divide_horizontal(Maze& m, Rect r, Visitor& vis)
{
  // Pick the position of the wall.
  int y = rand(r.height() - 2) + 1 + r.top();

  // Pick the starting point and ending point
  // for the gap in the wall.
  int g1 = rand(r.width() - 1);
  int g2 = g1 + std::min(gap_size, r.width() - g1 - 1);

  // Draw the wall.
  for (int i = 0; i < g1; ++i)
    m(y, i + r.left()) = Tile::Wall;
  for (int i = g2; i < r.width(); ++i)
    m(y, i + r.left()) = Tile::Wall;

  Rect top(r.tl, {r.right(), y});
  Rect bottom({r.left(), y + 1}, r.br);

  divide(m, top, vis);
  divide(m, bottom, vis);
}


// -------------------------------------------------------------------------- //
// Maze generation

void
generate(Maze& m, Visitor& vis)
{
  int x = m.cols();
  int y = m.rows();
  Rect r({0, 0}, {x, y});
  divide(m, r, vis);

  // Put the exit on the maze.
  //
  // TODO: This could be better.
  m(y - 1, x - 1) = Tile::Exit;

  // Draw the final maze.
  vis.draw(m);
}
