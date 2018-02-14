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

const int row = 14;
const int col = 51;

Cell* grid[row][col];
char printGrid[row][col];

Cell* maze(Cell* cell);

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//Populate array with cells
	for (int i = 0; i < row - 1; ++i)
	{
		for (int j = 0; j < col - 1; ++j)
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

	/*printing loops*/
	for (int i = 0; i < row - 1; ++i)
	{
		for (int j = 0; j < col - 1; ++j)
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

	//Define each neighboring cell
	Cell* top =		grid[cell->getYPos() - 1][cell->getXPos()	 ];
	Cell* right =	grid[cell->getYPos()	][cell->getXPos() + 1];
	Cell* bottom =	grid[cell->getYPos() + 1][cell->getXPos()	 ];
	Cell* left =	grid[cell->getYPos()	][cell->getXPos() - 1];

	//Check valid neighbor directions and add them to vector
	//Check whether cell is valid and whether it's been visited
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