/********************************************************************
  * Lab 1: main.cpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose: When given a color name, output the hexadecimal or decimal representation of that colo (-x for hexadecimal output, -d for decimal)
  *
  ********************************************************************/

#include "color.hpp"
#include <iostream>
#include <string>
#include <string.h>
//main class to check for -d or -x, if there are any arguments, and sanitizes the inputted data to all lowercase
  int main(int argc, char* argv[]){
    if(argc == 1){
      std::cout << "ERROR - no argument supplied";
	return 0;
    }

    bool dmode = false;
    bool xmode = false;

    std::string check = argv[1];
    //check to see if it is decimal mode or hexadecimal mode
    if(check == "-d" || check == "-D"){
	  dmode = true;
    }
    else if(check == "-x" || check == "-X"){
	xmode = true;
    }
    //makes all argument values lowercase
    char* temp;
    for(int i = 1; i < argc; ++i){
      temp = argv[i];
      for (int j = 0; j < strlen(temp); ++j){
	temp[j] = tolower(temp[j]);
      }
      argv[i] = temp;
    }
    //function to look up to see what values are associated with given input
    lookup(argc, argv, dmode, xmode);

  }

