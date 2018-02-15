//Amazing
/*
	This program will print out a different maze every time it is run
	and guarantees only one path through. You can choose the dimensions
	of the maze. i.e. the number of squares wide and long.
*/

/*
	PSEUDO
	1. Make the initial cell the current cell and mark it as visited
	2. While there are unvisited cells
		1. If the current cell has any neighbours which have not been visited
			1. Choose randomly one of the unvisited neighbours
			2. Push the current cell to the stack
			3. Remove the wall between the current cell and the chosen cell
			4. Make the chosen cell the current cell and mark it as visited
		2. Else if stack is not empty
			1. Pop a cell from the stack
			2. Make it the current cell
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#include "Cell.h"

using namespace std;

const int row = 2;
const int col = 2;

const int drawRow = (row * 2) + 1;
const int drawCol = (col * 2) + 1;

Cell* grid[row][col];
char printGrid[drawRow][drawCol];

Cell* maze(Cell* cell);
void displayBoard(int xDiff, int yDiff, Cell* currentCell);
void populateDrawGrid();

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//Populate array with cells
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			Cell* cell = new Cell(i, j);
			grid[i][j] = cell;
		}
	}

	//set starting cell as visited
	grid[0][0]->setVisited(true);
	grid[0][0]->setCurrent(true);

	populateDrawGrid();
	
	//Pause and clear screen then display
	displayBoard(0, 0, grid[0][0]);

	//recursive function
	//returns NULL when finished
	maze(grid[0][0]);

	return 0;
}

Cell* maze(Cell* cell)
{
	vector<Cell*> neighbors;

	//Define each neighboring cell
	Cell* top =		grid[cell->getYPos() - 1][cell->getXPos()	 ];
	Cell* right =	grid[cell->getYPos()	][cell->getXPos() + 1];
	Cell* bottom =	grid[cell->getYPos() + 1][cell->getXPos()	 ];
	Cell* left =	grid[cell->getYPos()	][cell->getXPos() - 1];

	//Check valid neighbor directions and add them to vector
	//Check whether cell is valid and whether it's been visited
	if (top && !top->getVisited() && cell->getYPos() != 0)
	{
		neighbors.push_back(top);
	}
	if (right && !right->getVisited() && cell->getXPos() != col - 1)
	{
		neighbors.push_back(right);
	}
	if (bottom && !bottom->getVisited() && cell->getYPos() != row - 1)
	{
		neighbors.push_back(bottom);
	}
	if (left && !left->getVisited() && cell->getXPos() != 0)
	{
		neighbors.push_back(left);
	}

	//Pick random neighbor and step forward
	if (neighbors.size() > 0)
	{
		random_shuffle(neighbors.begin(), neighbors.end());
		Cell* currentCell = neighbors[0];

		currentCell->setVisited(true);
		cell->setCurrent(false);
		currentCell->setCurrent(true);

		int xDiff = currentCell->getXDifference(cell);
		int yDiff = currentCell->getYDifference(cell);

		//Pause and clear screen then display
		displayBoard(xDiff, yDiff, currentCell);

		//Recursion
		maze(currentCell);
	}

	return NULL;
}

void displayBoard(int xDiff, int yDiff, Cell* currentCell)
{
	system("PAUSE");
	system("CLS");

	for (int i = 0; i < drawRow; ++i)
	{
		for (int j = 0; j < drawCol; ++j)
		{
			if (currentCell->getXPos() == j - 1 &&
				currentCell->getYPos() == i - 1 &&
				printGrid[i][j] == '#')
			{
				printGrid[i][j] = currentCell->Show();
				cout << printGrid[i][j];
			}
			else
			{
				cout << printGrid[i][j];
			}
		}
		cout << endl;
	}	
}

void populateDrawGrid()
{
	for (int i = 0; i < drawRow; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < drawCol; ++j)
			{
				if (j % 2 == 0)
				{
					printGrid[i][j] = '+';
				}
				else
				{
					printGrid[i][j] = '-';
				}
			}
		}

		if (i != 0 && i % 3 == 0 || i == 1)
		{
			for (int j = 0; j < drawCol; ++j)
			{
				if (j % 2 == 0)
				{
					printGrid[i][j] = '|';
				}
				else
				{
					printGrid[i][j] = '#';
				}
			}
		}
	}
}