#pragma once

class Cell
{
public:
	Cell(int y, int x, bool visible = true, bool current = false, bool visited = false);
	~Cell();

	char Show();

	inline bool getCurrent() const { return current; }
	inline bool getVisited() const { return visited; }
	inline Cell* getPreviousCell() const { return previousCell; }
	inline int getYPos() const { return yPos; }
	inline int getXPos() const { return xPos; }

	inline void setCurrent(bool setter) { current = setter; }
	inline void setVisited(bool setter) { visited = setter; }
	inline void setPreviousCell(Cell* cell) { previousCell = cell; }

	int getXDifference(Cell* previousCell) const;
	int getYDifference(Cell* previousCell) const;

private:

	Cell* previousCell;

	bool current;
	bool visited;

	int yPos;
	int xPos;
};

