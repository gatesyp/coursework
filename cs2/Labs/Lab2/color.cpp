/********************************************************************
  * Lab 1: color.cpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose: CPP file to translate between string argument and its hexadecimal/decimal representations. 
  *
  ********************************************************************/

#include "color.hpp"
#include <string>
#include <map>
#include <cctype>
#include <iomanip>
#include <string.h>
#include <iostream>

using namespace std;


int lookup(int argc, char* argv[], bool dmode, bool xmode){
  map <string, Color> colors;
  colors["white"] = Color (255, 255, 255);
  colors["silver"] = Color(192, 192, 192);
  colors["gray"] = Color (128, 128, 128);
  colors["black"] = Color(0, 0, 0);
  colors["red"] = Color (255, 0, 0);
  colors["maroon"] = Color(128, 0, 0);
  colors["yellow"] = Color(255, 255, 0);
  colors["olive"] = Color(128, 128, 0);
  colors["lime"] = Color(0, 255, 0);
  colors["green"] = Color(0, 128, 0);
  colors["aqua"] = Color(0, 255, 255);
  colors["teal"] = Color(0, 128, 128);
  colors["blue"] = Color(0, 0, 255);
  colors["navy"] = Color(0, 0, 50);
  colors["fuschia"] = Color(255, 0, 255);
  colors["purple"] = Color(128, 0, 128);

  if(dmode){
    for(int i = 2; i < argc; i++){
      Color c = colors[argv[i]];
      string blackCheck = argv[i];
        
      if (c.R == 0 && c.G == 0 && c.B == 0 && blackCheck != "black"){
  cout << "ERROR - not a valid argument";
  return 0;
      }
      cout << c.R << " " << c.G << " " << c.B << std::endl;
    }
  }else if(xmode){
    for(int i = 2; i < argc; i++)
      {
	string blackCheck = argv[i];
	Color c = colors[argv[i]];
	if (c.R == 0 && c.G == 0 && c.B == 0 && blackCheck != "black")
    {
      cout << "ERROR - not a valid argument";
      return 0;
      }
  cout << "#" << std::setw(2) << std::setfill('0') << std::hex << c.R;
  std::cout << std::setw(2) << std::setfill('0') << std::hex << c.G;
  std::cout << std::setw(2) << std::setfill('0') << std::hex << c.B << std::endl;
      }
  } else{
    for(int i = 1; i < argc; i++){
      string blackCheck = argv[i];
      Color c = colors[argv[i]];
      if (c.R == 0 && c.G == 0 && c.B == 0 && blackCheck != "black"){
  cout << "ERROR - not a valid argument";
  return 0;
      }
      std::cout << "#" << std::setw(2) << std::setfill('0') << std::hex << c.R;
      std::cout << std::setw(2) << std::setfill('0') << std::hex << c.G;
      std::cout << std::setw(2) << std::setfill('0') <<std::hex << c.B << std::endl;
    }
  }
}
