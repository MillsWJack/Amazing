#include "Cell.h"

Cell::Cell(int x, int y, bool visible, bool current, bool visited):
	xPos(x),
	yPos(y)
{
}

Cell::~Cell()
{
}

char Cell::Show()
{
	if (this->visible && !this->visited)
	{
		return '*';
	}
	if (this->visible && this->visited)
	{
		return '#';
	}

	return ' ';
}
