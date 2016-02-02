/*******************************************************************
  * Lab 3: Make Your Own String Class main.cpp
  *
  * Author: Istvan Gates
  *         ig11@zips.uakron.edu
  *
  * Purpose: make my own string class with constructor and deconstructor
  *
  ********************************************************************/
#include "string.hpp"
#include <cassert>

int main(){
//initialize all of my variables, and perform the deep copy operation
  String s1;
  String s2 = "test";
  String s3 = s2;
  
  std::cout << s1 << '\n';
  std::cout << s2 << '\n';
  std::cout << s3 << '\n';
	//perform reassignment 
String a = "one";
String b = "two";
a = b;
b = "three";
std::cout << a << '\n';
std::cout << b << '\n';
//perform concatenation operation
String hello  = "hello ";
String world = "world";
String concat = hello + world;
std::cout << concat << '\n';
String c = "c";
String d = "d";
//assert tests
assert(c == c);
assert(c != d);
assert(c < d);
assert(c <= d);
assert(d > c);
assert(d >= c);

}

