/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int checkpath(int *maze, int rows, int columns, int x, int y, int x2, int y2, int prev){
	if (x == x2 && y == y2){
		return 1;
	}
	if (x > rows || y > columns){
		return 0;
	}
	int right = x*columns + y + 1, down = (x + 1)*columns + y, left = (x)*columns + y - 1, up = (x - 1)*columns + y, current = x*columns + y;
	int arr[] = { right, down, left, up };
	if (maze[right] == 1 && y + 1 < columns){
		return checkpath(maze, rows, columns, x, y + 1, x2, y2, current);
	}
	else if (maze[down] == 1 && x + 1 < rows){
		return checkpath(maze, rows, columns, x + 1, y, x2, y2, current);
	}
	else if (maze[left] == 1 && prev != left){
		return checkpath(maze, rows, columns, x, y - 1, x2, y2, current);
	}
	else  if (maze[up] == 1 && prev != up){
		return checkpath(maze, rows, columns, x - 1, y, x2, y2, current);
	}
	else{
		return 0;
	}
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (maze[x2*columns + y2]){
		if (x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0 && x1 < rows && x2 < rows && y1 < columns && y2 < columns){
			return checkpath(maze, rows, columns, x1, y1, x2, y2, 0);
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
