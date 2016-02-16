//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymbursk
// Assignment #5
// Question #1
// Class Implementation
// Professor: Howard Cheng
// Program: List.cc
// Purpose: Takes the header file and defines all the elements of it
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include"List.h"

using namespace std;

//********************************************************************
// Default Constructor
// Post-Condition -- Default list is empty with a dummy node that
//                   essentially, points to itself
//********************************************************************
List::List()
{
	dummyNode = new Element(nullptr, nullptr, 0);
	dummyNode->next = dummyNode->prev = dummyNode;
}

//********************************************************************
// Destructor
// Post-Condition -- Deletes every element of the list, ensuring that
//                   there are no dangling pointers or unallocated
//                   memory
//********************************************************************
List::~List()
{
	while(begin() != end())
	{
		List::Iterator deleteElement(dummyNode->next);
		erase(deleteElement);
	}
	
	List::Iterator deleteElement(dummyNode);
	erase(deleteElement);
}

//********************************************************************
// Function returns an iterator that points to the beginning of the list
// Note: If the list is empty, this will equal the end function iterator
//********************************************************************
List::Iterator List::begin() const
{
	List::Iterator beginIterator;
	beginIterator.ptr = this->dummyNode->next;
	return beginIterator;
}

//********************************************************************
// Function returns an iterator that points to one past the end of the
// list. Note: If the list is empty, this will equal the begin function
// iterator
//********************************************************************
List::Iterator List::end() const
{
	List::Iterator endIterator;
	endIterator.ptr = this->dummyNode;
	return endIterator;
}

//********************************************************************
// Insert character c at Iterator location it. Note that if the iterator
// points to one past the end, the character is appended to the end of
// the list. This also ensures that the link is not screwed up when
// being inserted
//********************************************************************
void List::insert (List::Iterator insertLocation, char c)
{
	// Creates a new element with the correct pointers and with
	// the data given by the user. Assigns the other pointers to the
	// correct place to ensure the linked list is not broken
	Element *newElement = new Element(insertLocation.ptr, 
									  insertLocation.ptr->prev, c);	
	insertLocation.ptr->prev->next = newElement;
	insertLocation.ptr->prev = newElement;
}

//********************************************************************
// Function erases the element that Iterator it is pointing at. It also
// ensures that the doubly linked circular list is not broken when the
// element is removed from the list
//********************************************************************
void List::erase (List::Iterator eraseLocation)
{
		// Assign each of the pointers to the correct location so that
		// when the element is removed, the linked list is not broken
		eraseLocation.ptr->prev->next = eraseLocation.ptr->next;
		eraseLocation.ptr->next->prev = eraseLocation.ptr->prev;
		delete eraseLocation.ptr;
}

//********************************************************************
// Iterator Private Class Implementation
//********************************************************************

//********************************************************************
// Default Constructor
// Post-Condition -- Default constructor that initializes the ptr in
//                   the iterator class to nullptr
//********************************************************************
List::Iterator::Iterator()
{
	ptr = nullptr;
}

//********************************************************************
// ++ Operator Overload
// Post-Condition -- This allows for use of the Iterator ++ operator.
//                   It moves the pointer of the Iterator class one
//                   to the right
//********************************************************************
const List::Iterator& List::Iterator::operator++()
{
	ptr = ptr->next;
	return *this;
}

//********************************************************************
// -- Operator Overload
// Post-Condition -- This allows for use of the Iterator -- operator.
//                   It moves the pointer of the Iterator class one
//                   to the left
//********************************************************************
const List::Iterator& List::Iterator::operator--()
{
	ptr = ptr->prev;
	return *this;
}

//********************************************************************
// * Operator Overload
// Post-Condition -- This allows for use of the * operator within the
//                   Iterator class as a dereferencing operator.
//                   Essentially takes the pointer and dereferences the
//                   data currently at that location. It should also be
//                   noted that this data can be assigned to a new value
//********************************************************************
char& List::Iterator::operator*()
{
	return ptr->data;
}

//********************************************************************
// * Operator Overload
// Post-Condition -- This is a const version of the above operator
//                   overload. This ensures that when the data is 
//                   dereferenced, it cannot be assigned to another
//                   value. Mostly for use of const objects
//********************************************************************
const char& List::Iterator::operator*() const
{
	return ptr->data;
}

//********************************************************************
// == Operator Overload
// Post-Condition -- This allows for use of comparison between two
//                   Iterators. This function overloads the ==
//                   operator so that we can check to see if two
//                   Iterators have the same address. Returns true if
//                   this is the case
//********************************************************************
bool List::Iterator::operator==(Iterator comparisonIterator) const
{
	return (this->ptr == comparisonIterator.ptr);
}

//********************************************************************
// != Operator Overload
// Post-Condition -- This allows for use of the comparison between two
//                   Iterators. This function overloads the !=
//                   operator so that we can check to see if two
//                   Iterators do not have the same address. Returns
//                   true if this is the case
//********************************************************************
bool List::Iterator::operator!=(Iterator comparisonIterator) const
{
	return !(this->ptr == comparisonIterator.ptr);
}

