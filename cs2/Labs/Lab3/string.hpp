/* 
Lab 3: Make your own string class   string.hpp
Author: Istvan Gates
	ig11@zips.uakron.edu

Purpose: make my own string class with constructor and deconstructor
*/
#ifndef STRING_HPP
#define STRING_HPP
#include <string.h>

using namespace std;

//create the STring class
class String{
	int len;
	char* str;

	public:
//default constructor for String
	String()
	:len(0), str(nullptr)
	{}

//copy constructor for String. copies the length of existing char array, dynamicall allocates memory for the new string
	String(String const& s)
	:len(s.len), str(new char[len+1])
	{
		strcpy(str, s.str);
	}

//c-string constructor. copies length and contents, then dynamically allocates memory for new c string array

	String(char const* s)
	:len(strlen(s)), str(new char[len + 1])
	{
		strcpy(str, s);
	}

//deconstructor to free up dynamically allocated memory
	~ String(){
	delete[] str;
	}
};

#endif
