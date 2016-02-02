
#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "maze.hpp"
#include "queue.hpp"

#include <algorithm>
#include <iostream>


// Represents whether or not we've visited or will visit
// a particular tile in a maze.
enum Color
{
  White,  // Unexplored.
  Gray,   // To be explored.
  Black,  // Explored.
};


// The color table is used to store visitation information
// during the search. When default initialized, all color
// will be White.
using Color_table = Table<Color>;


// An index table is used to support the construction of
// a search tree. Each element in this table is an index
// that refers to the the parent in the search tree.
using Index_table = Table<Index>;


// A symbol constant used to slow down animations.
constexpr int sleep_duration = 5000;



#endif
