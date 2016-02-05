#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "algorithm.cpp"

using namespace std;
void test_find()
{
	//Range of strings
	std::vector<std::string> str_1={"Hi", "this", "is", "a", "test", "for", "equal"};    //True Case
	std::string s= "Hi";
	auto StrIterator = find(str_1.begin(),str_1.end(),s);
	assert(StrIterator != str_1.end());
	assert(s == *StrIterator);
	//False Case
	s="None";
	StrIterator = find(str_1.begin(),str_1.end(),s);
	assert(StrIterator == str_1.end());

	//Range of ints
	std::vector<int> val_1 = {1,2,3,4,5,6,7,8,9,10};
	//True Case
	int val=5;
	auto IntIterator=find(val_1.begin(),val_1.end(),val);
	assert(IntIterator != val_1.end());
	assert(*IntIterator == val);

	//False case
	val=12;
	IntIterator=find(val_1.begin(),val_1.end(),val);
	assert(IntIterator == val_1.end());
}


void test_equals()
{
	//Test for range of strings
	std::vector<std::string> str_1={"Hi", "this", "is", "a", "test", "for", "equal"};
	std::vector<std::string> str_2={"Hi", "this", "is", "a", "test", "for", "equal"};
	std::vector<std::string> str_3={"Hi", "test", "for", "equal"};
	std::vector<std::string> str_4={"Hi", "this", "is", "a"};

	assert(equals(str_1.begin(),str_1.end(),str_2.begin(),str_2.end()));
	assert(!equals(str_3.begin(),str_3.end(),str_4.begin(),str_4.end()));

	//Test for range of integers
	std::vector<int> val_1 {1,2,3,4,5,6,7,8,9,10};
	std::vector<int> val_2 {1,2,3,4,5,6,7,8,9,10};
	std::vector<int> val_3 {1,2,3,4,5,6};
	std::vector<int> val_4 {5,6,7,8,9,10};
	assert(equals(val_1.begin(),val_1.end(),val_2.begin(),val_2.end()));
	assert(!equals(val_3.begin(),val_3.end(),val_4.begin(),val_4.end()));
}



void test_min_element()
{
	std::vector<int> val_1 = {12,2,3,4,5,1,6,7,8,9,10};
	auto IntIterator = min_element(val_1.begin(),val_1.end());
	assert(*IntIterator == 1);

	std::vector<std::string> str_1={"hi", "this", "is", "a", "test", "for", "equal"};
	auto StrIterator = min_element(str_1.begin(),str_1.end());
	assert(*StrIterator == "a");
}

void test_copies()
{
	//Test for range of integers
	std::vector<int> val_1 = {12,2,3,4,5,1,6,7,8,9,10};
	std::vector<int> val_2(11);
	auto it = copies(val_1.begin(),val_1.end(),val_2.begin());
	assert(*(val_1.begin())==*(val_2.begin()));
	assert(it == val_2.end());

	//Test for range of Strings
	std::vector<std::string> str_1={"Hi", "this", "is", "a", "test", "for", "equal"};
	std::vector<std::string> str_2(7);
	auto StrIterator = copies(str_1.begin(),str_1.end(),str_2.begin());
}

int main()
{	
	test_find();
 	test_equals();
	test_min_element();
 	test_copies();
	std::cout << "Success!" << std::endl;
	return 0;
}
