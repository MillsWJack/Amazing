#pragma once
class Cell
{
public:
	Cell(int x, int y, bool visible = true, bool current = false, bool visited = false);
	~Cell();

	char Show();
	inline bool getVisible() const { return visible; }
	inline bool getCurrent() const { return current; }
	inline bool getVisited() const { return visited; }

	inline void setVisible(bool setter) { visible = setter; }
	inline void setCurrent(bool setter) { current = setter; }
	inline void setVisited(bool setter) { visited = setter; }

private:
	bool visible;
	bool current;
	bool visited;

	int yPos;
	int xPos;

};

