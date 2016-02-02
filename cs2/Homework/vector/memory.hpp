#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <new>
#include <memory>


// Helper functions

// Allocate memory for n objects of type T. The resulting
// memory is uninitialized. For example:
//
//    int* p = allocate<int>(20); 
//
// allocates space for 20 integers. Use construct() to
// create objects in uninitialized memory.
template<typename T>
inline T* allocate(int n)
{
  return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
}


// Deallocate memory allocated using the allocate() 
// function. Be sure to destroy the objects prior to
// deallocation.
template<typename T>
inline void deallocate(T* p)
{
  ::operator delete(p);
}


// Construct an object in at the address p. You can
// provide any arguments you want to the constructor.
// For example:
//
//    int* p = allocate<int>(1); 
//    construct(p, 5);            // Initialize p with 5.
template<typename T, typename... Args>
inline T* construct(T* p, Args&&... args)
{
  return new (p) T(std::forward<Args>(args)...);
}


// Destroy the the given object, but do not delete it.
template<typename T>
inline void destroy(T* p)
{
  p->~T();
}


// Destroy the elements in the range [first, last). This does
// not release the underlying memory.
template<typename T>
inline void initialized_destroy(T* first, T* last)
{
  while (first != last) {
    destroy(first);
    ++first;
  }
}

#endif
