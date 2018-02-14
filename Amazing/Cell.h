#pragma once

const int cols = 4;
const int rows = 4;

class Cell
{
public:
	Cell(int y, int x, bool visible = true, bool current = false, bool visited = false);
	~Cell();

	char Show();

	inline bool getCurrent() const { return current; }
	inline bool getVisited() const { return visited; }
	inline int getYPos() const { return yPos; }
	inline int getXPos() const { return xPos; }

	inline void setCurrent(bool setter) { current = setter; }
	inline void setVisited(bool setter) { visited = setter; }

private:

	bool current;
	bool visited;

	int yPos;
	int xPos;

};

