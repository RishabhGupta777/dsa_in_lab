#include<bits/stdc++.h>
using namespace std;

bool canMove(int r,int c,int n,vector<vector<int>> &grid){
   if (r < 0 or c < 0 or r >= n or c >= n or grid[r][c] == 1 or grid[r][c] == 2)
        return false;
 
        return true;
    // return r>=0 and c>=0 and r<n and c<n and grid[r][c]==0; //according to sir
}

void f(vector<vector<int>> &grid,int &ans,int n,int r,int c){
if(r==n-1 && c==n-1) { //base case
    ans+=1;
    return;
}
grid[r][c]=2; //means visited  -->pruning step
if(canMove(r+1,c,n,grid)) f(grid,ans,n,r+1,c);//down
if(canMove(r-1,c,n,grid)) f(grid,ans,n,r-1,c); //up
if(canMove(r,c+1,n,grid)) f(grid,ans,n,r,c+1);//right
if(canMove(r,c-1,n,grid)) f(grid,ans,n,r,c-1); //left
grid[r][c]=0; //unvisited   -->backtraking step
}

int main()
{
    int n = 7;

    vector<vector<int>> grid = {
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0}
    };

    int ans=0;

    f(grid,ans,n,0,0);

    cout << ans;
}
