#ifndef STRING_HPP
#define STRING_HPP
#include <string.h>
#include <iostream>
//create String class
class String{
	public:
//declare member variables and functions
		int len;      
		char* str;

		//default constructor for String
		String()                 
			:len(0), str(new char[1])
		{}

		//copy constructor for String. copies the length of existing char array, dynamically allocates memory for the new string   
		String(String const& s)      	
			:len(s.len), str(new char[len+1]) 
		{
			strcpy(str, s.str);
		}    

		//c-string constructor. copies length and contents, then dynamically allocates memory for new c string array
		String(char const* s)   
			:len(strlen(s)), str(new char[len +1])
		{
			strcpy(str, s);
		}    

		//destructor to free up dynamically allocated memory
		~ String(){         
			delete[] str;
		}

		//function to get the member varialbe

		char const* getString()const{
			return str;
		}
//perform copy operation
		String& operator=(char const* s){
			len = strlen(s);
			delete[] str;
			str = new char[len + 1];

			strcpy(str, s);
			return *this;
}
//perform copy operation
		String& operator=(String const& s){
			len = s.len;
			delete[] str;
			str = new char[len + 1];
			strcpy(str, s.str);
			return *this;
		}
};
//ovleroading the cin operator
inline std::ostream& operator<<(std::ostream& os, String const& s)
{
	return os << s.getString();
}
//overlading the + operator so that concatenation may be performed
inline String operator+(String const& lhs, String const& rhs) {
	String result;
	result.len = (lhs.len + rhs.len);
	result.str = new char[result.len + 1];
	strcpy(result.str, lhs.str);
	return result;
}
//overloading all of the operators
//starting with == operator, using strcmp
inline bool operator ==(String const& lhs, String const& rhs){
	int rc = strcmp(lhs.str, rhs.str);
	if(rc == 0)
		return true;
	else
		return false;
}
//perform != overloading, by just notting the == operatio and notting it
inline bool operator!=(String const& lhs, String const& rhs){
	return !(lhs == rhs);
}
//using strcmp to see if strings are greater than
inline   bool operator >(String const& lhs, String const& rhs){
	int rc = strcmp(lhs.str, rhs.str);
	if(rc == 1)
		return true;
	else
		return false;
}
//once again check to see if strings are equal or greater than
inline   bool operator >=(String const& lhs, String const& rhs){
	int rc = strcmp(lhs.str, rhs.str);
	if(rc == 0 || rc == 1)
		return true;
	else return false;
}

//check to see if they are less than, see if result of strcmp is less than 0
inline   bool operator <(String const& lhs, String const& rhs){
	int rc = strcmp(lhs.str, rhs.str);
	return !(lhs > rhs);
}
//check to see if result of strcmp is 0 or less than 0
inline   bool operator <=(String const& lhs, String const& rhs){
	int rc = strcmp(lhs.str, rhs.str);
	if(rc == 0 || rc == -1)
		return true;
	else
		return false;
}
//end the header guard :)
#endif
