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

const int row = 6;
const int col = 10;

const int drawRow = (row * 2) + 1;
const int drawCol = (col * 2) + 1;

Cell* grid[row][col];
char printGrid[drawRow][drawCol];

Cell* maze(Cell* cell);
void displayBoard();

vector<Cell*> stack;

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
	stack.push_back(grid[0][0]);
	
	//Pause and clear screen then display
	displayBoard();

	//recursive function
	//returns NULL when finished
	maze(grid[0][0]);

	return 0;
}

Cell* maze(Cell* cell)
{
	vector<Cell*> neighbors;
	Cell* currentCell = NULL;

	//Define each neighboring cell
	Cell* top =		grid[cell->getYPos() - 1][cell->getXPos()	 ];
	Cell* right =	grid[cell->getYPos()	][cell->getXPos() + 1];
	Cell* bottom =	grid[cell->getYPos() + 1][cell->getXPos()	 ];
	Cell* left =	grid[cell->getYPos()	][cell->getXPos() - 1];

	//Check valid neighbor directions and add them to vector
	//Check whether cell is valid and whether it's been visited
	if (cell->getYPos() != 0)
	{
		if (top && !top->getVisited())
		{
			neighbors.push_back(top);
		}
	}
	if (cell->getXPos() != col - 1)
	{
		if (right && !right->getVisited())
		{
			neighbors.push_back(right);
		}
	}
	if (cell->getYPos() != row - 1)
	{
		if (bottom && !bottom->getVisited())
		{
			neighbors.push_back(bottom);
		}
	}
	if (cell->getXPos() != 0)
	{
		if (left && !left->getVisited())
		{
			neighbors.push_back(left);
		}
	}

	//Pick random neighbor and step forward
	if (neighbors.size() > 0)
	{
		random_shuffle(neighbors.begin(), neighbors.end());
		currentCell = neighbors[0];
		stack.push_back(currentCell);

		currentCell->setVisited(true);
		cell->setCurrent(false);
		currentCell->setCurrent(true);
		currentCell->setPreviousCell(cell);

		//Pause and clear screen then display
		displayBoard();
	}
	else if (stack.size() > 0)
	{
		currentCell = stack.back();
		stack.pop_back();
	}

	if (currentCell == NULL)
	{
		return NULL;
	}
	else
	{
		return maze(currentCell);
	}
}

void displayBoard()
 {
	system("PAUSE");
	system("CLS");

	int y = 0;
	int x = 0;

	for (int i = 0; i < drawRow; ++i)
	{
		for (int j = 0; j < drawCol; ++j)
		{
			//If first row or every other, print line
			if (i == 0 || i % 2 == 0)
			{
				//alternate between + and - to form a line
				if (j == 0 || j % 2 == 0)
				{
					printGrid[i][j] = '+';
					cout << printGrid[i][j];
				}
				else if (grid[y - 1][x])
				{
					if (grid[y][x]->getPreviousCell() == grid[y - 1][x]
						&& grid[y][x]->getPreviousCell() != NULL
						&& i != drawRow - 1)
					{
						printGrid[i][j] = ' ';
						cout << printGrid[i][j];
					}
					else if (grid[y - 1][x]->getPreviousCell() == grid[y][x]
						&& grid[y][x]->getPreviousCell() != NULL
						&& i != drawRow - 1)
					{
						printGrid[i][j] = ' ';
						cout << printGrid[i][j]; 
					}
					else
					{
						printGrid[i][j] = '-';
						cout << printGrid[i][j];
					}
					x++;
				}

				else
				{
					printGrid[i][j] = '-';
					cout << printGrid[i][j];
				}
			}
			//If row is odd and col is odd, add cell to array
			//and print - alternate with |
			if (j % 2 == 1 && i % 2 == 1)
			{
				printGrid[i][j] = grid[y][x]->Show();
				cout << printGrid[i][j];
				x++;
			}
			else if (i != 0 && (j % 2 == 0 && i % 2 == 1))
			{
				if (j == 0 || j == drawCol - 1)
				{
					printGrid[i][j] = '|';
					cout << printGrid[i][j];
				}
				else if (grid[y][x - 1])
				{
					if (grid[y][x]->getPreviousCell() == grid[y][x - 1] 
						&& grid[y][x]->getPreviousCell() != NULL)
					{
						printGrid[i][j] = ' ';
						cout << printGrid[i][j];
					}
					else if (grid[y][x - 1]->getPreviousCell() == grid[y][x]
						&& grid[y][x]->getPreviousCell() != NULL)
					{
						printGrid[i][j] = ' ';
						cout << printGrid[i][j];
					}
					else
					{
						printGrid[i][j] = '|';
						cout << printGrid[i][j];
					}
				}
			}
		}

		cout << endl;
		x = 0;
		if (i % 2 == 1 && i != 0 && i != drawRow - 2)
		{
			y++;
		}
	}
}