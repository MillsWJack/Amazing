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