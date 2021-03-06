#ifndef DATE_HPP
#define DATE_HPP
#include "memory.hpp"
#include <iostream>
#include <new>
#include <memory>
#include <assert.h>
#include <initializer_list>
#include <string>
#include <vector>

using namespace std;
template<typename T>
struct Vector : std::vector<T>// : std::vector<int>
{ 
	using iterator = T*;
	using const_iterator = T const*;
	iterator begin(){
		return base;	
	}
	const_iterator begin() const {return base;}
	iterator end(){return last; }
	const_iterator end() const{ return last;}
	// initialize my member variables
	T *base, *last, *limit;
	// most of the code here is given in class, or from my notesi
	// find the size of vector
	int size() const{
		return (last - base);
	}
	// find the TOTAL size of vector, including allocated but uninitialized memory
	int capacity() {
		return (limit - base);
	}
	// check to see if vector has contents
	bool empty() {
		return ((last - base) == 0);
	}
	// another function to see if it is empty, because you use both notations: 
	// empty() and is_empty
	// in your test case codes, so I just built both of them. did not change your given code
	bool is_empty() {
		return empty();
	}
	// erase an element contained in vector
	void erase(T* p){
		T* k = p;
		if(p == last - 1) {
			pop_back();
			return;
		}	
		else{
			while(k != last){
				++k;
				*p = *k;
				++p;
			}
			k = NULL;
			destroy(--last);
			return;
		}
	}


	T* insert(T* p, T v){
		T* tmp1 = last - 1;
		T* tmp2 = last;
		if(last == limit){
			reserve(2 * capacity());
		}
		while(tmp1 != p){
			*tmp2 = *tmp1; 
			--tmp1;
			--tmp2;

		}
		*p = v;
		last = base + size();
		return p;
	}

	Vector()// default constructor, reserve an arbitrary amount of space, and initialize the base to be null ptr
		:base(nullptr), last(), limit()
	{}
	// the copy constructor, (learned the difference between copy and assignment instructions in lab 5), performs same functionality as the assignment operator but in a different case
	Vector(const Vector& v)
		:base(new T[v.size()]), last(base + v.size()), limit(last)
	{	
		for(int i = 0; i < size(); i++){
			// copy all values over
			*(base + i)  = *(v.base + i);
		}
	}
	// given code, toallow initialization thru list
	Vector(std::initializer_list<T> list)
		:base(nullptr) 
	{
		reserve(list.size());
		for (T n : list)
			push_back(n);
	}

	// a lot of this was in my notes from class 
	// reserves new values and and performs function when expanding a vector pass the limit of vector  
	void reserve(int n) {
		if(!base) {
			// if no base, then create one specified to given size, and set last and limit appropiately
			base = allocate<T>(n);
			last = base;
			limit = base + n;			
		}
		// if there is a base, allocate new memory, copy over all values using unit_copy
		// and destroy the old data structure
		else {
			T *p = allocate<T>(n);
			T *q = uninitialized_copy(base, last, p);
			for(T *i = base; i != last; ++i) 
				destroy(i);
			//deallocate the old base, and then reassign the member variables
			deallocate(base);
			base = p;
			last = q;
			limit = base + n;
		}
	}
	// add an element to the vector
	void push_back(T n) {
		// if there is no base, then reserve new memory (arbitrary amount)
		if(!base) {
			reserve(16);
		}
		// else if the limit has been reached, allocate new memory that is twice the current capacity, and add the element
		else if(last == limit) { 
			reserve (2*capacity());
		}

		construct(last++, n);
	}
	// destroy the very last element - free that memory
	void pop_back() {
		// check to see if vector empty
		assert(!(empty()));
		// destroy the last element, and decrement last 
		destroy(--last);
	}
	// delete the entire vector
	void clear() {
		while(!(last - base) == 0)
			pop_back();
	}

	// overload [], in order to make subscripts work
	T operator[](int n) const {
		return *(base + (sizeof(T) * n));
	}

	T &operator[](int n) {
		return *(base +  n);
	}
	// overload assignment operator, passing by reference
	void  operator =(const Vector &v) {
		// set base to be thesize of the passed vector, and set up the last and limit pointers as well

		base = (new T[(v.last - v.base)]);
		last = (base + (v.last - v.base));
		limit = last;
		// now all pointers are set and skeleton of new vector is set
		// begin copying all the values over
		for(int i = 0; i < size(); i++){
			// copy all values over
			*(base + i)  = *(v.base + i);

		}
	}
	// deconstructor

	~Vector() {

		//	clear();	
		//	deallocate(base);
	}
};

#endif
template<typename T>
bool operator== (const Vector<T>& lhs,const Vector<T>& rhs) {
	if(lhs.size() != rhs.size())
		return false;
	for(int i = 0; i < lhs.size(); i++) {
		if(*lhs[i] != *rhs[i]);
		return false;
		return true;
	}
}

template<typename T>
bool operator!= (const Vector<T> & lhs, const Vector<T> &rhs) {
	return (!(lhs == rhs));
}

template<typename T>
bool operator> (const Vector<T>& lhs, Vector<T>& rhs){
	return lexigraphical_compare(rhs.base, rhs.last, lhs.base, lhs.last);
}

template<typename T>
bool operator< (const Vector<T>& lhs, Vector<T>& rhs){
	return(lhs < rhs);    
}

template<typename T>
bool operator<= (const Vector<T>& lhs, Vector<T>& rhs){
	return !(rhs < lhs);
}
template<typename T>
bool operator>= (const Vector<T>& lhs, Vector<T>& rhs){
	return !(lhs < rhs);
}


