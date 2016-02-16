//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #5
// Question #1
// Class Interface
// Professor: Howard Cheng
// Program: List.h
// Purpose: Header file defines the prototypes of everything used in
//          the List class
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************

#ifndef LIST_H
#define LIST_H

class List
{
	private:
		// Private Nested Class
		class Element
		{
			public:
				// Data to store within each element
				char data;
				
				// Pointer to the next element
				Element *next;
				
				// Pointer to the previous element
				Element *prev;
				
				// Template for each element
				Element(Element *m, Element *n, char d) : next{m}, 
				prev{n}, data{d} {}
		};
		
		// Dummy frontal node to use for the circular double linked list
		Element *dummyNode;
		
	public:
		// Constructors
		List();               // Default Constructor
		
		// Destructor
		~List();              // Destructor set to delete every element
							  // within the list
		
		// Public Nested Class					  
		class Iterator
		{
			public:
				// Constructor
				Iterator();   // Default Constructor
				
				// Operator Overloads
				const Iterator& operator++();
							  // ++ operator overload that moves the
							  // iterator pointer one to the right
							  
				const Iterator& operator--();
							  // -- operator overload that moves the
							  // iterator pointer one to the left
							  
				char& operator*();
							  // Dereference operator overload that
							  // the data at the pointer to be
							  // dereferenced and assigned to a new
							  // value
							  
				const char& operator*() const;
							  // Const version of the operator overload
							  // from above to deal with const objects
							  
				bool operator==(Iterator) const;
							  // == operator overload to compare
							  // addresses of two iterator pointers.
							  // Returns true if the two pointers have
							  // the same address
							  
				bool operator!=(Iterator) const;
							  // != operator overload to compare
							  // addresses of two iterator pointers.
							  // Returns true if the two pointers do not
							  // have the same address
				
			private:
				// Allows the List class access to the private elements
				friend class List;
				
				// Primary pointer with all iterators
				Element *ptr;
				
				// Private constructor that assigns the pointer to n
				Iterator(Element* n) {ptr = n;}
		};
		
		// Function to insert a character c at iterator location it
		void insert (Iterator it, char c);
		
		// Function to erase a character at the iterator location.
		// Ensures that the list is not broken when the element is
		// erased
		void erase (Iterator it);
		
		// Returns an iterator to the beginning of the list
		List::Iterator begin() const;
		
		// Returns an iterator to one past the end of the list
		List::Iterator end() const;
};
#endif
