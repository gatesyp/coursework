
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>


// TODO: Replace this class with your vector implementation.
template<typename T>
struct Vector
{
  // TODO: You will need to add the following constructor to
  // make the program compile. Be sure to initialize your
  // member variables before calling reserve.
  Vector(int n)
  {
    reserve(n);
    // TODO: Consider using std::uninitialized_fill to make
    // this more efficient.
    while (n) {
      push_back(T());
      --n;
    }
  }
};


#endif
