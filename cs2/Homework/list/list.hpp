// Istvan Gates
// Linked List class
#ifndef LIST_HPP
#define LIST_HPP

#include <list>
#include <cassert>
#include <iostream>
using namespace std;
// Node Struct, to hold values/linkings between nodes
template<typename T>
struct Node {
	Node<T>* next, *previous;
	T value;
};
// iterator class w/ overloaded operators, constructor takes a node pointer
template<typename T>
struct Iterator {
	Node<T>* i = nullptr;

	Iterator (Node<T>* x) : i(x) {}

	// dereferences an iterator by returning value held in node
	T& operator*() {
		return i->value;
	}
	// checks to see if there is a next node, then points to it
	Iterator operator ++(){
		// assert(i->next != nullptr);
		return (i=i->next); 
	}
	// checks to see if there is a previous node, then points to it
	Iterator operator --(){
		// assert(i->previous != nullptr);
		return (i=i->previous);
	}
};
// node copy assignment function
template<typename T>
Node<T>* copy (Node<T> * ptr) {
	// check to see if pointer exists, if not then exit function
	if(!ptr)
		return nullptr;
	// dynamically allocate memory for a new Node object, and copy all values and pointers to it
	Node<T> *tmp = new Node<T>;
	tmp->value = ptr->value;
	// recursive solution to copy each node, with a base case of if tmp->next is null
	tmp->next = copy(ptr->next);
	if(tmp->next != nullptr)
		tmp->next->previous = tmp;
	return tmp;
}
// function to convert from an iterator back to a node pointer
template<typename T>
Node<T>* iterateConvert(Iterator<T> iterator) {
	return iterator.i;
}
// List struct which holds logic for what a Doubly Linked list can do
template<typename T>
struct List {
	// head points to the very first node, and tail points to very last node
	Node<T>* head;
	Node<T>* tail;
	// size of the overall list
	int sizeOf = 0;
	// default constructor initializes an empty list where head and tail are null
	List()
		:head(nullptr), tail(nullptr)
	{}
	// copy constructor, takes a Linked List and loops over it to construct a Linked List
	List (List<T> &a){
		// set the head of list to match the head of argument 
		head = a.head;
		// set the size equal to size of argument
		sizeOf = a.size();
		//create temporary pointer to facilitate iteration, and to copy nodes
		Node<T> * temp = head;
		// loop over the argument linked list and copy the node linkings
		while(temp->next) temp = temp->next;
		// set tail to the final node, which will be temp
		tail = temp;
	}
	// unitialized list constructor, takes an unitialized list
	List (std::initializer_list<T> list)
		:head(nullptr), tail(){	
			// calls pushback on every value in the passed in unitialized list
			for(T n : list){
				push_back(n);
			}
		}
	// iterator for the beginning of linked list
	Iterator<T> begin(){
		Iterator<T> iterator(head);
		return iterator;
	}

	Iterator<T> begin() const{
		Iterator<T> iterator(head);
		return iterator;
	}
	// returns an iterator pointing to the last node of linked list
	Iterator<T> end(){
		Iterator<T> iterator(tail);
		return iterator;
	}

