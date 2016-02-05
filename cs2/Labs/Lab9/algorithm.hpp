#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <iostream>
#include <vector>
#include <string>
using namespace std; 
template<typename T, typename input>
T find(T first,const T end, const input& val) {
	if(first == end){
		return first;
	} else if(*first == val) return first;
	else return find(++first, end, val);


}



template<typename T>
bool equals(T first1, T last1, T first2, T last2) {
	if(first1 != last1){
		if(*first1 != *first2){
			return false;
		} else{
			equals(++first1, last1, ++first2, last2);
		}
	}
	else return true;

}


template<typename T>
T min_element(T first, T end) {
	if(first == end - 1) return first;
	T min = min_element(++first, end);
return (*first < *min) ? first : min;

}

template<typename T>
T copies(T first, T last, T d_first) {
	if(first == (last -1)) {
		*d_first = *first;
		return d_first + 1; 
	} else {
		*d_first = *first;
		return copies(++first, last, ++d_first);
	}
}

#endif
