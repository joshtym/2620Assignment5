//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #5
// Question #2
// Class Implementation
// Professor: Howard Cheng
// Program: Sudoku.cc
// Purpose: Using the SudokuGrid class, this program enables the user
//          to input any sudoku file, and solves it
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<fstream>
#include<iostream>
#include"SudokuGrid.h"

using namespace std;

//********************************************************************
// Function Prototypes
//********************************************************************
// Function to check if the sudoku has been filled or is already full
bool isFull (const SudokuGrid& sudokuPuzzle);

// Function that, using recursion, actually determines what value to
// put in each cell
bool solve(SudokuGrid& sudokuPuzzle, int row, int column, int& counter);

// Function to make sure that the number of columns never exceeds 9
void checkColumn(int& row, int& column);

int main()
{
	// Variable Declarations
	SudokuGrid sudokuPuzzle;
	string fileName;
	ifstream inFile;
	int counter = 1;
	
	// Get file name from user
	cout << "Please enter the input file name: ";
	cin >> fileName;
	
	// Open file
	inFile.open(fileName.c_str());
	inFile >> sudokuPuzzle;
	
	// Show the intial uncomplete sudoku
	cout << "The sudoku that you have entered into the system appears "
		 << "as such." << endl;
	cout << "0's in the grid represent blanks on the grid: " << endl;
	cout << endl;
	cout << sudokuPuzzle << endl;
	
	// Intial call to solve function. If function is solvable, the
	// completed sudoku is outputted. If not solvable, a message
	// is outputted that it is not solvable
	if (solve(sudokuPuzzle, 1, 1, counter))
	{
		cout << "The completed sudoku appears as such: ";
		cout << endl << endl;
		cout << sudokuPuzzle << endl;
		cout << "Solve was called " << counter << " times!" << endl;
	}
	else
		cout << "This puzzle is not solvable!" << endl;
	
	return 0;
}

//********************************************************************
// Function Definitions
//********************************************************************

// Function takes in the position of a cell, in row and column, and
// solves for that cell using recursive methods. It also keeps track of
// how many times this function is called
bool solve(SudokuGrid& sudokuPuzzle, int row, int column, int& counter)
{
	// Ensure you're not at an illegal column number, IE, 10. If you
	// are, the row is incremented and column is reset back to 1
	checkColumn(row, column);
	
	// If this sudoku is full, then we're done. Return true if full
	if (isFull(sudokuPuzzle))
		return true;
	
	// If the cell is already occuppied, don't perform any operations
	// on it and instead, move to the next cell	
	if (!(sudokuPuzzle.empty(row, column)))
	{	
		 if(solve(sudokuPuzzle, row, column + 1, counter))
			return true;
	}
	
	else
	{
		// Everytime a cell is solved for, this counter goes up
		counter++;
		
		// Check to see if any of the digits can fit in this cell
		for (int digit = 1; digit < 10; digit++)
		{
			// If digit is valid, then put it in the cell and move on
			// to the next cell
			if(sudokuPuzzle.isValid(row, column, digit))
			{
				sudokuPuzzle.put(row, column, digit);
				
				if(solve(sudokuPuzzle, row, column + 1, counter))
					return true;
			}
		}
		// Cell cleared as a mistake was made earlier and must be
		// corrected before we put in another number
		sudokuPuzzle.clear (row, column);
	}
	return false;
	
}

// Function takes the Sudoku grid and checks to see if it is full or not
bool isFull (const SudokuGrid& sudokuPuzzle)
{
	// If any cell in the sudoku is empty, then the grid is not full
	// and hence, returns false. This loop checks for any empty
	// cells
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if(sudokuPuzzle.empty(i, j))
			{
				return false;
			}
		}
	}
	
	return true;
}

// Function looks to see that a column, while being incremented, never
// surpasses the default limit, 9. Essentially, if this limit is passed
// the row is incremented and the column reset back to 1
void checkColumn(int& row, int& column)
{
	if (column == 10)
	{
		row++;
		column = 1;
	}
}
