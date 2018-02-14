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

Cell* maze(Cell* grid[row][col], int a, int b);

int main()
{

	Cell* grid[row][col];

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++i)
		{
			Cell* cell = new Cell(i, j);
			grid[i][j] = cell;
			if (maze(grid, i, j) == NULL)
			{
				grid[i][j]->Show();
			}
		}
	}

	return 0;
}

Cell* maze(Cell* grid[row][col], int a, int b)
{
	vector<Cell*> neighbors;

	Cell* top = grid[a - 1][b];
	Cell* right = grid[a][b + 1];
	Cell* bottom = grid[a + 1][b];
	Cell* left = grid[a][b - 1];

	if (a < 0 || b < 0 || a > col || b > row)
	{
		return NULL;
	}

	else if (top && !top->getVisited())
	{
		neighbors.push_back(top);
	}
	else if (right && !right->getVisited())
	{
		neighbors.push_back(right);
	}
	else if (bottom && !bottom->getVisited())
	{
		neighbors.push_back(bottom);
	}
	else if (left && !left->getVisited())
	{
		neighbors.push_back(left);
	}

	random_shuffle(neighbors.begin(), neighbors.end());
}