	Iterator<T> end() const{
		Iterator<T> iterator(tail);
		return iterator;
	}
	// returns the size of the Linked List
	int size() const{
		return sizeOf;
	}
	// returns true if there are no nodes in the Linked List
	bool is_empty(){
		return (size() == 0);
	}
	// erase function, takes an iterator and deletes that node
	void erase(Iterator<T> iterator) {
		assert(size() != 0);
		Node<T> * tmp = iterateConvert(iterator);
		
		// check case of when only one element in the linked list
		if(sizeOf == 1){
			head = nullptr;
			tail = nullptr;
		}
		// check case if node to be erased is tail 
		else if(!(tmp->next)) {
			Node<T> *l = tmp->previous;
			l->next = nullptr;
			tail = l;
		}
		// check case if node to be erased is head
		else if(!(tmp->previous)) {
			Node<T> *l = tmp->next;
			l->previous = nullptr;
			head = l;
		} 
		// for all other cases, resets the pointers around element to be erased so that nothing is pointing at the element anymore
		else {
			Node<T> *n = tmp->next;
			Node<T> *l = tmp->previous;
			l->next = n;
			n->previous = l;
		}
		// take care of dangling pointers and decrement the size of the linked list
		delete tmp;
		--sizeOf;
	}
	// function to insert an element, inserts it one spot behind what the iterator is pointing at
	// note: must use push_back fuction to insert elements at the very end of the Linked List
	Iterator<T> insert (Iterator<T> iterator, T value){
		// dynamically allocate a new node and set the value of it
		Node<T> *tmp = new Node<T>;
		tmp->value = value;
		// convert the iterator to a node pointer
		Node<T> *node = iterateConvert(iterator);
		Iterator<T> end(tail);
		// check case when the linked list is empty
		if(is_empty()) { 
			tmp->next = nullptr;
			tmp->previous = nullptr;
			tail = tmp;
		head = tmp;

		}
		// check case when it is to be inserted at head
		else if(!(node->previous)) {
			node->previous = tmp;
			tmp->previous = nullptr;
			tmp->next = node;
		head = tmp;
		}
		// handles all other cases
		else {
			// reset the pointers around the node so that they point at the new node
			Node<T>* l = node->previous;
			l->next = tmp;
			tmp->previous = l;
			tmp->next = node;
			node->previous = tmp;
		}

		++sizeOf;
		Iterator<T> r = tmp;
		return r;
	}
	// used when user is required to put an element at the end of the list
	void push_back(T n) {
		// dynamically allocate memory for a new node and set the value of it
		Node<T> *tmp = new Node<T>;
		tmp->value = n;
		// check the case when the list is empty, if true set head to tmp node, set next and previous to null
		if(is_empty()) {
			tmp->previous = nullptr;
			head = tmp;
		} else{ 
			// if list is not empty, set pointers of the current tail to point at the new node
			tmp->previous = tail;
			tmp->previous->next = tmp;
		}
		// update tail, and set the next pointer to null (because there is nothing after tail)
		tmp->next = nullptr;
		tail = tmp;
		// increment the size of the array
		++sizeOf;
	}
	// used to add a new element at the very front of the Linked List
	void push_front(T n) {
		// dynamically allocate space for the new node and set the value of the node
		Node<T> *tmp = new Node<T>;
		tmp->value = n;
		// check the case when the list is empty
		if(is_empty()) {
			tmp->previous = nullptr;
			tmp->next = nullptr;
			tail = tmp;
		} else{
			// otherwise set the previous pointer to null (because there is nothing before head) and set the next pointer to head
			tmp->previous = nullptr;
			tmp->next = head;
			tmp->next->previous = tmp;
		}
		// update head and increment size of Linked List
		head = tmp;
		++sizeOf;
	}
	// delete the very last node of the Linked List
	void pop_back() {
		assert(size() != 0);
		if(size() == 1){
			tail = nullptr;
			head = nullptr;
			delete tail; 
			delete head;
		} else{
			tail = tail -> previous;
			tail -> next =  nullptr;
			delete tail -> next;
		}
		--sizeOf;
	}
	 	// delete the very first node in the linked list
void pop_front() {
	// make sure the list is not empty
	assert(size()!=0);
	// make a temporary pointer which points to head
	if(size() == 1)	{
	head = nullptr; 
	delete head;

	}
	else { 
	Node<T>* tmp = head;
	// set head to point at the second node in the list
	head = tmp->next;
	// set the 'previous' pointer for the second node to null
	tmp->next->previous = nullptr;	
	// delete the old head and decrement the size of the list
	delete tmp;
	}
	--sizeOf;
}
// assignment operator
List& operator = (const List<T> &a) {
	// call the recursive function copy to copy all the nodes over
	head = copy(a.head);
	// update size of the list
	sizeOf = a.size();
	// create a temporary pointer, so that we may find tail 
	Node<T>* tmp = head;
	while(tmp->next) tmp = tmp->next;
	// update tail our list to be the tail of the argument list 
	tail = tmp;

	return *this;
}
// clear the entire list, called by the List Destructor as well
void clear() {
// call pop back
	while(sizeOf != 0){
	pop_back();
	}
}
 ~List(){
	clear();	
}
/*
	Node<T>* p = new Node<T>;
	p = head;
	while(p) {
		Node<T>* tmp = p->next;
		delete p;
		p = tmp;
		--sizeOf;
	}*/
};
// overloaded equality operators, compares two nodes to see if the nodes are the same node
template<typename T>
bool operator ==(Iterator<T> lhs, Iterator<T> rhs){
	return (lhs.i == rhs.i);
}
// opposite of the equality operator
template<typename T>
bool operator !=(Iterator<T> lhs, Iterator<T> rhs) {
	return !(lhs == rhs);
}
#endif
