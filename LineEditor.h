//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #4 (Adjusted for use in Assignment 5)
// Question #1a
// Class Interface
// Professor: Howard Cheng
// Program: LineEditor.h
// Purpose: Header file defines the prototypes of everything used in
//          the LineEditor class
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************

#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#include<iostream>
#include<string>
#include"List.h"

using namespace std;

class LineEditor
{
	public:
		// Constructors
		LineEditor();                 // Default Constructor
		
		// Get Methods
		const List& getList() const;
									  // Returns the list
		
		const List::Iterator& getIterator() const;
									  // Returns the current iterator
									  // position
									  
		// Methods
		void left();                  // Moves the position of the
									  // cursor to the left by one
									  
		void right();				  // Moves the position of the
									  // cursor to the right by one
									  
		void insert(const string& s); // Inserts string s into the list
									  // at the current position of the
									  // cursor
									  
		void erase();				  // Erases the character at the
									  // current position of the cursor
									  
		void change(char c);		  // Changes the character at the
									  // current position of the cursor
									  // to c
									  
		void apply(char (*f)(char c));// Applies the function f to every
									  // every character in the list
									  
		void apply(int (*f)(int c));  // Applies the function f to every
									  // every character in the list
		
	// Friend Functions
	friend ostream& operator<<(ostream& os,const LineEditor& le);
									  // Overloads the << operator to
									  // allow outputing of the list
		
	private:
		List textList;
		List::Iterator cursor;
	
};
#endif
