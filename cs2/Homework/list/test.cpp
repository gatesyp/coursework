
#include "test.hpp"

#include <string>
#include <iostream>

// -------------------------------------------------------------------------- //
// Globals


// Actually defines the exit code variable. If you
// comment this out, you will get a linker error.
int exit_code;


// -------------------------------------------------------------------------- //
// Helper functions

template<typename T>
T& 
get(List<T>& l, int n)
{
  auto iter = l.begin();
  while (n) {
    ++iter;
    --n;
  }
  return *iter;
}


template<typename T>
T const& 
get(List<T> const& l, int n)
{
  auto iter = l.begin();
  while (n) {
    ++iter;
    --n;
  }
  return *iter;
}


template<typename I>
bool
is_equal(I first1, I last1, I first2)
{
  while (first1 != last1) {
    if (*first1 != *first2)
      return false;
    ++first1;
    ++first2;
  }
  return true;
}


// -------------------------------------------------------------------------- //
// Test_list_common

Test_list_common::Test_list_common()
{
  default_init();
}

// Check that default initialization creates an empty
// list. The capacity may be 0.
void
Test_list_common::default_init()
{
  List<int> v;
  check(v.is_empty());
  check(v.size() == 0);
}


// -------------------------------------------------------------------------- //
// Test_list_int


Test_list_int::Test_list_int()
{
  list_init();
  range_access();
  copy_init();
  copy_assign();
  self_assign();
  push_back();
  pop_back();
  insert();
  erase();
  clear();
}


// Check that list initialization creeates a list whose
// elements are the same as the initializer list.
void
Test_list_int::list_init()
{
  List<int> v { 1, 2, 3 };
  check(!v.is_empty());
  check(v.size() == 3);
  check(get(v, 0) == 1);
  check(get(v, 1) == 2);
  check(get(v, 2) == 3);
}


// Check that a list can be used with the range-based
// for loop. The list must define begin() and end().
void
Test_list_int::range_access()
{
  List<int> v { 0, 1, 2 };
  int n = 0;
  for (int x : v)
    check(x == n++);
}


