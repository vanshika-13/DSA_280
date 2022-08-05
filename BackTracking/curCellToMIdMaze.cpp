/*Given a square maze containing positive numbers, find all paths from a corner cell (any of the extreme four corners) to the middle cell. We can move exactly n steps from a cell in 4 directions i.e. North, East, West and South where n is value of the cell, 

We can move to mat[i+n][j], mat[i-n][j], mat[i][j+n], and mat[i][j-n] from a cell mat[i][j] where n is value of mat[i][j].

Example

Input:  9 x 9 maze
[ 3, 5, 4, 4, 7, 3, 4, 6, 3 ]
[ 6, 7, 5, 6, 6, 2, 6, 6, 2 ]
[ 3, 3, 4, 3, 2, 5, 4, 7, 2 ]
[ 6, 5, 5, 1, 2, 3, 6, 5, 6 ]
[ 3, 3, 4, 3, 0, 1, 4, 3, 4 ]
[ 3, 5, 4, 3, 2, 2, 3, 3, 5 ]
[ 3, 5, 4, 3, 2, 6, 4, 4, 3 ]
[ 3, 5, 1, 3, 7, 5, 3, 6, 4 ]
[ 6, 2, 4, 3, 4, 5, 4, 5, 1 ]

Output:
(0, 0) -> (0, 3) -> (0, 7) -> 
(6, 7) -> (6, 3) -> (3, 3) -> 
(3, 4) -> (5, 4) -> (5, 2) -> 
(1, 2) -> (1, 7) -> (7, 7) ->
(7, 1) -> (2, 1) -> (2, 4) -> 
(4, 4) -> MID*/

#include <bits/stdc++.h>
using namespace std;

void printPath(vector<vector<int>> &maze, int i, int j, string ans)
{

    // If we reach the center cell
    if (i == maze.size() / 2 && j == maze.size() / 2)
    {

        ans += "(";
        ans += to_string(i);
        ans += ", ";
        ans += to_string(j);
        ans += ") -> MID";
        cout << ans << endl;
        return;
    }

    if (maze[i][j] == 0)
    {
        return;
    }
    int k = maze[i][j];

    maze[i][j] = 0;
    ans += "(";
    ans += to_string(i);
    ans += ", ";
    ans += to_string(j);
    ans += ") -> ";

    if (j + k < maze.size())
    {
        printPath(maze, i, j + k, ans);
    }

    // down call
    if (i + k < maze.size())
    {
        printPath(maze, i + k, j, ans);
    }

    // left call
    if (j - k > 0)
    {
        printPath(maze, i, j - k, ans);
    }

    // up call
    if (i - k > 0)
    {
        printPath(maze, i - k, j, ans);
    }

    maze[i][j] = k;
}

int main()
{

    // Creating the maze
    vector<vector<int>> maze = {
        {3, 5, 4, 4, 7, 3, 4, 6, 3},
        {6, 7, 5, 6, 6, 2, 6, 6, 2},
        {3, 3, 4, 3, 2, 5, 4, 7, 2},
        {6, 5, 5, 1, 2, 3, 6, 5, 6},
        {3, 3, 4, 3, 0, 1, 4, 3, 4},
        {3, 5, 4, 3, 2, 2, 3, 3, 5},
        {3, 5, 4, 3, 2, 6, 4, 4, 3},
        {3, 5, 1, 3, 7, 5, 3, 6, 4},
        {6, 2, 4, 3, 4, 5, 4, 5, 1}};

    // Calling the printPath function
    printPath(maze, 0, 0, "");
}
