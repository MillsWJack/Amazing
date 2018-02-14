//Amazing
/*
	This program will print out a different maze every time it is run
	and guarantees only one path through. You can choose the dimensions
	of the maze. i.e. the number of squares wide and long.
*/

/*
	PSEUDO
	Make the initial cell the current cell and mark it as visited
	While there are unvisited cells
		If the current cell has any neighbours which have not been visited
			Choose randomly one of the unvisited neighbours
			Push the current cell to the stack
			Remove the wall between the current cell and the chosen cell
			Make the chosen cell the current cell and mark it as visited
		Else if stack is not empty
			Pop a cell from the stack
			Make it the current cell
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#include "Cell.h"

using namespace std;

const int row = 4;
const int col = 4;

Cell* grid[row][col];
char printGrid[row][col];

Cell* maze(Cell* cell);

int main()
{
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
	
	//recursive function
	//returns NULL when finished
	maze(grid[0][0]);

	//printing loops
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << grid[i][j]->Show();
		}

		cout << endl;
	}

	return 0;
}

Cell* maze(Cell* cell)
{
	vector<Cell*> neighbors;

	Cell* top =		grid[cell->getYPos() - 1][cell->getXPos()	 ];
	Cell* right =	grid[cell->getYPos()	][cell->getXPos() + 1];
	Cell* bottom =	grid[cell->getYPos() + 1][cell->getXPos()	 ];
	Cell* left =	grid[cell->getYPos()	][cell->getXPos() - 1];

	//Check edgecases
	if (cell->getYPos() < 0 || cell->getXPos() < 0 ||
		cell->getYPos() > col || cell->getXPos() > row)
	{
		return NULL;
	}

	//Check valid neighbor directions and add them to vector
	if (top && !top->getVisited())
	{
		neighbors.push_back(top);
	}
	if (right && !right->getVisited())
	{
		neighbors.push_back(right);
	}
	if (bottom && !bottom->getVisited())
	{
		neighbors.push_back(bottom);
	}
	if (left && !left->getVisited())
	{
		neighbors.push_back(left);
	}

	//Pick random neighbor and step forward
	if (neighbors.size() > 0)
	{
		random_shuffle(neighbors.begin(), neighbors.end());
		Cell* currentCell = neighbors[0];
		currentCell->setVisited(true);
		maze(currentCell);
	}

	return NULL;
}