// Check that a copied list contains the same elements
// as the original and that the orignal is unmodified.
// The capcity of the copied list must the the same as
// its size.
void
Test_list_int::copy_init()
{
  List<int> v1 { 1, 2, 3 };
  List<int> v2 = v1;
  check(get(v2, 0) == 1);
  check(get(v2, 1) == 2);
  check(get(v2, 2) == 3);
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Check that a copy assigned list contains the same
// elements as the eoriginal and that the original is
// unmodified.
// The capcity of the copied list must the the same as
// its size.
void
Test_list_int::copy_assign()
{
  List<int> v1 { 1, 2, 3 };
  List<int> v2;
  v2 = v1;
  check(get(v2, 0) == 1);
  check(get(v2, 1) == 2);
  check(get(v2, 2) == 3);
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Check that self-assignment does not crash or leak.
void
Test_list_int::self_assign()
{
  List<int> v1 { 1, 2, 3 };
  v1 = v1;
}


// Test the insertion of elements at the end of the
// list.
void
Test_list_int::push_back()
{
  List<int> v1;
  for (int i = 0; i < 3; ++i)
    v1.push_back(i);
  List<int> v2 { 0, 1, 2 };
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Test the removal of elements at the end of the
// list.
void
Test_list_int::pop_back()
{
  List<int> v { 1, 2, 3 };
  while (!v.is_empty()){
    v.pop_back();}
  check(v.is_empty());
}


// Test the insertion of elements at the end of the
// list.
void
Test_list_int::push_front()
{
  List<int> v1;
  for (int i = 0; i < 3; ++i)
    v1.push_front(i);
  List<int> v2 { 2, 1, 0 };
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Test the removal of elements at the end of the
// list.
void
Test_list_int::pop_front()
{
  List<int> v { 1, 2, 3 };
  while (!v.is_empty())
    v.pop_front();
  check(v.is_empty());
}


// Test the positional insert.
void
Test_list_int::insert()
{
  List<int> v1;  
  v1.insert(v1.begin(), 0);
  check(v1.size() == 1);
  check(get(v1, 0) == 0);

  List<int> v2;
  v2.insert(v2.end(), 0);
  check(v2.size() == 1);
  check(get(v2, 0) == 0);

  v2.insert(v2.begin(), 1);
  check(v2.size() == 2);
  check(get(v2, 0) == 1);
  check(get(v2, 1) == 0);

  v2.insert(v2.end(), 2);
  check(v2.size() == 3);
  check(get(v2, 0) == 1);
  check(get(v2, 2) == 0);
  check(get(v2, 1) == 2);

}


// Test positional erase.
void
Test_list_int::erase()
{
  List<int> v { 1, 2, 3 };
  v.erase(++v.begin());
  check(v.size() == 2);
  check(get(v, 0) == 1);
  check(get(v, 1) == 3);
  
  v.erase(v.begin());
  check(v.size() == 1);
  check(get(v, 0) == 3);
  
  v.erase(v.begin());
  check(v.size() == 0);
}


// Test that removing clearing a list releases all
// the necessary memory.
void
Test_list_int::clear()
{
  List<int> v { 1, 2, 3 };
  v.clear();
  check(v.is_empty());
}


// -------------------------------------------------------------------------- //
// Test_list_string


Test_list_string::Test_list_string()
{
  list_init();
  range_access();
  copy_init();
  copy_assign();
  self_assign();
  push_back();
  pop_back();
  push_front();
  pop_front();
  insert();
  erase();
  clear();
}


// Check that list initialization creeates a list whose
// elements are the same as the initializer list.
void
Test_list_string::list_init()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  check(!v.is_empty());
  check(v.size() == 3);
  check(get(v, 0) == std::string("a"));
  check(get(v, 1) == std::string("b"));
  check(get(v, 2) == std::string("c"));
}


// Check that a list can be used with the range-based
// for loop. The list must define begin() and end().
void
Test_list_string::range_access()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  
  // Do something with the string values...
  for (std::string const& x : v)
    check(x.size());
}


// Check that a copied list contains the same elements
// as the original and that the orignal is unmodified.
// The capcity of the copied list must the the same as
// its size.
void
Test_list_string::copy_init()
{
  List<std::string> v1 { std::string("a"), std::string("b"), std::string("c") };
  List<std::string> v2 = v1;
  check(get(v2, 0) == std::string("a"));
  check(get(v2, 1) == std::string("b"));
  check(get(v2, 2) == std::string("c"));
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Check that a copy assigned list contains the same
// elements as the eoriginal and that the original is
// unmodified.
// The capcity of the copied list must the the same as
// its size.
void
Test_list_string::copy_assign()
{
  List<std::string> v1 { std::string("a"), std::string("b"), std::string("c") };
  List<std::string> v2;
  v2 = v1;
  check(get(v2, 0) == std::string("a"));
  check(get(v2, 1) == std::string("b"));
  check(get(v2, 2) == std::string("c"));
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Check that self-assignment does not crash or leak.
void
Test_list_string::self_assign()
{
  List<std::string> v1 { std::string("a"), std::string("b"), std::string("c") };
  v1 = v1;
}


// Test the insertion of elements at the end of the
// list.
void
Test_list_string::push_back()
{
  List<std::string> v1;
  v1.push_back(std::string("a"));
  v1.push_back(std::string("b"));
  v1.push_back(std::string("c"));
  List<std::string> v2 { std::string("a"), std::string("b"), std::string("c") };
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Test the removal of elements at the end of the
// list.
void
Test_list_string::pop_back()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  while (!v.is_empty())
    v.pop_back();
  check(v.is_empty());
}



// Test the insertion of elements at the front of the
// list.
void
Test_list_string::push_front()
{
  List<std::string> v1;
  v1.push_front(std::string("a"));
  v1.push_front(std::string("b"));
  v1.push_front(std::string("c"));
  List<std::string> v2 { std::string("c"), std::string("b"), std::string("a") };
  check(is_equal(v1.begin(), v1.end(), v2.begin()));
}


// Test the removal of elements at the front of the
// list.
void
Test_list_string::pop_front()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  while (!v.is_empty())
    v.pop_front();
  check(v.is_empty());
}


// Test the positional insert.
void
Test_list_string::insert()
{
  List<std::string> v1;  
  v1.insert(v1.begin(), std::string("a"));
  check(v1.size() == 1);
  check(get(v1, 0) == std::string("a"));

  List<std::string> v2;
  v2.insert(v2.end(), std::string("a"));
  check(v2.size() == 1);
  check(get(v2, 0) == std::string("a"));

  v2.insert(v2.begin(), std::string("b"));
  check(v2.size() == 2);
  check(get(v2, 0) == std::string("b"));
  check(get(v2, 1) == std::string("a"));

  v2.insert(v2.end(), std::string("c"));
  check(v2.size() == 3);
  check(get(v2, 0) == std::string("b"));
  check(get(v2, 2) == std::string("a"));
  check(get(v2, 1) == std::string("c"));

}


// Test positional erase.
void
Test_list_string::erase()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  v.erase(++v.begin());
  check(v.size() == 2);
  check(get(v, 0) == std::string("a"));
  check(get(v, 1) == std::string("c"));
  
  v.erase(v.begin());
  check(v.size() == 1);
  check(get(v, 0) == std::string("c"));
  
  v.erase(v.begin());
  check(v.size() == 0);
}

// Test that removing clearing a list releases all
// the necessary memory.
void
Test_list_string::clear()
{
  List<std::string> v { std::string("a"), std::string("b"), std::string("c") };
  v.clear();
  check(v.is_empty());
}

