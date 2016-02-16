//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #4
// Question #1b
// Professor: Howard Cheng
// Program: LineEditor.cc
// Purpose: Program that implements the class file written into a simple
//          text editor.
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include<string>
#include"LineEditor.h"
#include<cctype>

using namespace std;

int main()
{
	// Variable Declarations
	LineEditor text;
	string userString;
	char operation = 'a';
	char c;
	
	// Input desired player protocol
	cin >> operation;
	
	while (operation != 'Q')
	{
		switch (operation)
		{
			// Move the cursor to the left
			case 'L':
				text.left();
				break;
			// Move the cursor to the right
			case 'R':
				text.right();
				break;
			// Insert user given string at cursor location
			case 'I':
				cin >> userString;
				text.insert(userString);
				break;
			// Erase character at the cursor
			case 'D':
				text.erase();
				break;
			// Change character at the cursor to c
			case 'C':
				cin >> c;
				text.change(c);
				break;
			// Change all characters to uppercase
			case 'U':
				text.apply(toupper);
				break;
			// Change all characters to lowercase
			case 'l':
				text.apply(tolower);
				break;
			// Print out the text
			case 'P':
				cout << text;
				break;
			default:
				break;
		}
		
		cin >> operation;
	}
	
	cout << endl;
	
	return 0;
}
