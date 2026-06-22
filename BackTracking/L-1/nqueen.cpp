#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> answer;
bool canMove(vector<vector<char> > & grid,int n,int r,int c){
    //check column
    for(int i=r-1;i>=0;i--){
     if(grid[i][c]=='Q')  return false;
    }
    //check up-left
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
          if(grid[i][j]=='Q')  return false;
    }
     //check up-right
    for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
          if(grid[i][j]=='Q')  return false;
    }
    return true;
}

void f(vector<vector<char> > & grid,int n,int r){
    if(r==n) {
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j];
        //     }
        //     cout<<'\n';
        // }
        vector<string> temp;
        for (int i = 0; i < n; i++) {
           string row;
           for (int j = 0; j < n; j++) {
           row.push_back(grid[i][j]);
        }
        temp.push_back(row);
       }
       answer.push_back(temp);
       for(int i=0;i<answer.size();i++){
         cout << "Solution " << i + 1 << ":\n";
            for(int j=0;j<answer[i].size();j++){
                cout<<answer[i][j]<<'\n';
            }
            cout<<'\n';
        }

    return;
    }
    for(int c=0;c<n;c++){
      if(canMove(grid,n,r,c)){
        grid[r][c]='Q';
        f(grid,n,r+1);
        grid[r][c]='.';
      }
   }
}

void solveNQueens(int n){
    vector<vector<char> > grid(n, vector<char>(n,'.'));
    f(grid,n,0);    
}

int main(){
    solveNQueens(4);

}
