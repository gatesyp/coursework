/********************************************************************
  * Lab 1: color.hpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose:Provide the functions to actuallyperform the translation between str  * ing argument to its hexadecimal or decimal representation
  *
  ********************************************************************/

#ifndef COLOR_HPP
#define COLOR_HPP

struct Color{
  int R, G, B;

  Color() :R(0), G(0), B(0)
  {}
  
  Color(int x, int y, int z)
    :R(x), G(y), B(z)
  {}
};

int lookup(int argc, char* argv[], bool dmode, bool xmode);

#endif
