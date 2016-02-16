//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #4 (Adjusted for use in assignment 5)
// Question #1a
// Class Implementation
// Professor: Howard Cheng
// Program: LineEditor.cc
// Purpose: Takes the header file and defines all the elements of it
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include<string>
#include<cctype>
#include"List.h"
#include"LineEditor.h"

using namespace std;

//********************************************************************
// Default Constructor
// Post-Condition -- Sets the list to a cleared (empty) list and sets
//                   the cursor at one past the end
//********************************************************************
LineEditor::LineEditor()
{
	// Ensures cleared list
	//textList.clear();
	
	// Set the iterator to point to the very end of the line
	cursor = textList.end();
}

//********************************************************************
// Const function returns the contents of L. As a note, I was forced
// to use these functions as the << operator overload, even with the
// friend option, was giving me errors of accessing private data members
// from this class.
//********************************************************************
const List& LineEditor::getList() const
{
	return textList;
}

//********************************************************************
// Const function returns the current iterator. As a note, I was forced
// to use these functions as the << operator overload, even with the
// friend option, was giving me errors of accessing private data members
// from this class.
//********************************************************************
const List::Iterator& LineEditor::getIterator() const
{
	return cursor;
}
//********************************************************************
// Function moves the iterator by one position to the left
//********************************************************************
void LineEditor::left()
{
	// Ensures that the cursor is not already at the beginning
	if(cursor != textList.begin())
		--cursor;
}

//********************************************************************
// Function moves the iterator by one position to the right
//********************************************************************
void LineEditor::right()
{
	// Ensures the cursor is not already at the end
	if (cursor != textList.end())
		++cursor;
}

//********************************************************************
// Function takes the user given string s and inserts it into the list
// at the position of the iterator(cursor)
//********************************************************************
void LineEditor::insert(const string& s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		textList.insert(cursor,s[i]);
	}
}

//********************************************************************
// Function erases the character at the current iterator position
//********************************************************************
void LineEditor::erase()
{
	// Ensures that the cursor is currently not pointed at the end
	// where there currently is no character
	if (cursor != textList.end())
	{
		textList.erase(cursor);
		--cursor;
	}
}

//********************************************************************
// Function takes the current character found at the iterator(cursor)
// and changes it to c
//********************************************************************
void LineEditor::change(char c)
{
	// Checks to see if the cursor is currently at the end. If it is,
	// this instead calls the insert function.
	if (cursor == textList.end())
	{
		string convertedChar = "";
		
		// Insert the character into a string. In essence "converts" it
		convertedChar.push_back(c);
		
		// Use the insert function to insert character c at the end
		insert(convertedChar);
	}
	else
		*cursor = c;
}

//********************************************************************
// Function takes a given char function with one char parameter, and
// applies that function to every character in the list
//********************************************************************
void LineEditor::apply(char (*f)(char c))
{
	// Ensures we're not altering the position of the current iterator
	List::Iterator it = cursor;

	for (it = textList.begin(); it != textList.end(); ++it)
	{
		// Apply function f to each part of the list
		*it = f(*it);
	}
}

//********************************************************************
// Function takes a given int function with one int parameter, and
// applies that function to every character in the list. Note that this
// function was necessary in order to deal with the function toupper
// built into c++ as it is naturally a integer function, not a
// character function.
//********************************************************************
void LineEditor::apply(int (*f)(int c))
{
	List::Iterator it = cursor;

	for (it = textList.begin(); it != textList.end(); ++it)
	{
		*it = f(*it);
	}
}

//********************************************************************
// Function overloads the << operator to allow for printing of character
// list
//********************************************************************
ostream& operator<<(ostream& os, const LineEditor& le)
{	
	// Prints the entire list ending it with a '$' symbol
	for (List::Iterator iter = le.getList().begin(); 
		 iter != le.getList().end(); ++iter)
	{
		cout << *iter;
	}
	
	cout << "$" << endl;
	
	// On a new line, this prints the position of where the cursor is
	// currently at marked by the '^'
	for (List::Iterator iter = le.getList().begin(); 
		 iter != le.getIterator(); ++iter)
	{
		cout << " ";
	}
	
	cout << "^" << endl;
	
	return os;
}
