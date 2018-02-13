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

#include "Cell.h"

using namespace std;

const int cols = 4;
const int rows = 4;

Cell* gridArray[rows][cols];

void draw(Cell* grid[][cols]);

int main()
{
	for (int x = 0; x < rows; ++x)
	{
		for (int y = 0; y < cols; ++y)
		{
			Cell* pCell = new Cell(x, y);
			gridArray[x][y] = pCell;
		}
	}

	gridArray[0][0]->setVisible(true);
	gridArray[0][0]->setCurrent(true);
	gridArray[0][0]->setVisited(true);

	draw(gridArray);

	return 0;
}


void draw(Cell* grid[][cols])
{
	for (int j = 0; j < rows; ++j)
	{
		for (int i = 0; i < cols; ++i)
		{
			cout << gridArray[j][i]->Show();
		}

		cout << endl;
	}
}