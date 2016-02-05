
#ifndef TABLE_HPP
#define TABLE_HPP

#include "vector.hpp"

#include <cassert>


// Represents a position in a table in terms
// of rows and columns.
struct Index
{
  int r;
  int c;
};


// Represents a two-dimensional array in row-major layout.
// Elements of the array are accessed using the function
// call operator:
//
//    Table<int> t(3, 4); // 3 rows, 4 columns
//    t(1, 2) = 1;        // sets row 1, column 2 to 0.
//
// The Index class can also be used to select elements
// from the table.
//
//    Index x {2, 1};
//    t(x) = 1;           // sets row 2, column 1 to 0.
template<typename T>
struct Table : Vector<T>
{
private:
  using Row_init = std::initializer_list<T>;
  using Table_init = std::initializer_list<Row_init>;
public:

  // See below.
  Table(int, int);
  Table(Index);
  Table(Table_init);

  // Returns the element at index n.
  using Vector<T>::operator[];

  // Returns the element at row r, column c.
  T const& operator()(int r, int c) const { return (*this)[offset(r, c)]; }
  T&       operator()(int r, int c)       { return (*this)[offset(r, c)]; }

  // Returns the element specified by the given index.
  T const& operator()(Index x) const { return (*this)(x.r, x.c); }
  T&       operator()(Index x)       { return (*this)(x.r, x.c); }

  // Returns the number of rows.
  int rows() const { return dim.r; }

  // Returns the number of columns.
  int cols() const { return dim.c; }

  // Returns an index representing the dimensions of
  // the table.
  Index dims() const { return dim; }

  // Returns the offset of row r, column c within the
  // underlying vector.
  int offset(int r, int c) const { return r * dim.c + c; }

  // Returns the offset of the given index.
  int offset(Index x) const { return offset(x.r, x.c); }

private:
  Index dim;
};


// Initialize a table with r rows and c columns.
template<typename T>
inline
Table<T>::Table(int r, int c)
  : Vector<T>(r * c), dim{r, c}
{ }


// Initialize a table with the dimensions indicated
// by the given idex.
template<typename T>
inline
Table<T>::Table(Index x)
  : Vector<T>(x.r * x.c), dim{x.r, x.c}
{ }


// Initialize a table from nested initializer lists.
// This allows the following construction:
//
//    Table<int> t {
//      {1, 2, 3},
//      {4, 5, 6}
//    };
//
// The number of rows (2) and number of columns (3) are 
// inferred from the initializer lists. All rows in the
// initializer list shall have the same length.
template<typename T>
inline
Table<T>::Table(Table_init t)
  : Vector<T>(t.size() * t.begin()->size())
  , dim{t.size(), t.begin()->size()}
{
  auto iter = this->begin();
  for (Row_init const& r : t) {
    assert(r.size() == t.begin()->size());
    for (T const& c : r)
      *iter++ = c;
  }
}


#endif
