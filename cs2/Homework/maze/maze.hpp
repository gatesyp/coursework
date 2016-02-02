
#ifndef MAZE_HPP
#define MAZE_HPP

#include "table.hpp"

#include <unistd.h>
#include <iostream>


// Represents the kind of tile in a maze. There
// are three kinds of tiles: empty,
struct Tile
{
  enum Kind {
    Empty, // An empty tile can be traversed
    Wall,  // A wall cannot be traversed
    Exit,  // An exit for the maze
  };

  // Tiles are empty by default.
  Tile() : kind(Empty) { }

  // Initialize the tile with the given kind.
  Tile(Kind k) : kind(k) { }

  bool is_wall() const { return kind == Wall; }
  bool is_exit() const { return kind == Exit; }
  bool is_open() const { return kind == Empty || kind == Exit; }

  // Set the kind of tile.
  Tile& operator=(Kind k) { kind = k; return *this; }

  Kind kind;
};


// Support equality comparison between tiles and their
// kinds. Do this because we support assignment to
// kinds of tiles.
inline bool
operator==(Tile t, Tile::Kind k) { return t.kind == k; }

inline bool
operator!=(Tile::Kind k, Tile t) { return t.kind != k; }

inline bool
operator==(Tile::Kind k, Tile t) { return t.kind == k; }

inline bool
operator!=(Tile t, Tile::Kind k) { return t.kind != k; }


// FIXME: Put this somewhere else.
inline std::ostream&
operator<<(std::ostream& os, Tile t)
{
  if (t.is_wall())
    return os << '#';
  if (t.is_exit())
    return os << '@';
  else
    return os << '.';
}




// Represents a point on the grid, given as a row and
// column offsets. An interface for accessing neighbor
// locations is also provided. Note that there is no
// guarantee that neighbors are actually valid. This
// must be checked separately.
struct Location : Index
{
  Location(int r, int c)
    : Index{r, c}
  { }

  Location north() const { return {r - 1, c}; }
  Location south() const { return {r + 1, c}; }
  Location east() const { return {r, c + 1}; }
  Location west() const { return {r, c - 1}; }
};



// A maze is simply a table of tiles along with
// a handful of functions to support various
// queries and
struct Maze : Table<Tile>
{
  // Import constructors.
  using Table<Tile>::Table;

  // Import operators [] and ().
  using Table<Tile>::operator[];
  using Table<Tile>::operator();

  bool is_valid(Location) const;
  bool is_wall(Location) const;
  bool is_open(Location) const;

  void print(std::ostream&) const;
};



// Returns true if the location is within the
// bounds of the maze.
inline bool
Maze::is_valid(Location loc) const
{
  if (0 <= loc.r && loc.r < rows())
    if (0 <= loc.c && loc.c < cols())
      return true;
  return false;
}


// Returns true if the location is occupied
// by a wall.
inline bool
Maze::is_wall(Location loc) const
{
  return (*this)(loc).is_wall();
}


// Returns true if the given location is unoccupied.
// This is the case when the location is not a wall.
inline bool
Maze::is_open(Location loc) const
{
  return (*this)(loc).is_open();
}


// Print the maze.
inline void
Maze::print(std::ostream& os) const
{
  for (int r = 0; r < rows(); ++r) {
    for (int c = 0; c < cols(); ++c)
      os << (*this)(r, c);
    os << '\n';
  }
}


#endif
