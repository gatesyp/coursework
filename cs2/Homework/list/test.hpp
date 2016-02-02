
#ifndef TEST_HPP
#define TEST_HPP

#include "list.hpp"

#include <iostream>


// Declares the variable that will contain the exit
// code for the program (see main).
//
// The extern keyword tells the compiler that the
// variable of this name and type is declared somewhere.
// See test.cpp for its definition.
//
// NOTE: It is generally considered poor programming 
// style to put global variables in header files.
extern int exit_code;


// Use this instead of assert to check for failures.
// This will diagnose the failed check and update the
// exit code (see main).
#define check(e)                                    \
  if (!(e)) {                                       \
    std::cerr << "error: "                          \
               << __func__ << ":"                   \
               << __LINE__ << ": "                  \
               << #e << " evaluated to false\n";    \
    exit_code = 1;                                  \
  }



// Non-dependent testing facilities.
struct Test_list_common
{
  Test_list_common();

  void default_init();
};


// Tests for integer lists
struct Test_list_int : Test_list_common
{
  Test_list_int();

  void list_init();
   void range_access();
   void copy_init();
   void copy_assign();
   void self_assign();
   void push_back();
   void pop_back();
   void push_front();
   void pop_front();
   void insert();
   void erase();
   void clear();
};


// Tests for strings lists
struct Test_list_string : Test_list_common
{
  Test_list_string();

  void list_init();
  void range_access();
  void copy_init();
  void copy_assign();
  void self_assign();
  void push_back();
  void pop_back();
  void push_front();
  void pop_front();
  void insert();
  void erase();
  void clear();
};



#endif

