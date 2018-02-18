# Amazing

## Recursive backtracking maze generator

A console maze generator written in C++ using a depth-first-search algorithm, this algorithm works by reviewing the available legal neighbors to the current cell, randomizes it's choice, then adding it's choice to the stack to enable the use of backtracking. The process is continued until there are no possible neighbors, the stack is then used to go back to a time where a cell had the choice of more than one neighbor, then it selects a new cell that is yet to be visited. This process continues recursively until there are no more available cells.

Further reading:

https://en.wikipedia.org/wiki/Maze_generation_algorithm#Depth-first_search
http://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking

![Alt Text](https://i.imgur.com/EVhisBC.png)
