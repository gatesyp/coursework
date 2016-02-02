#include "vector.hpp"
#include "memory.hpp"
#include <climits>
#include <algorithm>
#include <iostream>
#include <stdexcept>


// Saves the result of the program (see main).
int exit_code;


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


// Sanity check for low-level memory helper functions.
void
test_memory()
{
  // Initialize and destroy a single object.
  int* p = allocate<int>(1);
  construct(p, 5);
  check(*p == 5);
  destroy(p);
  deallocate(p);  
  // Initialize and destroy a sequence of objects.
  int a[] { 1, 2, 3 };
  int* q = allocate<int>(3);
  std::uninitialized_copy(a, a + 3, q);
  initialized_destroy(q, q + 3);
  deallocate(q);
}


// Check that default initialization creates an empty
// vector. The capacity may be 0.
void
test_default_init()
{
  Vector v;
  check(v.is_empty());
  check(v.size() == 0);
}


// Check that list initialization creeates a vector whose
// elements are the same as the initializer list.
void
test_list_init()
{
  Vector v { 1, 2, 3 };
  check(!v.is_empty());
  check(v.size() == 3);
  check(v.capacity() >= 3);
  check(v[0] == 1);
  check(v[1] == 2);
  check(v[2] == 3);
}


// Check that a vector can be used with the range-based
// for loop. The vector must define begin() and end().
void
test_range_access()
{
  Vector v { 0, 1, 2 };
  int n = 0;
  for (int x : v)
    check(x == n++);
}


// Check that a copied vector contains the same elements
// as the original and that the orignal is unmodified.
// The capcity of the copied vector must the the same as
// its size.
void
test_copy_init()
{
  Vector v1 { 1, 2, 3 };
  Vector v2 = v1;
  check(v1[0] == 1);
  check(v1[1] == 2);
  check(v1[2] == 3);
  check(std::equal(v1.begin(), v1.end(), v2.begin()));
  check(v2.capacity() == v2.size());
}


// Check that a copy assigned vector contains the same
// elements as the eoriginal and that the original is
// unmodified.
// The capcity of the copied vector must the the same as
// its size.
void
test_copy_assign()
{
  Vector v1 { 1, 2, 3 };
  Vector v2;
  v2 = v1;
  check(v2[0] == 1);
  check(v2[1] == 2);
  check(v2[2] == 3);
  check(std::equal(v1.begin(), v1.end(), v2.begin()));
  check(v2.capacity() == v2.size());
}


// Check that self-assignment does not crash or leak.
void
test_self_assign()
{
  Vector v1 { 1, 2, 3 };
  v1 = v1;
}


// Check that reserving memory actually updates the
// capcity but not the size.
void
test_reserve()
{
  Vector v;
  v.reserve(1024);
  check(v.capacity() >= 1024);
  check(v.size() == 0);
}


// Test the insertion of elements at the end of the
// vector.
void
test_push_back()
{
//cout << "make v1" << endl;
  Vector v1;
//printf("made v1\n");
  for (int i = 0; i < 3; ++i){
    v1.push_back(i);
//printf("made %d", i);
}
  Vector v2 { 0, 1, 2 };
  check(std::equal(v1.begin(), v1.end(), v2.begin()));
}


// Test the removal of elements at the end of the
// vector.
void
test_pop_back()
{
  Vector v { 1, 2, 3 };
  while (!v.is_empty())
    v.pop_back();
  check(v.is_empty());
  check(v.capacity() >= 3);
}


// Test that removing clearing a vector releases all
// the necessary memory.
void
test_clear()
{
  Vector v { 1, 2, 3 };
  v.clear();
  check(v.is_empty());
  check(v.capacity() >= 3);
}


int main()
{
  test_memory();

test_default_init();
test_list_init();
test_range_access();
test_copy_init();
test_copy_assign();
test_self_assign();
test_reserve();
test_push_back();
test_pop_back();
test_clear();


  return exit_code;
}
