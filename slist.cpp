/* Class Library File */
#include "slist.h"
#include <sstream>
#include <string>

namespace patch {
	template<typename T> std::string to_string(const T& n) {
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

// Constructor
LinkedList::LinkedList() {
	head = NULL;
}
// Destructor
LinkedList::~LinkedList() {
	Node *ptr = head;
	Node *temp;
	// Cycle through list and release all node data
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		delete temp; // release the memory pointed to by temp
	}
}
// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(Airport *a) {
	Node *n = new Node();
	n->locationID[0] = a->code[0];
	n->locationID[1] = a->code[1];
	n->locationID[2] = a->code[2];
	n->locationID[3] = a->code[3];
	n->locationID[4] = a->code[4];
	n->latitude = a->latitude;
	n->longitude = a->longitude;
	n->next = head;

	head = n;
}
// clear()					//Removes all elements from this list.
void LinkedList::clear() {
	Node *ptr = head;
	Node *temp;
	// Cycle through list and release all node data
	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool LinkedList::equals(LinkedList l) {
	Node *pointerOne = head;
	Node *pointerTwo = l.head;
	while (pointerOne->next != NULL) {
		if (
			( std::string(pointerOne->locationID).compare(std::string(pointerTwo->locationID)) ) && 
			( pointerOne->lat == pointerTwo->lat ) && 
			( pointerOne->lon == pointerTwo->lon )
		   ) 
		{
			pointerOne = pointerOne->next;
			pointerTwo = pointerTwo->next;
		} else {
			return false;
		}
	}

	if(ptr_two->next != NULL){
		return false; //if the input linked list is too long
	}
	return true;
}
Airport LinkedList::nodeToAirport(Node n) {
	Airport temp;
	temp.code[0] = n.locationID[0];
	temp.code[1] = n.locationID[1];
	temp.code[2] = n.locationID[2];
	temp.code[3] = n.locationID[3];
	temp.code[4] = n.locationID[4];
	temp.latitude = n.latitude;
	temp.longitude = n.longitude;
	return temp;
}
Airport LinkedList::nodeToAirport(Node* n) {
	return nodeToAirport()
}

//get(index)				//Returns the element at the specified index in this list.
Airport LinkedList::get(int i) {
	int length = size();
	int increment = length - 1 - i;
	int counter = 0;
	Node *ptr = head;
	while (ptr->next != NULL && counter != increment) {
		counter++;
		ptr = ptr->next;
	}
	if(counter == increment) {
		return nodeToAirport(*ptr);
	}
}
int LinkedList::size() {
	int counter = 0;
	Node *ptr = head;
	while (ptr->next != NULL) {
		counter++;
		ptr = ptr->next;
	}
	counter++;
	return counter;
}

Airport* nodeToAirportPtr(Node n){
	Airport* a = new Airport();
	a->code = n->locationID;
	a->longitude = n->longitude;
	a->latitude = n->latitude;
	return a;
}

Airport nodeToAirport(Node n){
	return &nodeToAirportPtr(n);
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void LinkedList::insert(int index, Airport value){
	Airport* ptr = getPointerAtId(index-1);
	Airport* temp = ptr->next;
	ptr->next = value;
	value->next = temp;
	delete temp;
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
void LinkedList::exchg(int index1, int index2){
	if(index1 = index2){
		return;
	}
	Airport* ptr1 = getPointerAtId(index1);
	Airport* ptr2 = getPointerAtId(index2);
	Airport* t = ptr1;
	ptr1 = ptr2;
	ptr2 = t;
	delete t;
}

// isEmpty()				//Returns true if this list contains no elements.
bool LinkedList::isEmpty(){
	if(head != NULL){
		return false;
	}
	return true;
}
// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

// remove(index)			//Removes the element at the specified index from this list.
void LinkedList::remove(int index){
	Airport* f = getPointerAtId(index-1);
	f->next = getPointerAtId(index+1);
}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void LinkedList::set(int index, int value){
	Airport* f = getPointerAtId(index);
	f->value = value;
}
// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
LinkedList LinkedList::subList(int start, int length){
	Airport* s = getPointerAtId(start);
	LinkedList l = new LinkedList();
	int total = 0;
	while(total < length){
		l.add(s);
		s = s->next;
		total++;
	}
	return l;
}

// toString()				//Converts the list to a printable string representation.
string LinkedList::toString() {
	string output;
	Node *ptr = head;
	while (ptr->next != NULL) {
		output += std::string(ptr->locationID) + " " + patch::to_string(ptr->lat) + " "
				+ patch::to_string(ptr->lon) + "\n";
		ptr = ptr->next;
	}
	output += std::string(ptr->locationID) + " " + patch::to_string(ptr->lat) + " "
					+ patch::to_string(ptr->lon) + "\n";

	return output;
}
Airport* getPointerAtId(int id){
	int counter = 0;
	ptr = head;
	while(counter < id+1){
		ptr = ptr->next;
		counter++;
	}
	delete counter;
	return ptr;
}