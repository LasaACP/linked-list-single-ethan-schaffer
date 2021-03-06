/* Header file for single linked list class library */
#include <iostream>
#include <string>
using namespace std;

// Header head
#ifndef SLIST_H
#define SLIST_H

class Airport {
public:
	char code[5];
	double longitude;
	double latitude;
};

/**
 * Linked List class
 */
class LinkedList {
	//friend class Airport;
	struct Node {
		char locationID[5];
		double latitude;
		double longitude;
		Node *next;
	};

public:
	LinkedList(); // constructor
	~LinkedList(); // destructor

	// add(value)				//Adds a new value to the end of this list.
	void add(Airport *a);
	// clear()					//Removes all elements from this list.
	void clear();
	// equals(list)				//Returns true if the two lists contain the same elements in the same order.
	bool equals(LinkedList l);
	//get(index)				//Returns the element at the specified index in this list.
	Airport get(int i);
	// size()					//Returns the number of elements in this list.
	int size();
	// toString()				//Converts the list to a printable string representation.
	string toString();
	Airport* nodeToAirportPtr(Node n);
	Airport nodeToAirport(Node n);
//insert(index, value)		//Inserts the element into this list before the specified index.
	void insert(int index, int value);
//exchg(index1, index2)		//Switches the payload data of specified indexex.
	void exchg(int index1, int index2);
// isEmpty()				//Returns true if this list contains no elements.
	bool isEmpty();
// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

// remove(index)			//Removes the element at the specified index from this list.
	void remove(int index);
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
	void set(int index, int value);
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
	LinkedList subList(int start, int length);
private:
	Node *head; // this is the private member variable. It is just a pointer to the first Node
};


// Header end
#endif