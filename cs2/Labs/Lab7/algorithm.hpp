#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <iostream>

using namespace std; 

template<typename input, typename T>

input find (input first, input last, const T& val) {
	while(first != last) {
		if(*first == val) return first;
		++first;
	}

	return last;
}

template<typename test>
bool equals(test first1, test last1, test first2, test last2) {
	int i = 0;
	int j = 0;
	while(first1!=last1) {
		if(*first1 != *first2){ 
			return false;
		}	
	++first1;
	++first2;
	}
	return true;
}

template<typename T>
const T& minimum(const T& first, const T& second) {
	if(first < second) 
		return first;
	else
		return second;
}

template<typename T>
T min_element(T first, T last) {
	T min = first;
	++first;
	while(first != last) {
		if(!(*min < *first))
			min = first;
	++first;
	}
	return min;
}

template<typename T>
T copies(T first, T last, T d_first) {
	while(first != last) {
		*d_first = *first;
		++first;
		++d_first;

	}

//	cout << "first : " << *(--first) << " d_first : " << *(--d_first) << "\n";
	return  (d_first);
}

template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first) {
        init = init + *first;
    }
    return init;
}

#endif
