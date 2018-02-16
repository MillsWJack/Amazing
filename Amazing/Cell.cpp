#include "Cell.h"

#include <vector>
#include <algorithm>

using namespace std;

Cell::Cell(int y, int x, bool visible, bool current, bool visited):
	xPos(x),
	yPos(y),
	current(current),
	visited(visited)
{
}

Cell::~Cell()
{
}

char Cell::Show()
{
	if (!this->visited)
	{
		return '#';
	}
	else
	{
		return ' ';
	}
}

int Cell::getXDifference(Cell* previousCell) const
{
	if (previousCell->getXPos() < this->getXPos())
	{
		return -1;
	}
	else if(previousCell->getXPos() > this->getXPos())
	{
		return +1;
	}
	else
	{
		return 0;
	}
}

int Cell::getYDifference(Cell* previousCell) const
{
	if (previousCell->getYPos() < this->getYPos())
	{
		return -1;
	}
	else if (previousCell->getYPos() > this->getYPos())
	{
		return +1;
	}
	else
	{
		return 0;
	}
}