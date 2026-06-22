#include<bits/stdc++.h>
using namespace std;

int answer = 0;

void solve(int i, int j, vector<vector<int>> &grid,
           vector<vector<int>> &visited, int n)
{
    // destination
    if (i == n - 1 && j == n - 1)
    {
        answer++;
        return;
    }

    // invalid
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;

    if (grid[i][j] == 1)   // blocked
        return;

    if (visited[i][j])
        return;

    visited[i][j] = 1;

    solve(i + 1, j, grid, visited, n); // down
    solve(i, j + 1, grid, visited, n); // right
    solve(i - 1, j, grid, visited, n); // up
    solve(i, j - 1, grid, visited, n); // left

    visited[i][j] = 0; // backtrack
}

int main()
{
    int n;
    // cin >> n;
    n=7;

    // vector<vector<int>> maze(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n, 0)); 

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> maze[i][j];

    vector<vector<int>> maze = {
    {0,0,1,0,0,1,0},
    {1,0,1,1,0,0,0},
    {0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0},
    {1,0,1,1,0,1,0},
    {1,0,0,0,0,1,0},
    {1,1,1,1,0,0,0}
};


    solve(0, 0, maze, visited, n);

    cout << answer;
}
